#ifndef GAME_H
#define GAME_H

#include "Box2D/Box2D.h"
#include "SDL.h"

// Necessary for SDL to work with C++
#undef main

namespace libre
{
	class Game
	{
	public:

		Game() : mExit(false), mExitCode(0) {}
		~Game() {}

		// Call this to start the game. Calls Initialize(), then MainLoop(), then Cleanup(). Returns the exit code of the game.
		int Start();

		// Call this to quit the game. Default exit code is 0.
		void Quit(int exitCode = 0);

		// Call this to kill the game immediately - skips the rest of the current frame and Cleanup(). Use this only when absolutely necessary. Default exit code is 1.
		void Kill(int exitCode = 1);

	protected:

		// Called before MainLoop()
		virtual void Initialize() = 0;

		// Runs until manually stopped.
		void MainLoop();

		// Called after MainLoop exits.
		virtual void Cleanup() = 0;

	private:

		bool mExit;
		int mExitCode;
	};
}

#endif