#pragma once
#include "Constants.h"

class Turtle : public Animal {
public:
	Turtle(int positionX, int positionY, World* world);
	void Action() override;
	void Reproduce() override;
	bool AttackReflected(Organism* attacker) override;
	~Turtle();
};
