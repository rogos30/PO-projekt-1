#include "Fox.h"

Fox::Fox(int positionX, int positionY, World* world) {
	this->strength = 3;
	this->initiative = 7;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'F';
}

void Fox::Reproduce() {
	//SPAWNING A BABY ABOVE A PARENT
	if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
		Fox* baby = new Fox(GetPositionX(), GetPositionY() - 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY BELOW A PARENT
	else if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
		Fox* baby = new Fox(GetPositionX(), GetPositionY() + 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE LEFT OF A PARENT
	else if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
		Fox* baby = new Fox(GetPositionX() - 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE RIGHT OF A PARENT
	else if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
		Fox* baby = new Fox(GetPositionX() + 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
}

void Fox::Action() {
	int direction = rand() % 4;
	switch (direction) {
	case UP:
		if (GetPositionY() - 1 >= 0) {
			if (world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
				world->Move(GetPositionX(), GetPositionY() - 1, this);
				SetPositionY(GetPositionY() - 1);
			}
			else if (world->GetBoardAt(GetPositionX(), GetPositionY() - 1)->GetStrength() <= this->GetStrength()) {
				Collision(world->GetBoardAt(GetPositionX(), GetPositionY() - 1));
			}
		}
	case DOWN:
		if (GetPositionY() + 1 < this->world->GetSizeY()) {
			if (world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
				world->Move(GetPositionX(), GetPositionY() + 1, this);
				SetPositionY(GetPositionY() + 1);
			}
			else if (world->GetBoardAt(GetPositionX(), GetPositionY() + 1)->GetStrength() <= this->GetStrength()) {
				Collision(world->GetBoardAt(GetPositionX(), GetPositionY() + 1));
			}
		}
	case LEFT:
		if (GetPositionX() - 1 >= 0) {
			if (world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
				world->Move(GetPositionX() - 1, GetPositionY(), this);
				SetPositionX(GetPositionX() - 1);
			}
			else if (world->GetBoardAt(GetPositionX() - 1, GetPositionY())->GetStrength() <= this->GetStrength()) {
				Collision(world->GetBoardAt(GetPositionX() - 1, GetPositionY()));
			}
		}
	case RIGHT:
		if (GetPositionX() + 1 < this->world->GetSizeX()) {
			if (world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
				world->Move(GetPositionX() + 1, GetPositionY(), this);
				SetPositionX(GetPositionX() + 1);
			}
			else if (world->GetBoardAt(GetPositionX() + 1, GetPositionY())->GetStrength() <= this->GetStrength()) {
				Collision(world->GetBoardAt(GetPositionX() + 1, GetPositionY()));
			}
		}
	}
}

Fox::~Fox() {}