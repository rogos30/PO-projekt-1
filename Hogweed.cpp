#include "Hogweed.h"
#include "Animal.h"

Hogweed::Hogweed(int positionX, int positionY, World* world) {
	this->strength = 10;
	this->initiative = 0;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'h';
}

bool Hogweed::ReturnKill() {
	return true;
}

void Hogweed::Action() {
	//KILLING ANIMALS AROUND IT
	if (GetPositionY() - 1 >= 0 && dynamic_cast<Animal*>(world->GetBoardAt(GetPositionX(), GetPositionY() - 1))) {
		world->Kill(world->GetBoardAt(GetPositionX(), GetPositionY() - 1));
	}
	if (GetPositionY() + 1 < this->world->GetSizeY() && dynamic_cast<Animal*>(world->GetBoardAt(GetPositionX(), GetPositionY() + 1))) {
		world->Kill(world->GetBoardAt(GetPositionX(), GetPositionY() + 1));
	}
	if (GetPositionX() - 1 >= 0 && dynamic_cast<Animal*>(world->GetBoardAt(GetPositionX() - 1, GetPositionY()))) {
		world->Kill(world->GetBoardAt(GetPositionX() - 1, GetPositionY()));
	}
	if (GetPositionX() + 1 < this->world->GetSizeX() && dynamic_cast<Animal*>(world->GetBoardAt(GetPositionX() + 1, GetPositionY()))) {
		world->Kill(world->GetBoardAt(GetPositionX() + 1, GetPositionY()));
	}

	int spread = rand() % PLANT_SPREAD_CHANCE;
	if (spread == 0) {
		Reproduce();
	}
}

void Hogweed::Reproduce() {
	int direction = rand() % 4;

	switch (direction) {
	case UP:
		if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
			Hogweed* baby = new Hogweed(GetPositionX(), GetPositionY() - 1, world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	case DOWN:
		if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
			Hogweed* baby = new Hogweed(GetPositionX(), GetPositionY() + 1, world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	case LEFT:
		if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
			Hogweed* baby = new Hogweed(GetPositionX() - 1, GetPositionY(), world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	case RIGHT:
		if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
			Hogweed* baby = new Hogweed(GetPositionX() + 1, GetPositionY(), world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	}
}

Hogweed::~Hogweed() {}