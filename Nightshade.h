#pragma once
#include "Plant.h"

class Nightshade : public Plant {
public:
	Nightshade(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Nightshade();
};