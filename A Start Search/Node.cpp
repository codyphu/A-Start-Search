#include "Node.h"

Node(int* arr, int gp) {
	parent = nullptr;
	next = nullptr;
	data = arr;
	g = gp;
}
Node::Node(int* arr, int he, int gp) { //constructor using input array as start state
	parent = nullptr;
	next = nullptr;
	data = arr;
	h = he;
	g = gp;

}

int Node::getBlank() { //returns array location of 0
	for (int i = 0; i < 9; i++) {
		if (data[i] == 0)
			return i;
	}
	return 0;
}
void Node::print() {// prints out data and f (f=g+h)
	int k;
	if (h == 1) { //misplaced tile heuristic
		k = 0;
	}
	else if (h == 2) { //euclidean distance heuristic
		k = 0;
	}
	cout << "f=" << h + g << "h=" << h << "g=" << g << endl;
	for (int i = 0; i < 9; i++) {
		cout << data[i] << " ";
		if (i + 1 % 3 == 0) {
			cout << endl;
		}
	}
}