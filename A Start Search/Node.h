#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct Node{
	Node* parent;
	Node* child1;// 4 children per node max bc of only 4 maximum operations
	Node* child2;
	Node* child3;
	Node* child4;
	int h; // heuristic
	int g; // pathcost
	vector<int> data; //array of 9 to represent current state of the 8 puzzle
};

class compareF {
public:
    bool operator()(const Node* lhs, const Node* rhs)const {
        /*if (lhs->h + lhs->g == rhs->h + rhs->g) { // is fine for certain misplace tile heuristics but overall slows program
            return lhs->h  > rhs->h ;
        }*/
        return lhs->h + lhs->g > rhs->h + rhs->g;
    }
};

class Tree {
public:
    Node* current;  //current node that will be expanded
    Node* root; //initial node/input
    Node* goalNode;//store goal state when acchieved
    int nodes;// nodes expanded
    int newh;
    vector<int> goal{ 1, 2, 3, 4, 5, 6, 7, 8, 0 };
    vector<vector<int>> copys;//prevent repeating copys from being expanded and looping
    priority_queue<Node*, vector<Node*>, compareF> search;

    Tree(Node* start);

    bool checkGoal();
    double heuristic(Node* next);
    int getZero(Node* arr);
    bool checkDuplicate(vector<int> arr);//checks for duplicates returns true if arr is a duplicate array
    int getY(int a);
    int getX(int a);

    //operators
    Node* goUp();
    Node* goDown();
    Node* goLeft();
    Node* goRight();

    void print();

    void solve8puzzle();
    
};
#endif