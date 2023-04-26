#include "Constants.h"

using namespace std;

Node::Node(Organism* organism, Node* next) {
	this->organism = organism;
	this->next = next;
}

Node::~Node() {
	delete organism;
}

Organism* Node::GetOrganism() {
	return organism;
}

Node* Node::GetNext() {
	return next;
}

void Node::SetNext(Node* next) {
	this->next = next;
}

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

LinkedList::~LinkedList() {
	while (head != NULL) {
		RemoveHead();
	}
}

void LinkedList::Add(Organism* organism) {
	//cout << "Trying to add: " << organism->GetSymbol() << endl;
	Node* node = head;
	if (head == nullptr) {
		head = new Node(organism, nullptr);
		tail = head;
		size++;
		return;
	}
	while (node != nullptr) {
		if (node->GetOrganism()->GetInitiative() < organism->GetInitiative()) {
			if (node == head) {
				head = new Node(organism, node);
				size++;
				return;
			}
			else {
				Node* prev = head;
				while (prev->GetNext() != node) {
					prev = prev->GetNext();
				}
				prev->SetNext(new Node(organism, node));
				size++;
				return;
			}
		}
		else if (node->GetOrganism()->GetInitiative() == organism->GetInitiative()) {
			if (node->GetOrganism()->GetAge() < organism->GetAge()) {
				if (node == head) {
					head = new Node(organism, node);
					size++;
					return;
				}
				else {
					Node* prev = head;
					while (prev->GetNext() != node) {
						prev = prev->GetNext();
					}
					prev->SetNext(new Node(organism, node));
					size++;
					return;
				}
			}
		}
		if (node->GetNext() == nullptr) {
			node->SetNext(new Node(organism, nullptr));
			tail = node->GetNext();
			size++;
			return;
		}
		node = node->GetNext();
	}
}

void LinkedList::Remove(Organism* organism) {
	Node* node = head;
	Node* prev = NULL;
	while (node != NULL) {
		if (node->GetOrganism() == organism) {
			if (prev == NULL) {
				RemoveHead();
			}
			else if (node->GetNext() == NULL) {
				RemoveTail();
			}
			else {
				prev->SetNext(node->GetNext());
				//delete node;
				size--;
			}
			return;
		}
		prev = node;
		node = node->GetNext();
	}
}

void LinkedList::Remove(Node* node) {
	Node* prev = NULL;
	Node* current = head;
	while (current != NULL) {
		if (current == node) {
			if (prev == NULL) {
				RemoveHead();
			}
			else if (current->GetNext() == NULL) {
				RemoveTail();
			}
			else {
				prev->SetNext(current->GetNext());
				delete current;
				size--;
			}
			return;
		}
		prev = current;
		current = current->GetNext();
	}
}

void LinkedList::RemoveHead() {
	if (head != NULL) {
		Node* node = head;
		head = head->GetNext();
		//delete node;
		size--;
	}
}

void LinkedList::RemoveTail() {
	if (tail != NULL) {
		Node* node = head;
		Node* prev = NULL;
		while (node != NULL) {
			if (node->GetNext() == NULL) {
				if (prev == NULL) {
					head = NULL;
					tail = NULL;
				}
				else {
					prev->SetNext(NULL);
					tail = prev;
				}
				//delete node;
				size--;
				return;
			}
			prev = node;
			node = node->GetNext();
		}
	}
}

Node* LinkedList::GetHead() {
	return head;
}

Node* LinkedList::GetTail() {
	return tail;
}


int LinkedList::GetSize() {
	return size;
}

void LinkedList::Print() {
	Node* node = head;
	cout << "Organisms: " << size << endl;
	while (node != NULL) {
		cout << node->GetOrganism()->GetSymbol() << node->GetOrganism()->GetAge() << " ";
		node = node->GetNext();
	}
	cout << endl;
}