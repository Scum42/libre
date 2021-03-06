#pragma once

#include <cstdlib>
#include <string>

#include "Window.h"

namespace libre
{
    class Scene;

    class Game
    {
    public:

        // Get the game internally
        static Game* GetInstance() { return spInstance; }
        static Window* GetWindow() { return spInstance->mpWindow; }
        static Renderer* GetRenderer() { return spInstance->mpWindow->mpRenderer; }
        static Scene* GetCurrentScene() { return spInstance->mpScene; }

        // Constructor
        Game();

        // Call this to start the main loop. Calls InternalInit, Init, then InternalCleanup and Cleanup after the loop.
        int Start();

        // Call this to quit the game. Default exit code is 0 (success).
        inline void Quit(int exitCode = 0) { mExit = true; mExitCode = exitCode; }

        // Call this to kill the game immediately - skips the rest of the current frame and Cleanup(). Use this only when absolutely necessary. Default exit code is 1 (failure).
        inline void Kill(int exitCode = 1) { exit(exitCode); }

        // Get the window.
        //inline Window* GetWindow() { return mpWindow; }

        // Set the scene. Destroys the old scene and creates the new one.
        template <typename T>
        inline void SetScene()
        {
            if (mpScene) delete mpScene;
            mpScene = new T();
            mpScene->Initialize();
            mpScene->internal_InitializeGameObjects();
        }

        // Set the framerate
        void SetFramerate(float fps);

    protected:

        // Called before MainLoop()
        virtual void Initialize() = 0;

        // Poll SDL events.
        void PollEvents();

        // Run every frame absolutely first. Can be overriden, but you must remember to call the base.
        virtual void PhysicsUpdate();

        // Run every frame before Update(). Can be overridden, but you must remember to call the base funtion inside your custom PreUpdate().
        virtual void PreUpdate();
        
        // Run every frame. Can be overridden, but you must remember to call the base funtion inside your custom Update().
        virtual void Update();

        // Run every frame after Update(). Can be overridden, but you must remember to call the base funtion inside your custom PostUpdate().
        virtual void PostUpdate();

        // Run every frame. Can be overridden, but you must remember to call the base funtion inside your custom Render().
        virtual void Render();

        // Called after MainLoop exits.
        virtual void Cleanup() {}

        // Create the window. The window is stored internally, and will be cleaned up automatically.
        void CreateWindow(std::string name, int width, int height, WindowCreationFlags flags);
        // Create the window. The window is stored internally, and will be cleaned up automatically.
        void CreateWindow(std::string name, WindowCreationFlags flags);

    private:

        // Static reference to myself
        static Game* spInstance;

        // Initialize SDL and other things.

        void internal_Initialize();
        // Cleanup SDL and other things.
        void internal_Cleanup();

        // Exit information
        bool mExit;
        int mExitCode;

        // FPS information
        float mFramesPerSecond;
        Uint64 mTicksPerFrame;
        Uint64 mPerformanceFrequency;

        // The window
        Window* mpWindow;

        // The current scene
        Scene* mpScene;
    };
}