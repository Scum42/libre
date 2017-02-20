#ifndef LIBRE_GAME_H
#define LIBRE_GAME_H

namespace libre
{
    class Game
    {
    public:

        inline Game() : mExit(false), mExitCode(0) {}
        inline ~Game() {}

        // Call this to start the game. Calls Initialize(), then MainLoop(), then Cleanup(). Returns the exit code of the game.
        int Start();

        // Call this to quit the game. Default exit code is 0 (success).
        void Quit(int exitCode = 0);

        // Call this to kill the game immediately - skips the rest of the current frame and Cleanup(). Use this only when absolutely necessary. Default exit code is 1 (failure).
        void Kill(int exitCode = 1);

    protected:

        // Called before MainLoop()
        virtual void Initialize() = 0;

        // Runs until manually stopped.
        void MainLoop();

        // Called after MainLoop exits.
        virtual void Cleanup() = 0;

        // Create the window.


    private:

        // Initialize SDL and other things.
        void InternalInit();

        // Cleanup SDL and other things.
        void InternalCleanup();

        bool mExit;
        int mExitCode;
    };
}

#endif
