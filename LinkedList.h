#pragma once
#include "Constants.h"
#include <iostream>
#include "Organism.h"

class Organism;

using namespace std;

class Node {
	Organism* organism;
	Node* next;
	public:
		Node(Organism* organism, Node* next);
		~Node();
		Organism* getOrganism();
		Node* getNext();
		void setNext(Node* next);
};

class LinkedList {
	Node* head;
	Node* tail;
	int size;
	public:
		LinkedList();
		~LinkedList();
		void add(Organism* organism);
		void remove(Organism* organism);
		void remove(Node* node);
		void removeHead();
		void removeTail();
		Node* getHead();
		Node* getTail();
		int getSize();
		void print();
};
