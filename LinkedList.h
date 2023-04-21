#pragma once
#include "Constants.h"
#include <iostream>
#include "Organism.h"

class Organism;

using namespace std;

class Node {
private:
	Organism* organism;
	Node* next;
	Node* previous;
public:
	Node(Organism* organism);
	Organism* GetOrganism();
	Node* GetNext();
	void SetNext(Node* next);
	Node* GetPrevious();
	void SetPrevious(Node* previous);
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	LinkedList();
	const int Length();
	void Print();
	int GetIndexWith(Organism* organism);
	Node* GetAtPos(int position);
	Node* GetLastWith(int initiative);
	Node* GetFirst();
	Node* GetLast();
	void InsertAtTail(Organism* organism);
	void InsertAtHead(Organism* organism);
	void InsertAfter(Organism* organism, Node* node);
	void RemoveFirst();
	void RemoveLast();
	void RemoveNode(Node* node);
};
