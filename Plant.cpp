#include <cstdlib>
#include <iostream>
#include "Plant.h"

Plant::Plant() {}

void Plant::Action() {
	int spread = rand() % PLANT_SPREAD_CHANCE;
	if (spread == 0) {
		Reproduce();
	}
}

void Plant::Collision(Organism* organism) {
	
}