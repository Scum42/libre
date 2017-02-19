#include "Game.h"

#include "Box2D/Box2D.h"
#include "SDL.h"
#include "SDL_image.h"

using namespace libre;

int libre::Game::Start()
{
	InternalInit();
	Initialize();

	MainLoop();

	Cleanup();
	InternalCleanup();

	return mExitCode;
}

void libre::Game::Quit(int exitCode)
{
	mExit = true;
	mExitCode = exitCode;
}

void libre::Game::Kill(int exitCode)
{
	exit(exitCode);
}

void libre::Game::MainLoop()
{
	while (!mExit)
	{
		Quit();
	}
}

void libre::Game::InternalInit()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG & IMG_INIT_JPG);
}

void libre::Game::InternalCleanup()
{
	SDL_Quit();
	IMG_Quit();
}
