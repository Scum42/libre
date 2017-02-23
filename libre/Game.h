#ifndef LIBRE_GAME_H
#define LIBRE_GAME_H

namespace libre
{
    class Game
    {
    public:

        // Empty constructor -- with initializers.
        inline Game() :
            mExit(false),
            mExitCode(0)
        {}

        // Call this to start the game. Calls Initialize(), then MainLoop(), then Cleanup(). Returns the exit code of the game.
        int Start();

        // Call this to quit the game. Default exit code is 0 (success).
        inline void Quit(int exitCode = 0) { mExit = true; mExitCode = exitCode; }

        // Call this to kill the game immediately - skips the rest of the current frame and Cleanup(). Use this only when absolutely necessary. Default exit code is 1 (failure).
        void Kill(int exitCode = 1) { exit(exitCode); }

    protected:

        // Called before MainLoop()
        virtual void Initialize() = 0;

        // Run every frame before Update(). Can be overridden, but defaults to doing nothing.
        virtual void PreUpdate() {}
        
        // Run every frame. Can be overridden, but you must remember to call the base funtion inside your custom Update().
        virtual void Update();

        // Run every frame after Update(). Can be overridden, but defaults to doing nothing.
        virtual void PostUpdate() {}

        // Run every frame. Can be overridden, but you must remember to call the base funtion inside your custom Render().
        virtual void Render();

        // Called after MainLoop exits.
        virtual void Cleanup() = 0;

        // Create the window. The window is stored internally.
        //void CreateWindow(int width, int height);

    private:

        // Initialize SDL and other things.
        void InternalInit();

        // Runs until manually stopped.
        void MainLoop();

        // Cleanup SDL and other things.
        void InternalCleanup();

        // Exit information
        bool mExit;
        int mExitCode;
    };
}

#endif
