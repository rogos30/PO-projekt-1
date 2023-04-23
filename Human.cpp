#include "Human.h"

Human::Human(int positionX, int positionY, World* world) {
	this->strength = 5;
	this->initiative = 4;
	this->abilityCooldown = 0;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
	this->symbol = 'H';
}

void Human::Action() {
	if (GetAbilityCooldown() >= 5) SetStrength(GetAbilityCooldown());
	SetAbilityCooldown(GetAbilityCooldown() - 1);

	char direction = world->GetInput();
	switch (direction) {
	case UP_ARROW:
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
	case DOWN_ARROW:
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
	case LEFT_ARROW:
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
	case RIGHT_ARROW:
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
	case SPACE:
		Ability();
		break;
	}
	cout << "Human strength: " << GetStrength() << endl;
	cout << "Human cooldown: " << GetAbilityCooldown() << endl;
}

void Human::Reproduce() {
}

void Human::Ability() {
	if (GetAbilityCooldown()<=0) SetAbilityCooldown(10);
}

int Human::GetAbilityCooldown() {
	return abilityCooldown;
}

void Human::SetAbilityCooldown(int cooldown) {
	abilityCooldown = cooldown;
}

Human::~Human() {}