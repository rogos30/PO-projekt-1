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
	if (organism->GetSymbol() == this->symbol) {
		Reproduce();
	}
	else if (organism->GetStrength() <= this->strength) {
		if (organism->AttackReflected(this) == false && organism->AttackAvoided() == false) {
			int enemyX = organism->GetPositionX();
			int enemyY = organism->GetPositionY();
			if (organism->StrengthBoost()) {
				this->SetStrength(GetStrength() + 3);
				cout << this->GetSymbol() << " boosted their strength, because ";
			}
			world->Kill(organism);
			cout << this->symbol << " killed " << organism->GetSymbol();
			if (organism->ReturnKill()) {
				cout <<  " and " << organism->GetSymbol() << " return-killed " << this->GetSymbol();
				world->Kill(this);
			}
			else {
				world->Move(enemyX, enemyY, this);
				SetPositionX(enemyX);
				SetPositionY(enemyY);
			}
			cout << endl;
		}
		else if (organism->AttackReflected(this) == false && organism->AttackAvoided() == true) {
			//ESCAPE UP
			if (GetPositionY() - 1 >= 0 && world->GetBoardAt(GetPositionX(), GetPositionY() - 1) == nullptr) {
				world->Move(GetPositionX(), GetPositionY() - 1, this);
				SetPositionY(GetPositionY() - 1);
				world->Move(GetPositionX(), GetPositionY() + 1, organism);
				organism->SetPositionY(GetPositionY() + 1);
				cout << organism->GetSymbol() << " avoided " << GetSymbol() << "'s attack" << endl;
			} 
			//ESCAPE DOWN
			else if (GetPositionY() + 1 < this->world->GetSizeY() && world->GetBoardAt(GetPositionX(), GetPositionY() + 1) == nullptr) {
				world->Move(GetPositionX(), GetPositionY() + 1, this);
				SetPositionY(GetPositionY() + 1);
				world->Move(GetPositionX(), GetPositionY() - 1, organism);
				organism->SetPositionY(GetPositionY() - 1);
				cout << organism->GetSymbol() << " avoided " << GetSymbol() << "'s attack" << endl;
			} 
			//ESCAPE LEFT
			else if (GetPositionX() - 1 >= 0 && world->GetBoardAt(GetPositionX() - 1, GetPositionY()) == nullptr) {
				world->Move(GetPositionX() - 1, GetPositionY(), this);
				SetPositionX(GetPositionX() - 1);
				world->Move(GetPositionX() + 1, GetPositionY(), organism);
				organism->SetPositionX(GetPositionX() + 1);
				cout << organism->GetSymbol() << " avoided " << GetSymbol() << "'s attack" << endl;
			}
			//ESCAPE RIGHT
			else if (GetPositionX() + 1 < this->world->GetSizeX() && world->GetBoardAt(GetPositionX() + 1, GetPositionY()) == nullptr) {
				world->Move(GetPositionX() + 1, GetPositionY(), this);
				SetPositionX(GetPositionX() + 1);
				world->Move(GetPositionX() - 1, GetPositionY(), organism);
				organism->SetPositionX(GetPositionX() - 1);
				cout << organism->GetSymbol() << " avoided "<< GetSymbol() << "'s attack" << endl;
			}
			//NO ESCAPE
			else {
				int enemyX = organism->GetPositionX();
				int enemyY = organism->GetPositionY();
				if (organism->StrengthBoost()) {
					this->SetStrength(GetStrength() + 3);
					cout << this->GetSymbol() << " boosted their strength, because ";
				}
				world->Kill(organism);
				cout << this->symbol << " couldn't escape " << organism->GetSymbol();
				if (organism->ReturnKill()) {
					cout << " and " << organism->GetSymbol() << " return-killed " << this->GetSymbol();
					world->Kill(this);
				}
				else {
					world->Move(enemyX, enemyY, this);
					SetPositionX(enemyX);
					SetPositionY(enemyY);
				}
				cout << endl;
			}
		}
		else if (organism->AttackReflected(this) == true && organism->AttackAvoided() == false) cout << organism->GetSymbol() << " reflected " << GetSymbol() << "'s attack" << endl;
	}
	else {
		if (AttackReflected(organism) == false) {
			if (this->StrengthBoost()) {
				organism->SetStrength(GetStrength() + 3);
				cout << organism->GetSymbol() << " boosted their strength, because ";
			}
			world->Kill(this);
			cout << this->symbol << " walked into " << organism->GetSymbol() << " and died" << endl;
		}
		else cout << this->symbol << " walked into " << organism->GetSymbol() << " and reflected their attack" << endl;
	}
}