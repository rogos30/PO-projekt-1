#pragma once
#include "Constants.h"

class Plant : public Organism {

public:
	Plant();
	void Action();
	void Collision(Organism* organism) override;
};
