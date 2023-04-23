#pragma once
#include "Plant.h"

class Hogweed : public Plant {
public:
	Hogweed(int positionX, int positionY, World* world);
	bool ReturnKill() override;
	void Action() override;
	void Reproduce() override;
	~Hogweed();
};
