#pragma once

#include <cstdlib>
#include <string>

#include "Window.h"

namespace libre
{
    class Game
    {
    public:

        // Get the game internally
        static Game* GetInstance() { return spInstance; }

        // Constructor
        Game();

        // Call this to start the main loop. Calls InternalInit, Init, then InternalCleanup and Cleanup after the loop.
        int Start();

        // Call this to quit the game. Default exit code is 0 (success).
        inline void Quit(int exitCode = 0) { mExit = true; mExitCode = exitCode; }

        // Call this to kill the game immediately - skips the rest of the current frame and Cleanup(). Use this only when absolutely necessary. Default exit code is 1 (failure).
        inline void Kill(int exitCode = 1) { exit(exitCode); }

        // Get the window.
        inline Window* GetWindow() { return mpWindow; }

        // Get DeltaTime
        inline float GetDeltaTime() { return mDeltaTime; }

        // Set the framerate
        void SetFramerate(float fps);

    protected:

        // Called before MainLoop()
        virtual void Initialize() = 0;

        // Poll SDL events.
        void PollEvents();

        // Run every frame before Update(). Can be overridden, but you must remember to call the base funtion inside your custom PreUpdate().
        virtual void PreUpdate();
        
        // Run every frame. Can be overridden, but you must remember to call the base funtion inside your custom Update().
        virtual void Update();

        // Run every frame after Update(). Can be overridden, but you must remember to call the base funtion inside your custom PostUpdate().
        virtual void PostUpdate();

        // Run every frame. Can be overridden, but you must remember to call the base funtion inside your custom Render().
        virtual void Render();

        // Called after MainLoop exits.
        virtual void Cleanup() = 0;

        // Create the window. The window is stored internally, and will be cleaned up automatically.
        void CreateWindow(std::string name, int width, int height, WindowCreationFlags flags);
        // Create the window. The window is stored internally, and will be cleaned up automatically.
        void CreateWindow(std::string name, WindowCreationFlags flags);

    private:

        // Static reference to myself
        static Game* spInstance;

        // Initialize SDL and other things.
        void InternalInitialize();

        // Cleanup SDL and other things.
        void InternalCleanup();

        // Exit information
        bool mExit;
        int mExitCode;

        // FPS information
        float mFramesPerSecond;
        Uint64 mTicksPerFrame;
        Uint64 mPerformanceFrequency;
        float mDeltaTime;

        // The window
        Window* mpWindow;
    };
}