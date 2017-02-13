#include "Game.h"

using namespace libre;

int libre::Game::Start()
{
	Initialize();
	MainLoop();
	Cleanup();
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
