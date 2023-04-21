#include "Nightshade.h"

Nightshade::Nightshade(int positionX, int positionY, World* world) {
	this->strength = 0;
	this->initiative = 0;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'n';
}

void Nightshade::Reproduce() {
	int direction = rand() % 4;

	switch (direction) {
	case UP:
		if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
			Nightshade* baby = new Nightshade(GetPositionX(), GetPositionY() - 1, world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	case DOWN:
		if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
			Nightshade* baby = new Nightshade(GetPositionX(), GetPositionY() + 1, world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	case LEFT:
		if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
			Nightshade* baby = new Nightshade(GetPositionX() - 1, GetPositionY(), world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	case RIGHT:
		if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
			Nightshade* baby = new Nightshade(GetPositionX() + 1, GetPositionY(), world);
			world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
		}
	}
}

Nightshade::~Nightshade() {}