#pragma once
#include "Organism.h"

class Animal : public Organism{
public:
	Animal();
	void Action();
	void Collision(Organism* organism) override;
};