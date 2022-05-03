
#include <iostream>
#include <vector>
#include <queue>
#include "Node.h"
using namespace std;
struct compareF{
    bool operator()(const Node* lhs, const Node* rhs)const {
        return lhs->getF() < rhs->getF();
    }
};

class Tree {
    Node* current;
    Node* root; //initial node/input
    int nodes;// nodes expanded
    vector<int> goal{ 1,2,3,4,5,6,7,8,0 };
    vector<int> test1{ 1,2,3,4,5,6,7,0,8 };
    vector<vector<int>> copys;//prevent repeating copys from being expanded and looping
    //operators


    Tree(Node* start) {
        root = start;
        current = start;
        nodes = 1;
    }
    void solve8puzzle() {
    }

    Node* goUp() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() - 3, current->getBlank()));
    }
    Node* goDown() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() + 3, current->getBlank()));
    }
    Node* goLeft() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() - 1, current->getBlank()));
    }
    Node* goRight() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() + 1, current->getBlank()));
    }

private:
    priority_queue<Node*,vector<Node*>,compareF> search;
};



int main()
{   
    //int inp;
   // cout << "Welcome to A* Search Algorithm please choose what heuristic you want to use" << endl << "Type 0 for Uniform Cost Search" << endl << "Type 1 for A* with the Misplaced Tile heuristic" << endl << "Type 2 for A* with the Euclidean Distance heuristic"<<endl;
    //cin >> inp;

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

