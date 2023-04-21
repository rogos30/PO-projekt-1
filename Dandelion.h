#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Dandelion();
};


