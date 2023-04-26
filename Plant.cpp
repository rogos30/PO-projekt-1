#include "Constants.h"

Plant::Plant() {}

void Plant::Action() {
	this->age++;
	int spread = rand() % PLANT_SPREAD_CHANCE;
	if (spread == 0) {
		Reproduce();
	}
}

void Plant::Collision(Organism* organism) {
	
}