#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
	Wolf(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Wolf();
};

