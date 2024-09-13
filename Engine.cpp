#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <conio.h>

#include "Engine.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"
#include "Monster.h"
#include "TextActor.h"

using namespace std;

int UEngine::KeyCode = 0;
UEngine* UEngine::Instance = nullptr;

UEngine::UEngine()
{
	DeltaSeconds = 0;
	LastTime = 0;
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "Init error" << endl;
		return;
	}

	MyWindow = SDL_CreateWindow("Simple GameEngine", 100, 100, 600, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE /*SDL_RENDERER_SOFTWARE*/);

	srand((unsigned int)(time(0)));

	IsRunning = true;

	TTF_Init();
	Mix_OpenAudio(48000, MIX_DEFAULT_CHANNELS, 2, 4096);
}

void UEngine::Term()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	TTF_Quit();

	Mix_CloseAudio();

	SDL_Quit();
}

void UEngine::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UEngine::Run()
{
	while (IsRunning)
	{
		Input();

		DeltaSeconds = SDL_GetTicks64() - LastTime;
		LastTime = SDL_GetTicks64();
		Tick();
		Render();
	}
}

void UEngine::LoadLevel(std::string MapFilename)
{
	char Map[256];

	ifstream InputFile;

	InputFile.open(MapFilename);

	int Y = 0;
	while (InputFile.getline(Map, 80))
	{
		for (int X = 0; X < strlen(Map); ++X)
		{
			if (Map[X] == 'P')
			{
				SpawnActor(new APlayer(X, Y));
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == '*')
			{
				SpawnActor(new AWall(X, Y));
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == ' ')
			{
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == 'M')
			{
				SpawnActor(new AMonster(X, Y));
				SpawnActor(new AFloor(X, Y));
			}
			else if (Map[X] == 'G')
			{
				SpawnActor(new AGoal(X, Y));
				SpawnActor(new AFloor(X, Y));
			}

		}
		Y++;
	}

	SpawnActor(new ATextActor());

	//Sort
	Sort();

	InputFile.close();
}

void UEngine::Sort()
{
	AActor* Temp;
	for (int i = 0; i < Actors.size(); ++i)
	{
		for (int j = i + 1; j < Actors.size(); ++j)
		{
			if (Actors[i]->Layer > Actors[j]->Layer)
			{
				Temp = Actors[i];
				Actors[i] = Actors[j];
				Actors[j] = Temp;
			}
		}
	}
}

void UEngine::Input()
{
	//KeyCode = _getch();

	SDL_PollEvent(&MyEvent);
}

void UEngine::Tick()
{
	switch (MyEvent.type)
	{
	case SDL_QUIT:
		IsRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		cout << "Mouse Button Down" << endl;
		break;
	case SDL_KEYDOWN:
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			IsRunning = false;
			break;
		}
	}

	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UEngine::Render()
{
	//ClearScreen
	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
	SDL_RenderClear(MyRenderer);

	for (auto Actor : Actors)
	{
		Actor->Render();
	}

	SDL_RenderPresent(MyRenderer);
}
