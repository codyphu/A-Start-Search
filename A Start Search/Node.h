#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
class Node
{
public:
	Node* parent;
	Node* child1;
	Node* child2;
	Node* child3;
	Node* child4;
	int h; // heuristic
	int g; // pathcost
	int* data; //array of 9 to represent current state of the 8 puzzle
	Node(int* arr, int he, int gp); //constructor using input array as start state


	int getBlank() const; //returns array location of 0
	int getF() const; //finds the value of f(f=g+h)
	void print() const;// prints out data and f (f=g+h)

};

#endif