#include "Sheep.h"

Sheep::Sheep(int positionX, int positionY, World* world) {
	this->strength = 4;
	this->initiative = 4;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'S';
}

void Sheep::Reproduce() {
	//SPAWNING A BABY ABOVE A PARENT
	if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
		Sheep* baby = new Sheep(GetPositionX(), GetPositionY() - 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY BELOW A PARENT
	else if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
		Sheep* baby = new Sheep(GetPositionX(), GetPositionY() + 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE LEFT OF A PARENT
	else if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
		Sheep* baby = new Sheep(GetPositionX() - 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE RIGHT OF A PARENT
	else if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
		Sheep* baby = new Sheep(GetPositionX() + 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
}

Sheep::~Sheep() {}