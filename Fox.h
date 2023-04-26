#pragma once
#include "Constants.h"

class Fox : public Animal {
public:
	Fox(int positionX, int positionY, World* world);
	void Action() override;
	void Reproduce() override;
	~Fox();
};