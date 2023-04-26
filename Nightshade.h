#pragma once
#include "Constants.h"

class Nightshade : public Plant {
public:
	Nightshade(int positionX, int positionY, World* world);
	bool ReturnKill() override;
	void Reproduce() override;
	~Nightshade();
};