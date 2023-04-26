#pragma once
#include "Constants.h"

class Human : public Animal {
private:
		int abilityCooldown;
public:
	Human(int positionX, int positionY, World* world);
	void Action() override;
	void Reproduce() override;
	void Ability();
	int GetAbilityCooldown();
	void SetAbilityCooldown(int cooldown);
	~Human();
};
