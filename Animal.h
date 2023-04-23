#pragma once
#include "Organism.h"

class Animal : public Organism{
public:
	Animal();
	void Action() override;
	void Collision(Organism* organism) override;
};