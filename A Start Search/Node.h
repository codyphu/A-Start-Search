#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
	Node* parent;
	Node* child1;// 4 children per node max bc of only 4 maximum operations
	Node* child2;
	Node* child3;
	Node* child4;
	int h; // heuristic
	int g; // pathcost
	vector<int> data; //array of 9 to represent current state of the 8 puzzle

	Node(vector<int> arr, int he, int gp); //constructor using input vector as start state and base of tree
	Node(Node* curr, vector<int> arr);//constructor for children of the tree

	vector<int> swap(vector<int> arr, int x, int y); //swap where x is the location of non zero number and y is the zero or blank
	int getBlank() const; //returns array location of 0
	int getF() const; //finds the value of f(f=g+h)
	void print() const;// prints out data and f (f=g+h)

};

#endif