#include <cstdlib>
#include <iostream>
#include "Animal.h"
#include "Constants.h"

Animal::Animal() {}

void Animal::Action() {
	int direction = rand() % 4;
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
		break;
	}
}

void Animal::Collision(Organism* organism) {
	if (organism->GetSymbol() == symbol) {
		Reproduce();
	}
	else {
		if (organism->GetStrength() <= strength) {
			std::cout << organism->GetSymbol() << " has been eaten by " << symbol << std::endl;
			world->Kill(organism);
			world->Move(GetPositionX(), GetPositionY(), this);
			SetPositionX(organism->GetPositionX());
			SetPositionY(organism->GetPositionY());
		}
		else {
			std::cout << symbol << " has been eaten by " << organism->GetSymbol() << std::endl;
			world->Kill(this);
		}
	}
}