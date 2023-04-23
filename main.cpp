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
#include "Fox.h"
#include "Turtle.h"
#include "Nightshade.h"
#include "Hogweed.h"
#include "Guarana.h"

using namespace std;

int main() {
	srand(time(NULL));
	World world(20, 20);

	Human* human1 = new Human(0, 0, &world);
	world.AddOrganism(human1, human1->GetPositionX(), human1->GetPositionY());



	Guarana* guarana1 = new Guarana(5, 2, &world);
	world.AddOrganism(guarana1, guarana1->GetPositionX(), guarana1->GetPositionY());

	Guarana* guarana2 = new Guarana(11, 13, &world);
	world.AddOrganism(guarana2, guarana2->GetPositionX(), guarana2->GetPositionY());



	Nightshade* nightshade1 = new Nightshade(17, 7, &world);
	world.AddOrganism(nightshade1, nightshade1->GetPositionX(), nightshade1->GetPositionY());



	Sheep* sheep1 = new Sheep(3, 3, &world);
	world.AddOrganism(sheep1, sheep1->GetPositionX(), sheep1->GetPositionY());

	Sheep* sheep2 = new Sheep(13, 4, &world);
	world.AddOrganism(sheep2, sheep2->GetPositionX(), sheep2->GetPositionY());

	Sheep* sheep3 = new Sheep(10, 9, &world);
	world.AddOrganism(sheep3, sheep3->GetPositionX(), sheep3->GetPositionY());

	Sheep* sheep4 = new Sheep(2, 7, &world);
	world.AddOrganism(sheep4, sheep4->GetPositionX(), sheep4->GetPositionY());



	Wolf* wolf1 = new Wolf(10, 18, &world);
	world.AddOrganism(wolf1, wolf1->GetPositionX(), wolf1->GetPositionY());

	Wolf* wolf2 = new Wolf(15, 15, &world);
	world.AddOrganism(wolf2, wolf2->GetPositionX(), wolf2->GetPositionY());



	Turtle* turtle1 = new Turtle(5, 5, &world);
	world.AddOrganism(turtle1, turtle1->GetPositionX(), turtle1->GetPositionY());


	
	Hogweed* hogweed1 = new Hogweed(17, 7, &world);
	world.AddOrganism(hogweed1, hogweed1->GetPositionX(), hogweed1->GetPositionY());

	Hogweed* hogweed2 = new Hogweed(15, 5, &world);
	world.AddOrganism(hogweed2, hogweed2->GetPositionX(), hogweed2->GetPositionY());



	Antelope* antelope1 = new Antelope(13, 3, &world);
	world.AddOrganism(antelope1, antelope1->GetPositionX(), antelope1->GetPositionY());

	Antelope* antelope2 = new Antelope(3, 7, &world);
	world.AddOrganism(antelope2, antelope2->GetPositionX(), antelope2->GetPositionY());

	

	Grass* grass1 = new Grass(3, 9, &world);
	world.AddOrganism(grass1, grass1->GetPositionX(), grass1->GetPositionY());

	Grass* grass2 = new Grass(3, 18, &world);
	world.AddOrganism(grass2, grass2->GetPositionX(), grass2->GetPositionY());



	Fox* fox1 = new Fox(2, 15, &world);
	world.AddOrganism(fox1, fox1->GetPositionX(), fox1->GetPositionY());



	Dandelion* dandelion1 = new Dandelion(0, 19, &world);
	world.AddOrganism(dandelion1, dandelion1->GetPositionX(), dandelion1->GetPositionY());

	Dandelion* dandelion2 = new Dandelion(10, 0, &world);
	world.AddOrganism(dandelion2, dandelion2->GetPositionX(), dandelion2->GetPositionY());


	world.DrawWorld();
	char userInput = 0;
	while ((userInput = _getch()) != 'q') {
		switch (userInput) {
		case UP_ARROW:
			world.SetInput(userInput);
			break;
		case DOWN_ARROW:
			world.SetInput(userInput);
			break;
		case LEFT_ARROW:
			world.SetInput(userInput);
			break;
		case RIGHT_ARROW:
			world.SetInput(userInput);
			break;
		case SPACE:
			world.SetInput(userInput);
			break;
		case ENTER:
			system("CLS");
			world.SimulateTurn();
		}
	}


	return 0;
}