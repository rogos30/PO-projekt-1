#include "Constants.h"

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
	this->SetHumanAlive(false);

	Node* node = organisms->GetHead();
	while (node != nullptr) {
		if (node->GetOrganism()!=nullptr) node->GetOrganism()->Action();
		node = node->GetNext();
	}
	this->DrawWorld();
	organisms->Print();
	turn++;
}

int World::GetTurn() {
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
	organisms->Add(organism);
}

void World::Kill(Organism* organism) {
	board[organism->GetPositionY()][organism->GetPositionX()] = nullptr;
	organisms->Remove(organism);
}

void World::Move(int destinationX, int destinationY, Organism* organism) {
	std::cout << organism->GetSymbol() << " moved from (" << organism->GetPositionX() << ", " << organism->GetPositionY() << ") to (" << destinationX << ", " << destinationY << ")" << std::endl;
	board[organism->GetPositionY()][organism->GetPositionX()] = nullptr;
	board[destinationY][destinationX] = organism;
}

void World::SaveGame() {
	std::ofstream file;
	file.open("save.txt");
	file << sizeX << " " << sizeY << " " << turn << " " << humanAlive << std::endl;
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (board[i][j] != nullptr) {
				file << board[i][j]->GetSymbol() << " " << board[i][j]->GetPositionX() << " " << board[i][j]->GetPositionY() << " " << board[i][j]->GetStrength() << " " << board[i][j]->GetInitiative() << " " << board[i][j]->GetAge();
				if (board[i][j]->GetSymbol() == 'H') {
					file << " " << ((Human*)board[i][j])->GetAbilityCooldown();
				}
				file << std::endl;
			}
		}
	}
	file.close();
}

void World::LoadGame() {
		std::ifstream file;
	file.open("save.txt");
	file >> sizeX >> sizeY >> turn >> humanAlive;
	board = new Organism**[sizeY];
	for (int i = 0; i < sizeY; i++) {
		board[i] = new Organism * [sizeX];
		for (int j = 0; j < sizeX; j++) {
			board[i][j] = nullptr;
		}
	}
	organisms = new LinkedList;
	char symbol;
	int positionX, positionY, strength, initiative, age, abilityCooldown;
	while (file >> symbol >> positionX >> positionY >> strength >> initiative >> age) {
		switch (symbol) {
		case 'A':
			AddOrganism(new Antelope(positionX, positionY, this), positionX, positionY);
			break;
		case 'n':
			AddOrganism(new Nightshade(positionX, positionY, this), positionX, positionY);
			break;
		case 'd':
			AddOrganism(new Dandelion(positionX, positionY, this), positionX, positionY);
			break;
		case 'F':
			AddOrganism(new Fox(positionX, positionY, this), positionX, positionY);
			break;
		case 'g':
			AddOrganism(new Grass(positionX, positionY, this), positionX, positionY);
			break;
		case 'H':
			file >> abilityCooldown;
			AddOrganism(new Human(positionX, positionY, this), positionX, positionY);
			((Human*)board[positionY][positionX])->SetAbilityCooldown(abilityCooldown);
			break;
		case 'u':
			AddOrganism(new Guarana(positionX, positionY, this), positionX, positionY);
			break;
		case 'W':
			AddOrganism(new Wolf(positionX, positionY, this), positionX, positionY);
			break;
		case 'S':
			AddOrganism(new Sheep(positionX, positionY, this), positionX, positionY);
			break;
		case 'h':
			AddOrganism(new Hogweed(positionX, positionY, this), positionX, positionY);
			break;
		case 'T':
			AddOrganism(new Turtle(positionX, positionY, this), positionX, positionY);
			break;
		}
	}
	file.close();
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