#include "Constants.h"

Turtle::Turtle(int positionX, int positionY, World* world) {
	this->strength = 2;
	this->initiative = 1;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'T';
}

void Turtle::Action() {
	this->age++;
	int direction = rand() % 16;
	switch (direction) {
	case UP:
		if (GetPositionY() - 1 >= 0) {
			if (world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
				world->Move(GetPositionX(), GetPositionY() - 1, this);
				SetPositionY(GetPositionY() - 1);
			}
			else {
				Collision(world->GetBoardAt(GetPositionX(), GetPositionY() - 1));
			}
		}
		break;
	case DOWN:
		if (GetPositionY() + 1 < this->world->GetSizeY()) {
			if (world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
				world->Move(GetPositionX(), GetPositionY() + 1, this);
				SetPositionY(GetPositionY() + 1);
			}
			else {
				Collision(world->GetBoardAt(GetPositionX(), GetPositionY() + 1));
			}
		}
		break;
	case LEFT:
		if (GetPositionX() - 1 >= 0) {
			if (world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
				world->Move(GetPositionX() - 1, GetPositionY(), this);
				SetPositionX(GetPositionX() - 1);
			}
			else {
				Collision(world->GetBoardAt(GetPositionX() - 1, GetPositionY()));
			}
		}
		break;
	case RIGHT:
		if (GetPositionX() + 1 < this->world->GetSizeX()) {
			if (world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
				world->Move(GetPositionX() + 1, GetPositionY(), this);
				SetPositionX(GetPositionX() + 1);
			}
			else {
				Collision(world->GetBoardAt(GetPositionX() + 1, GetPositionY()));
			}
		}
	default:
		cout << "T was too lazy to move" << endl;
		break;
	}
}

void Turtle::Reproduce() {
	//SPAWNING A BABY ABOVE A PARENT
	if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
		Turtle* baby = new Turtle(GetPositionX(), GetPositionY() - 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY BELOW A PARENT
	else if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
		Turtle* baby = new Turtle(GetPositionX(), GetPositionY() + 1, world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE LEFT OF A PARENT
	else if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
		Turtle* baby = new Turtle(GetPositionX() - 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
	//SPAWNING A BABY TO THE RIGHT OF A PARENT
	else if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
		Turtle* baby = new Turtle(GetPositionX() + 1, GetPositionY(), world);
		world->AddOrganism(baby, baby->GetPositionX(), baby->GetPositionY());
	}
}

bool Turtle::AttackReflected(Organism* attacker) {
	if (attacker->GetStrength() < 5) {
		return true;
	}
	else {
		return false;
	}
}

Turtle::~Turtle() {}