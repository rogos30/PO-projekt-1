#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(int positionX, int positionY, World* world);
	void Reproduce() override;
	~Guarana();
};
