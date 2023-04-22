#include "Constants.h"
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Sheep.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Wolf.h"
#include "Antelope.h"
#include "Human.h"

using namespace std;

int main() {
	srand(time(NULL));
	World world(20, 10);

	Human* human1 = new Human(0, 0, &world);
	world.AddOrganism(human1, human1->GetPositionX(), human1->GetPositionY());
	world.GetOrganisms()->Print();
	
	Wolf* wolf1 = new Wolf(10, 8, &world);
	world.AddOrganism(wolf1, wolf1->GetPositionX(), wolf1->GetPositionY());

	world.GetOrganisms()->Print();
	/*
	Sheep* sheep1 = new Sheep(19, 8, &world);
	world.AddOrganism(sheep1, sheep1->GetPositionX(), sheep1->GetPositionY());
	world.GetOrganisms()->Print();
	Sheep* sheep2 = new Sheep(9, 8, &world);
	world.AddOrganism(sheep2, sheep2->GetPositionX(), sheep2->GetPositionY());
	world.GetOrganisms()->Print();

	Wolf* wolf2 = new Wolf(15, 5, &world);
	world.AddOrganism(wolf2, wolf2->GetPositionX(), wolf2->GetPositionY());
	world.GetOrganisms()->Print();*/

	Sheep* sheep3 = new Sheep(10, 9, &world);
	world.AddOrganism(sheep3, sheep3->GetPositionX(), sheep3->GetPositionY());
	world.GetOrganisms()->Print();
	Sheep* sheep4 = new Sheep(10, 7, &world);
	world.AddOrganism(sheep4, sheep4->GetPositionX(), sheep4->GetPositionY());
	world.GetOrganisms()->Print();
	
	Wolf* wolf3 = new Wolf(19, 4, &world);
	world.AddOrganism(wolf3, wolf3->GetPositionX(), wolf3->GetPositionY());
	world.GetOrganisms()->Print();

	Antelope* antelope1 = new Antelope(13, 3, &world);
	world.AddOrganism(antelope1, antelope1->GetPositionX(), antelope1->GetPositionY());
	world.GetOrganisms()->Print();
	

	Grass* grass1 = new Grass(19, 9, &world);
	world.AddOrganism(grass1, grass1->GetPositionX(), grass1->GetPositionY());
	world.GetOrganisms()->Print();
	/*
	Grass* grass2 = new Grass(19, 3, &world);
	world.AddOrganism(grass2, grass2->GetPositionX(), grass2->GetPositionY());
	world.GetOrganisms()->Print();
	
	* Dandelion* dandelion1 = new Dandelion(0, 9, &world);
	Dandelion* dandelion2 = new Dandelion(10, 0, &world);
	world.AddOrganism(dandelion1, dandelion1->GetPositionX(), dandelion1->GetPositionY());
	world.AddOrganism(dandelion2, dandelion2->GetPositionX(), dandelion2->GetPositionY());
	*/


	world.DrawWorld();
	char ch;
	while (world.GetHumanAlive()) {
		world.SimulateTurn();
	}


	return 0;
}