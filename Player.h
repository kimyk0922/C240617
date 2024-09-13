#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape = 'P');
	virtual ~APlayer();

	virtual void Tick() override;
	virtual void Render() override;

	bool Predict(int PredictX, int PredictY);

	int SpirteIndexX;
	int SpirteIndexY;
	Uint64 ElapsedTime;

};

