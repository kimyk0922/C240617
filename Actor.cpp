#include "Actor.h"
#include "SDL.h"
#include "Engine.h"

#include <iostream>
#include <windows.h>

AActor::AActor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 0;
	IsCollision = false;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;

	ColorKeyR = 255;
	ColorKeyG = 255;
	ColorKeyB = 255;

}

AActor::AActor(int NewX, int NewY, char NewShape, int NewLayer)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = NewLayer;
	IsCollision = false;
	R = 0;
	G = 0;
	B = 0;
	SpriteSize = 60;

	ColorKeyR = 255;
	ColorKeyG = 255;
	ColorKeyB = 255;
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	//text 
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << Shape;

	//2D
	SDL_SetRenderDrawColor(GEngine->MyRenderer, R, G, B, 1);
	//SDL_RenderDrawPoint(GEngine->MyRenderer, X, Y);
	SDL_Rect MyRect;
	MyRect.x = X * SpriteSize;
	MyRect.y = Y * SpriteSize;
	MyRect.w = SpriteSize;
	MyRect.h = SpriteSize;
	if (MyTexture)
	{
		SDL_RenderCopy(GEngine->MyRenderer,
			MyTexture,
			nullptr,
			&MyRect);
	}
	else
	{
		SDL_RenderFillRect(GEngine->MyRenderer, &MyRect);
	}
}

void AActor::LoadTexture(std::string TextureFilename)
{
	//RAM Image
	MySurface = SDL_LoadBMP(TextureFilename.c_str());
	//RAM -> VRAM
	SDL_SetColorKey(MySurface, 1, SDL_MapRGB(MySurface->format,
		ColorKeyR, ColorKeyG, ColorKeyB));
	MyTexture = SDL_CreateTextureFromSurface(GEngine->MyRenderer, MySurface);
}
