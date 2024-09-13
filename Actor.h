#pragma once
#include <string>
#include "SDL.h"

class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape = ' ', int NewLayer = 0);
	virtual ~AActor();

	int Layer;

	int X;
	int Y;

	char Shape;

	virtual void Tick();
	virtual void Render();

	void LoadTexture(std::string TextureFilename);

	bool IsCollision;

	int R;
	int G;
	int B;
	int SpriteSize;

	int ColorKeyR;
	int ColorKeyG;
	int ColorKeyB;

	std::string Filename;
	SDL_Surface* MySurface;
	SDL_Texture* MyTexture;
};

