#include "Wolf.h"

Wolf::Wolf(int positionX, int positionY, World* world) {
	this->strength = 9;
	this->initiative = 5;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'W';
}

void Wolf::Reproduce() {
	//SPAWNING A BABY ABOVE A PARENT
	if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
		Wolf* baby = new Wolf(GetPositionX(), GetPositionY() - 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY BELOW A PARENT
	else if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
		Wolf* baby = new Wolf(GetPositionX(), GetPositionY() + 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE LEFT OF A PARENT
	else if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
		Wolf* baby = new Wolf(GetPositionX() - 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE RIGHT OF A PARENT
	else if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
		Wolf* baby = new Wolf(GetPositionX() + 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
}

Wolf::~Wolf() {}