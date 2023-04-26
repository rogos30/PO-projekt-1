#pragma once
#include "Constants.h"

class Grass : public Plant {
public:
	Grass(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Grass();
};

