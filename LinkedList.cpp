#include "LinkedList.h"
#include "Organism.h"
#include "Constants.h"
#include <iostream>

using namespace std;

Node::Node(Organism* organism, Node* next) {
	this->organism = organism;
	this->next = next;
}

Node::~Node() {
	delete organism;
}

Organism* Node::getOrganism() {
	return organism;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* next) {
	this->next = next;
}

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

LinkedList::~LinkedList() {
	while (head != NULL) {
		removeHead();
	}
}

void LinkedList::add(Organism* organism) {
	cout << "Trying to add: " << organism->GetSymbol() << endl;
	Node* node = head;
	if (head == nullptr) {
		head = new Node(organism, nullptr);
		tail = head;
		size++;
		return;
	}
	while (node != nullptr) {
		if (node->getOrganism()->GetInitiative() < organism->GetInitiative()) {
			if (node == head) {
				head = new Node(organism, node);
				size++;
				return;
			}
			else {
				Node* prev = head;
				while (prev->getNext() != node) {
					prev = prev->getNext();
				}
				prev->setNext(new Node(organism, node));
				size++;
				return;
			}
		}
		else if (node->getOrganism()->GetInitiative() == organism->GetInitiative()) {
			if (node->getOrganism()->getAge() < organism->getAge()) {
				if (node == head) {
					head = new Node(organism, node);
					size++;
					return;
				}
				else {
					Node* prev = head;
					while (prev->getNext() != node) {
						prev = prev->getNext();
					}
					prev->setNext(new Node(organism, node));
					size++;
					return;
				}
			}
		}
		if (node->getNext() == nullptr) {
			node->setNext(new Node(organism, nullptr));
			tail = node->getNext();
			size++;
			return;
		}
		node = node->getNext();
	}
}

void LinkedList::remove(Organism* organism) {
	Node* node = head;
	Node* prev = NULL;
	while (node != NULL) {
		if (node->getOrganism() == organism) {
			if (prev == NULL) {
				removeHead();
			}
			else if (node->getNext() == NULL) {
				removeTail();
			}
			else {
				prev->setNext(node->getNext());
				delete node;
				size--;
			}
			return;
		}
		prev = node;
		node = node->getNext();
	}
}

void LinkedList::remove(Node* node) {
	Node* prev = NULL;
	Node* current = head;
	while (current != NULL) {
		if (current == node) {
			if (prev == NULL) {
				removeHead();
			}
			else if (current->getNext() == NULL) {
				removeTail();
			}
			else {
				prev->setNext(current->getNext());
				delete current;
				size--;
			}
			return;
		}
		prev = current;
		current = current->getNext();
	}
}

void LinkedList::removeHead() {
	if (head != NULL) {
		Node* node = head;
		head = head->getNext();
		delete node;
		size--;
	}
}

void LinkedList::removeTail() {
	if (tail != NULL) {
		Node* node = head;
		Node* prev = NULL;
		while (node != NULL) {
			if (node->getNext() == NULL) {
				if (prev == NULL) {
					head = NULL;
					tail = NULL;
				}
				else {
					prev->setNext(NULL);
					tail = prev;
				}
				delete node;
				size--;
				return;
			}
			prev = node;
			node = node->getNext();
		}
	}
}

Node* LinkedList::getHead() {
	return head;
}

Node* LinkedList::getTail() {
	return tail;
}


int LinkedList::getSize() {
	return size;
}

void LinkedList::print() {
	Node* node = head;
	cout << "Organisms: " << size << endl;
	while (node != NULL) {
		cout << node->getOrganism()->GetSymbol() << " " << node->getOrganism()->GetInitiative() << " ";
		node = node->getNext();
	}
	cout << endl;
}