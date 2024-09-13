#include "Engine.h"

int SDL_main(int argc, char* argv[])
{
	GEngine->LoadLevel("data.map");
	GEngine->Run();

	delete GEngine;

	return 0;
}