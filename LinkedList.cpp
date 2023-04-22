#include <iostream>
#include "LinkedList.h"

using namespace std;

Node::Node(Organism* organism) : organism(organism), next(nullptr), previous(nullptr) {}

Organism* Node::GetOrganism() {
	return this->organism;
}

Node* Node::GetNext() {
	return this->next;
}

void Node::SetNext(Node* next) {
	this->next = next;
}

Node* Node::GetPrevious() {
	return this->previous;
}

void Node::SetPrevious(Node* previous) {
	this->previous = previous;
}



LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

const int LinkedList::Length() {
	int counter = 0;
	Node* tmp = head;
	while (tmp != NULL) {
		counter++;
		tmp = tmp->GetNext();
	}
	return counter;
}

void LinkedList::Print() {
	Node* tmp = head;
	int counter = 0;
	while (tmp != NULL) {
		cout << counter << ") " << tmp->GetOrganism()->GetSymbol() << " i=" << tmp->GetOrganism()->GetInitiative() << " previous: ";
		if (tmp->GetPrevious() != nullptr) cout <<  tmp->GetPrevious()->GetOrganism()->GetSymbol();
		else cout << "none";

		cout << ", next: ";
		if (tmp->GetNext() != nullptr) cout << tmp->GetNext()->GetOrganism()->GetSymbol() << endl;
		else cout << "none" << endl;
		tmp = tmp->GetNext();
		counter++;
	}
}

int LinkedList::GetIndexWith(Organism* organism) {
	int counter = 0;
	Node* tmp = head;
	while (tmp != NULL) {
		if (tmp->GetOrganism() == organism) return counter;
		counter++;
		tmp = tmp->GetNext();
	}
	return -1;
}

Node* LinkedList::GetAtPos(int position) {
	Node* tmp = head;
	while (tmp != NULL) {
		if (position == 0) return tmp;
		position--;
		tmp = tmp->GetNext();
	}
	return NULL;
}

Node* LinkedList::GetLastWith(int initiative) {
	if (tail == NULL) return NULL;
	Node* tmp = tail;
	while (tmp != NULL) {
		if (tmp->GetOrganism()->GetInitiative() <= initiative) return tmp;
		tmp = tmp->GetPrevious();
	}
	return NULL;
}

Node* LinkedList::GetFirst() {
	return head;
}

Node* LinkedList::GetLast() {
	return tail;
}

void LinkedList::InsertAtTail(Organism* organism) {
	Node* newNode = new Node(organism);
	newNode->SetPrevious(tail);
	newNode->SetNext(NULL);
	if (tail != NULL) tail->SetNext(newNode);
	if (head == NULL) head = newNode;
	tail = newNode;
}

void LinkedList::InsertAtHead(Organism* organism) {
	Node* newNode = new Node(organism);
	newNode->SetPrevious(nullptr);
	newNode->SetNext(head);
	if (head != nullptr) head->SetPrevious(newNode);
	if (tail == nullptr) tail = newNode;
	head = newNode;
}

void LinkedList::InsertAfter(Organism* organism, Node* node) {
	if (node != nullptr) {
		Node* newNode = new Node(organism);
		newNode->SetNext(node->GetNext());
		newNode->SetPrevious(node);
		if (node->GetNext() != nullptr) node->GetNext()->SetPrevious(newNode);
		node->SetNext(newNode);
	}
	else this->InsertAtHead(organism);
}

void LinkedList::RemoveFirst() {
	head = head->GetNext();
	delete head->GetPrevious();
	head->SetPrevious(nullptr);
}

void LinkedList::RemoveLast() {
	tail = tail->GetPrevious();
	delete tail->GetNext();
	tail->SetNext(nullptr);
}

void LinkedList::RemoveNode(Node* node) {
	if (node == nullptr) return;
	std::cout << "Removing node with organism: " << node->GetOrganism()->GetSymbol() << std::endl;
	if (node->GetPrevious() == nullptr) this->RemoveFirst();
	else if (node->GetNext() == nullptr) this->RemoveLast();
	else {
		node->GetNext()->SetPrevious(node->GetPrevious());
		node->GetPrevious()->SetNext(node->GetNext());
		delete node;
	}
}

/*
Node* temp = head;
while (temp != nullptr) {
	if (organism.inicjatywa < temp.inicjatywa)
}*/