#pragma once
#include "Plant.h"
#include "Constants.h"

class Dandelion : public Plant {
public:
	Dandelion(int positionX, int positionY, World* world);
	void Action() override;
	void Reproduce() override;
	~Dandelion();
};


