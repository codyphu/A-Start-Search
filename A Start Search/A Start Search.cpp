
#include <iostream>
#include <vector>
#include <queue>
#include "Node.h"
using namespace std;




int main()
{   
    vector<int> veasy{ 1,2,3,4,5,6,7,0,8 };
    vector<int> easy{ 1,2,0,4,5,3,7,8,6 };
    vector<int> doable{ 0,1,2,4,5,3,7,8,6 };
    vector<int> slightlyhard1{ 2,3,6,1,5,0,4,7,8 };
    //vector<int> slightlyhard2{ 2,0,3,1,7,6,5,4,8 }; tried to make a slower vector for misplace tile for low depth but it still went too fast
    vector<int> hard{ 1,2,6,0,3,5,4,7,8 };
    vector<int> harder{ 2,0,7,1,4,3,5,8,6 };
    vector<int> ohboy{ 8,7,1,6,0,2,5,4,3 };
    vector<int> testcase{ 1,0,3,4,2,6,7,5,8 };
    

    vector<int> input;
    Node* testn = new Node();
    Tree* testt = new Tree(testn);
    testn->g = 0;
    int inp;
    cout << "Welcome to 8 Puzzle Solver Algorithm please choose what heuristic you want to use" << endl << "Type 0 for Uniform Cost Search" << endl << "Type 1 for A* with the Misplaced Tile heuristic" << endl << "Type 2 for A* with the Euclidean Distance heuristic"<<endl;
    cin >> inp;
    while (inp < 0 || inp>2) {
        cout << "Invalid Itput. Please try again.";
        cin >> inp;
    }
    testt->newh = inp;
    cout << "If you want to use a preloaded 8 puzzle, input 0. If you want to input your own puzzle input 1."<<endl;
    cin >> inp;
    while (inp < 0 || inp>1) {
        cout << "Invalid Input. Please try again."<<endl;
        cin >> inp;
    }
    if (inp == 1) {
        cout << "Please input 9 numbers with a space inbetween each from 0-8 (0 represents the blank tile). The first 3 inputs will be the first row, the next 3 will be the second, and the last 3 will be the last row." << endl;
        cin >> inp;
        while (input.size() < 9) {
            input.push_back(inp);
            if (inp < 0 || inp >8) {
                cout << "Invalid input. Please input array from start.";
                input.clear();
            }
            cin >> inp;
            if (input.size() == 8) {
                input.push_back(inp);
            }
        }
        testn->data = input;
    }
    if (inp == 0) {
        cout << "Please Choose A Level of 8 Puzzle." << endl << "0 for Very Easy(Depth 2)" << endl << "1 for Easy(Depth 3)" << endl << "2 for Doable(Depth 5)" << endl << "3 for Oh Boy(Depth 23)" << endl << "4 for Testcase in Project(Depth 4)" << endl << "5 for SlightlyHard in Project(Depth 8)" <<endl << "6 for Hard in Project(Depth 12)" << endl << "7 for Harder in Project(Depth 16)" <<endl ;
        cin >> inp;
        while (inp < 0 || inp>7) {
            cout << "Invalid Itput. Please try again.";
            cin >> inp;
        }
        if (inp == 0)
            testn->data = veasy;
        if (inp == 1)
            testn->data = easy;
        if (inp == 2)
            testn->data = doable;
        if (inp == 3)
            testn->data = ohboy;
        if (inp == 4)
            testn->data = testcase;
        if (inp == 5)
            testn->data = slightlyhard1;
        if (inp == 6)
            testn->data = hard;
        if (inp == 7)
            testn->data = harder;
    }


    testt->copys.push_back(testn->data);
    testn->h=testt->heuristic(testn);
    testt->solve8puzzle();
    cout << "Do you want to back track from the Goal State Node. 0 for Yes. Anything else for No."<<endl;
    cin >> inp;
    if(inp==0)
    testt->backtrackFromGoal();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

