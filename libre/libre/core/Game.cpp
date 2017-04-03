#include "Game.h"

#include <iostream>
#include <ctime>

#include "Box2D/Box2D.h"
#include "SDL.h"
#include "SDL_image.h"

#include "libre/input/Mouse.h"

using namespace libre;
using namespace std;

Game* libre::Game::spInstance = nullptr;

libre::Game::Game()
{
    mExit = false;
    mExitCode = 0;

    mpWindow = nullptr;

    mFramesPerSecond = 0.0f;
    mDeltaTime = 0.0f;
    mTicksPerFrame = 0;
    mPerformanceFrequency = SDL_GetPerformanceFrequency();

    spInstance = this;

    mpScene = nullptr;

    srand((unsigned int)time(NULL));
}

int libre::Game::Start()
{
    // Init
    InternalInitialize();
    Initialize();

    // Timing for frames
    Uint64 start, end;

    while (!mExit)
    {
        // Set start and end
        start = SDL_GetPerformanceCounter();
        end = start + mTicksPerFrame;

        PollEvents();

        PreUpdate();
        Update();
        PostUpdate();

        mpWindow->GetRenderer()->Clear();
        Render();
        mpWindow->GetRenderer()->Flip();

        // Wait until the frame should end
        while (SDL_GetPerformanceCounter() < end);

        // Set delta time for the next frame
        mDeltaTime = (float)(end - start) / mPerformanceFrequency;
    }

    // Cleanup
    Cleanup();
    InternalCleanup();

    // Return exit code
    return mExitCode;
}

void libre::Game::SetFramerate(float fps)
{
    mFramesPerSecond = fps;
    mTicksPerFrame = (Uint64)((1.0f / fps) * mPerformanceFrequency);
}

void libre::Game::PollEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        // TODO: Respond to events
        switch (e.type)
        {
            case SDL_QUIT:
            {
                Quit();
                break;
            }
            case SDL_MOUSEMOTION:
            {
                Mouse::mPos.x = e.motion.x;
                Mouse::mPos.y = e.motion.y;
                break;
            }
        }
    }
}

void libre::Game::PreUpdate()
{
    // TODO: PreUpdate
}

void libre::Game::Update()
{
    // TODO: Update
}

void libre::Game::PostUpdate()
{
    // TODO: PostUpdate
}

void libre::Game::Render()
{
    // TODO: Render
}

void libre::Game::CreateWindow(std::string name, int width, int height, WindowCreationFlags flags)
{
    if (mpWindow) delete mpWindow;
    mpWindow = new Window(name, width, height, flags);
}

void libre::Game::CreateWindow(std::string name, WindowCreationFlags flags)
{
    if (mpWindow) delete mpWindow;
    mpWindow = new Window(name, flags);
}

void libre::Game::InternalInitialize()
{
    // Init all SDL features
    SDL_Init(SDL_INIT_EVERYTHING);

    // Init IMG for support of PNG and JPG files.
    IMG_Init(IMG_INIT_PNG & IMG_INIT_JPG);
}

void libre::Game::InternalCleanup()
{
    // Delete the window.
    delete mpWindow;
    mpWindow = nullptr;

    // Quit IMG.
    IMG_Quit();

    // Quit SDL.
    SDL_Quit();

    // Reset member variables.
    mExitCode = 0;
    mExit = false;
}
