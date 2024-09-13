#pragma once
#include "SDL.h"
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, char NewShape = 'M');
	virtual ~AMonster();
	virtual void Tick() override;
	bool Predict(int PredictX, int PredictY);

	Uint64 ElapsedTime;
};

