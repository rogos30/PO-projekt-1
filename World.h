#pragma once
#include "Constants.h"

class Organism;
class LinkedList;

class World {
private:
    int sizeX, sizeY, turn=0;
    Organism*** board;
    LinkedList* organisms;
    bool humanAlive = true;
    char input;

public:
    World(int sizeX, int sizeY);
    void SimulateTurn();
    void DrawWorld();
    void AddOrganism(Organism* organism, int positionX, int positionY);
    void Kill(Organism* organism);
    void Move(int destinationX, int destinationY, Organism* organism);
    void SaveGame();
    void LoadGame();
    int GetSizeX();
    int GetSizeY();
    char GetInput();
    int GetTurn();
    void SetInput(int ch);
    bool GetHumanAlive();
    void SetHumanAlive(bool humanAlive);
    LinkedList* GetOrganisms();
    Organism* GetBoardAt(int positionX, int positionY);
    ~World();
};