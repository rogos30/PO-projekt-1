#pragma once
#include "Constants.h"

class World;

class Organism {
protected:
	int strength, initiative, positionX, positionY, age=0;
	char symbol;
	World* world;

public:
	Organism();
	Organism(int strength, int initiative, int positionX, int positionY, World* world);
	Organism(int strength, int initiative, int positionX, int positionY, int age, World* world);
	virtual void Action() = 0;
	virtual void Collision(Organism* organism) = 0;
	virtual bool AttackReflected(Organism* attacker);
	virtual bool AttackAvoided();
	virtual bool StrengthBoost();
	virtual bool ReturnKill();
	virtual void Reproduce() = 0;
	void Draw();
	int GetStrength();
	void SetStrength(int strength);
	int GetInitiative();
	void SetInitiative(int initiative);
	int GetPositionX();
	void SetPositionX(int positionX);
	int GetPositionY();
	void SetPositionY(int positionY);
	char GetSymbol();
	int GetAge();
	World* GetWorld();
	~Organism();
};
