#include "Constants.h"
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Sheep.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Wolf.h"

using namespace std;

int main() {
	srand(time(NULL));
	World world(20, 20);
	Sheep* sheep1 = new Sheep(10, 10, &world);
	Sheep* sheep2 = new Sheep(0, 0, &world);
	Wolf* wolf1 = new Wolf(0, 10, &world);
	Wolf* wolf2 = new Wolf(15,5, &world);
	/*
	Grass* grass1 = new Grass(19, 19, &world);
	Grass* grass2 = new Grass(19, 0, &world);
	Dandelion* dandelion1 = new Dandelion(0, 19, &world);
	Dandelion* dandelion2 = new Dandelion(10, 0, &world);*/
	world.AddOrganism(sheep1, sheep1->GetPositionX(), sheep1->GetPositionY());
	world.AddOrganism(sheep2, sheep2->GetPositionX(), sheep2->GetPositionY());
	world.AddOrganism(wolf1, wolf1->GetPositionX(), wolf1->GetPositionY());
	world.AddOrganism(wolf2, wolf2->GetPositionX(), wolf2->GetPositionY());
	/*
	world.AddOrganism(grass1, grass1->GetPositionX(), grass1->GetPositionY());
	world.AddOrganism(grass2, grass2->GetPositionX(), grass2->GetPositionY());
	world.AddOrganism(dandelion1, dandelion1->GetPositionX(), dandelion1->GetPositionY());
	world.AddOrganism(dandelion2, dandelion2->GetPositionX(), dandelion2->GetPositionY());*/

	while (1) {
		world.SimulateTurn();
		system("pause");
	}


	return 0;
}