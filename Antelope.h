#pragma once
#include "Constants.h"

class Antelope : public Animal {
public:
	Antelope(int positionX, int positionY, World* world);
	void Action() override;
	bool AttackAvoided() override;
	void Reproduce() override;
	~Antelope();
};


