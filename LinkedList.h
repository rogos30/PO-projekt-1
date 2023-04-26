#pragma once
#include "Constants.h"

class Organism;

using namespace std;

class Node {
	Organism* organism;
	Node* next;
	public:
		Node(Organism* organism, Node* next);
		~Node();
		Organism* GetOrganism();
		Node* GetNext();
		void SetNext(Node* next);
};

class LinkedList {
	Node* head;
	Node* tail;
	int size;
	public:
		LinkedList();
		~LinkedList();
		void Add(Organism* organism);
		void Remove(Organism* organism);
		void Remove(Node* node);
		void RemoveHead();
		void RemoveTail();
		Node* GetHead();
		Node* GetTail();
		int GetSize();
		void Print();
};
