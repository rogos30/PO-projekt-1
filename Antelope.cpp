#include "Constants.h"

Antelope::Antelope(int positionX, int positionY, World* world) {
	this->strength = 4;
	this->initiative = 4;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'A';
}

void Antelope::Action() {
	this->age++;
	int direction = rand() % 4;
	switch (direction) {
	case UP:
		if (GetPositionY() - 2 >= 0) {
			if (world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
				if (world->GetBoardAt(GetPositionX(), GetPositionY() - 2) == nullptr) {
					world->Move(GetPositionX(), GetPositionY() - 2, this);
					SetPositionY(GetPositionY() - 2);
				}
				else {
					Collision(world->GetBoardAt(GetPositionX(), GetPositionY() - 2));
				}
			}
			else {
				Collision(world->GetBoardAt(GetPositionX(), GetPositionY() - 1));
			}
		}
		break;
	case DOWN:
		if (GetPositionY() + 2 < this->world->GetSizeY()) {
			if (world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
				if (world->GetBoardAt(GetPositionX(), GetPositionY() + 2) == nullptr) {
					world->Move(GetPositionX(), GetPositionY() + 2, this);
					SetPositionY(GetPositionY() + 2);
				}
				else {
					Collision(world->GetBoardAt(GetPositionX(), GetPositionY() + 2));
				}
			}
			else {
				Collision(world->GetBoardAt(GetPositionX(), GetPositionY() + 1));
			}
		}
		break;
	case LEFT:
		if (GetPositionX() - 2 >= 0) {
			if (world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
				if (world->GetBoardAt(GetPositionX() - 2, GetPositionY()) == nullptr) {
					world->Move(GetPositionX() - 2, GetPositionY(), this);
					SetPositionX(GetPositionX() - 2);
				}
				else {
					Collision(world->GetBoardAt(GetPositionX() - 2, GetPositionY()));
				}
			}
			else {
				Collision(world->GetBoardAt(GetPositionX() - 1, GetPositionY()));
			}
		}
		break;
	case RIGHT:
		if (GetPositionX() + 2 < this->world->GetSizeX()) {
			if (world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
				if (world->GetBoardAt(GetPositionX() + 2, GetPositionY()) == nullptr) {
					world->Move(GetPositionX() + 2, GetPositionY(), this);
					SetPositionX(GetPositionX() + 2);
				}
				else {
					Collision(world->GetBoardAt(GetPositionX() + 2, GetPositionY()));
				}
			}
			else {
				Collision(world->GetBoardAt(GetPositionX() + 1, GetPositionY()));
			}
		}
		break;
	}
}

bool Antelope::AttackAvoided() {
	int avoided = rand() %2;
	if (avoided) return true;
	else return false;
}

void Antelope::Reproduce() {
	//SPAWNING A BABY ABOVE A PARENT
	if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
		Antelope* baby = new Antelope(GetPositionX(), GetPositionY() - 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY BELOW A PARENT
	else if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
		Antelope* baby = new Antelope(GetPositionX(), GetPositionY() + 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE LEFT OF A PARENT
	else if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
		Antelope* baby = new Antelope(GetPositionX() - 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE RIGHT OF A PARENT
	else if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
		Antelope* baby = new Antelope(GetPositionX() + 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
}

Antelope::~Antelope() {}