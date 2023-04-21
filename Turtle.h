#pragma once
#include "Animal.h"
#include "Constants.h"

class Turtle : public Animal {
public:
	Turtle(int positionX, int positionY, World* world);
	void Action() override;
	void Reproduce() override;
	~Turtle();
};
