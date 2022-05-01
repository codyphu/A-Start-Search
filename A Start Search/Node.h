#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;
class Node
{
public:
	Node* parent;
	Node* next;
	int h; // heuristic
	int g; // pathcost
	int* data; //array of 9 to represent current state of the 8 puzzle
	Node(int* arr, int gp);
	Node(int* arr, int he, int gp); //constructor using input array as start state


	int getBlank(); //returns array location of 0

	void print();// prints out data and f (f=g+h)

};

#endif