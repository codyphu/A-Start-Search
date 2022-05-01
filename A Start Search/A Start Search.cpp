
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
    int nodes;

private:
    //priority_queue<Node*,vector<Node*>,compareF>;
};
int goal[9] = { 1,2,3,4,5,6,7,8,0 };
int test1[9]= { 1,2,3,4,5,6,7,0,8 };

int main()
{   
    //int inp;
   // cout << "Welcome to A* Search Algorithm please choose what heuristic you want to use" << endl << "Type 0 for Uniform Cost Search" << endl << "Type 1 for A* with the Misplaced Tile heuristic" << endl << "Type 2 for A* with the Euclidean Distance heuristic"<<endl;
    //cin >> inp;

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

