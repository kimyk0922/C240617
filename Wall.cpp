#include "Wall.h"

AWall::AWall()
{
	X = 1;
	Y = 1;
	Shape = ' ';
	Layer = 2;
	IsCollision = true;

	R = 255;
	G = 0;
	B = 0;
}

AWall::AWall(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 2; 
	IsCollision = true;

	R = 255;
	G = 0;
	B = 0;
	Filename = "data/wall.bmp";
	LoadTexture(Filename);
}

AWall::~AWall()
{
}