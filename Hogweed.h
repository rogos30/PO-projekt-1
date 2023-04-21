#pragma once
#include "Plant.h"

class Hogweed : public Plant {
public:
	Hogweed(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Hogweed();
};
