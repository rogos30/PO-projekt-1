#pragma once
#include "Organism.h"
#include "LinkedList.h"

class Organism;
class LinkedList;

class World {
private:
    int sizeX, sizeY, turn=0;
    Organism*** board;
    LinkedList* organisms;

public:
    World();
    World(int sizeX, int sizeY);
    void SimulateTurn();
    void DrawWorld();
    void AddOrganism(Organism* organism, int positionX, int positionY);
    void Kill(Organism* organism);
    void Move(int destinationX, int destinationY, Organism* organism);
    int GetSizeX();
    int GetSizeY();
    Organism* GetBoardAt(int positionX, int positionY);
    ~World();
};