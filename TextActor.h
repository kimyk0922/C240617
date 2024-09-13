#pragma once
#include "Actor.h"
#include "SDL_ttf.h"

#include <string>

class ATextActor : public AActor
{
public:
	ATextActor();
	virtual ~ATextActor();

	virtual void Render() override;

	std::string Text;

protected:
	TTF_Font* Font;
	int FontSize;
};

