#include <iostream>
using namespace std;

#include "SDL.h"
#undef main

#include "Box2D/Box2D.h"

void waitAndExit(int exitCode)
{
	cin.get();
	exit(exitCode);
}

int main(int argc, char *argv[])
{
	SDL_Window *window = nullptr;
	SDL_Surface *screen = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cout << "Error initting SDL Video: " << SDL_GetError() << endl;
		waitAndExit(-1);
	}

	window = SDL_CreateWindow("Hello SDL!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		cout << "Window could not be created: " << SDL_GetError() << endl;
		waitAndExit(-1);
	}

	waitAndExit(0);
}