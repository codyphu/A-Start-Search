
#include <iostream>
#include <vector>
#include <queue>
#include "Node.h"
using namespace std;




int main()
{   
    vector<int> test1{ 1,2,3,4,5,6,7,0,8 };
    //int inp;
   // cout << "Welcome to A* Search Algorithm please choose what heuristic you want to use" << endl << "Type 0 for Uniform Cost Search" << endl << "Type 1 for A* with the Misplaced Tile heuristic" << endl << "Type 2 for A* with the Euclidean Distance heuristic"<<endl;
    //cin >> inp;
   
    Node* testn = new Node();
    testn->data = test1;
    testn->g = 0;
    testn->h = 0;
    Tree* testt = new Tree(testn);
    testt->solve8puzzle();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

