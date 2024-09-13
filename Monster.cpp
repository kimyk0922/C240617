#include "Monster.h"
#include "Engine.h"

AMonster::AMonster()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Layer = 5;
	IsCollision = false;

	R = 255;
	G = 0;
	B = 255;
	ElapsedTime = 0;
}

AMonster::AMonster(int NewX, int NewY, char NewShape)
{
	X = NewX;
	Y = NewY;
	Shape = NewShape;
	Layer = 5;
	IsCollision = false;

	R = 255;
	G = 0;
	B = 255;

	ElapsedTime = 0;
	Filename = "data/monster.bmp";
	LoadTexture(Filename);
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	ElapsedTime += GEngine->GetWorldDeltaSeconds();

	//SDL_Log("%d %d", ElapsedTime, GEngine->DeltaSeconds);

	if (ElapsedTime < 500)
	{
		return;
	}

	ElapsedTime = 0;

	int Direction = rand() % 4;

	switch (Direction)
	{
	case 0:
		if (Predict(X, Y - 1))
		{
			Y--;
		}
		break;
	case 1:
		if (Predict(X, Y + 1))
		{
			Y++;
		}
		break;
	case 2:
		if (Predict(X - 1, Y))
		{
			X--;
		}
		break;
	case 3:
		if (Predict(X + 1, Y))
		{
			X++;
		}
		break;
	}
}

bool AMonster::Predict(int PredictX, int PredictY)
{
	for (auto OtherActor : GEngine->Actors)
	{
		if (this == OtherActor)
		{
			continue;
		}

		if (OtherActor->IsCollision == false)
		{
			continue;
		}

		if (PredictX == OtherActor->X && PredictY == OtherActor->Y)
		{
			return false;
		}
	}


	return true;
}
