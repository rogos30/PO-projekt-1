#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(int positionX, int positionY, World* world);
	bool StrengthBoost() override;
	void Reproduce() override;
	~Guarana();
};
