#include "Node.h"
#include <iostream>
#include <vector>

Node::Node(vector<int> arr, int he, int gp) { //constructor using input array as start state
	parent = nullptr;
	child1 = nullptr;
	child2 = nullptr;
	child3 = nullptr;
	child4 = nullptr;
	data = arr;
	h = he;
	g = gp;
}

Node::Node(Node* curr, vector<int> arr) {
	Node* next = new Node(arr, curr->h,curr->g+curr->h+1);
	next->parent = curr;
}

vector<int> Node::swap(vector<int> arr, int x, int y) {
	vector<int> n; //new vector
	for (int i = 0; i < 9; i++) {
		n.push_back(arr[i]);
	}

	n[y] = n[x];
	n[x] = 0;
	return n;
}

int Node::getBlank() const { //returns array location of 0
	for (int i = 0; i < 9; i++) {
		if (data[i] == 0)
			return i;
	}
	return 0;
}

int Node::getF() const {
	int k = 0;
	if (h == 1) { //misplaced tile heuristic
		k = 0;
	}
	else if (h == 2) { //euclidean distance heuristic
		k = 0;
	}
	return g + k;
}

void Node::print() const {// prints out data and f (f=g+h)

	cout << "f=" << this->getF() << " h=" << h << " g=" << g << endl;
	for (int i = 0; i < 9; i++) {
		cout << data[i] << " ";
		if (i + 1 % 3 == 0) {
			cout << endl;
		}
	}
}
