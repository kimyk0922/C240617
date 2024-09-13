#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal();
	AGoal(int NewX, int NewY, char NewShape = 'G');
	virtual ~AGoal();
};

