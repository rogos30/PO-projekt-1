#include <iostream>
#include <Windows.h>
#include "World.h"

World::World(int sizeX, int sizeY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->turn = 0;
	this->input = 0;
	board = new Organism**[sizeY];
	for (int i = 0; i < sizeY; i++) {
		board[i] = new Organism * [sizeX];
		for (int j = 0; j < sizeX; j++) {
			board[i][j] = nullptr;
		}
	}
	organisms = new LinkedList;
}

void World::SimulateTurn() {
	//for (int i= organisms->Length()-1; i>=0; i++) organisms->GetAtPos(i)->GetOrganism()->Action();

	Node* node = organisms->getHead();
	while (node != nullptr) {
		if (node->getOrganism()!=nullptr) node->getOrganism()->Action();
		node = node->getNext();
		//system("pause");
	}
	this->DrawWorld();
	organisms->print();

	//for (int i = 0; i < organisms->Length(); i++)
	//	std::cout << organisms->GetAtPos(i)->GetOrganism()->GetSymbol() << " jest na polu: (" << organisms->GetAtPos(i)->GetOrganism()->GetPositionX() << ", " << 
	//	organisms->GetAtPos(i)->GetOrganism()->GetPositionY() << ")" << std::endl;
	turn++;
}

int World::getTurn() {
	return turn;
}

void World::DrawWorld() {
	std::cout << "Author: Igor Rogozinski, 193326, group 3" << std::endl;
	std::cout << turn << ". turn" << std::endl;
	for (int i = 0; i < sizeX + 2; i++) std::cout << "#";
	std::cout << std::endl;
	for (int i = 0; i < sizeY; i++) {
		std::cout << "#";
		for (int j = 0; j < sizeX; j++) {
			if (board[i][j] != nullptr) {
				board[i][j]->Draw();
			}
			else std::cout << " ";
		}
		std::cout << "#" << std::endl;
	}
	for (int i = 0; i < sizeX + 2; i++) std::cout << "#";
	std::cout << std::endl;
}

void World::AddOrganism(Organism* organism, int positionX, int positionY) {
	board[positionY][positionX] = organism;
	organism->SetPositionX(positionX);
	organism->SetPositionY(positionY);
	organisms->add(organism);
}

void World::Kill(Organism* organism) {
	board[organism->GetPositionY()][organism->GetPositionX()] = nullptr;
	organisms->remove(organism);
}

void World::Move(int destinationX, int destinationY, Organism* organism) {
	std::cout << organism->GetSymbol() << " moved from (" << organism->GetPositionX() << ", " << organism->GetPositionY() << ") to (" << destinationX << ", " << destinationY << ")" << std::endl;
	board[organism->GetPositionY()][organism->GetPositionX()] = nullptr;
	board[destinationY][destinationX] = organism;
}

int World::GetSizeX() {
	return sizeX;
}

int World::GetSizeY() {
	return sizeY;
}

char World::GetInput() {
	return input;
}

void World::SetInput(int ch) {
	this->input = ch;
}

bool World::GetHumanAlive() {
	return humanAlive;
}

void World::SetHumanAlive(bool humanAlive) {
	this->humanAlive = humanAlive;
}

LinkedList* World::GetOrganisms() {
	return organisms;
}

Organism* World::GetBoardAt(int positionX, int positionY) {
	return board[positionY][positionX];
}

World::~World() {

}