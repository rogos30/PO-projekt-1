#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Antelope();
};


