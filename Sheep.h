#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
	Sheep(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Sheep();
};
