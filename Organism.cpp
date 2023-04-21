#include "Organism.h"
#include <iostream>

Organism::Organism() {}

Organism::Organism(int strength, int initiative, int positionX, int positionY, World* world) {
	this->strength = strength;
	this->initiative = initiative;
	this->positionX = positionX;
	this->positionY = positionY;
	this->world = world;
}

void Organism::Draw() {
	std::cout << symbol;
}

int Organism::GetStrength() {
	return strength;
}

void Organism::SetStrength(int strength) {
	this->strength = strength;
}

int Organism::GetInitiative() {
	return initiative;
}

void Organism::SetInitiative(int initiative) {
	this->initiative = initiative;
}

int Organism::GetPositionX() {
	return positionX;
}

void Organism::SetPositionX(int positionX) {
	this->positionX = positionX;
}

int Organism::GetPositionY() {
	return positionY;
}

void Organism::SetPositionY(int positionY) {
	this->positionY = positionY;
}

char Organism::GetSymbol() {
	return symbol;
}

World* Organism::GetWorld() {
	return world;
}

Organism::~Organism(){}