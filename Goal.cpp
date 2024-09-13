#include "Goal.h"

AGoal::AGoal()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 3;
	IsCollision = false;

	R = 0;
	G = 0;
	B = 255;
}

AGoal::AGoal(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 3;
	IsCollision = false;

	R = 0;
	G = 0;
	B = 255;

	Filename = "data/goal.bmp";
	LoadTexture(Filename);
}

AGoal::~AGoal()
{
}
