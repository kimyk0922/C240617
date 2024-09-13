#include "Floor.h"

AFloor::AFloor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 1;
	IsCollision = false;

	R = 100;
	G = 100;
	B = 100;
}

AFloor::AFloor(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 1;
	IsCollision = false;

	R = 100;
	G = 100;
	B = 100;

	Filename = "data/floor.bmp";
	LoadTexture(Filename);
}

AFloor::~AFloor()
{
}
