#pragma once
#include "Constants.h"

class Wolf : public Animal {
public:
	Wolf(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Wolf();
};

