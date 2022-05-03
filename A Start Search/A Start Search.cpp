
#include <iostream>
#include <vector>
#include <queue>
#include "Node.h"
using namespace std;
struct compareF{
    bool operator()(const Node* lhs, const Node* rhs)const {
        if (lhs->getF() == rhs->getF()) {
            return lhs->g > rhs->g;
       }
        return lhs->getF() < rhs->getF();
    }
};

class Tree{
public:
    Node* current;
    Node* root; //initial node/input
    int nodes;// nodes expanded
    vector<int> goal{ 1,2,3,4,5,6,7,8,0 };
    //vector<vector<int>> copys;//prevent repeating copys from being expanded and looping
    //operators

    Tree(Node* start) {
        root = start;
        current = start;
        nodes = 1;
        search.push(start);
    }

    bool checkGoal() {
        for (int i : goal) {
            if (current->data[i] != goal[i]) {
                return false;
            }
        }
    return true;
    }

    void solve8puzzle() {
        while (checkGoal()!=true) {
            int track = current->getBlank();
            
            if (track != 0 && track != 1 && track != 2) {
                Node* up = goUp();
                search.push(up);
                nodes++;
            }
            if (track != 6 && track != 7 && track != 8) {
                Node* down = goDown();
                search.push(down);
                nodes++;
            }
            if (track != 0 && track != 3 && track != 6) {
                Node* left = goLeft();
                search.push(left);
                nodes++;
            }
            if (track != 2 && track != 5 && track != 8) {
                Node* right = goRight();
                search.push(right);
                nodes++;
            }
            current->print();
            search.pop();
            current = search.top();
        }

    }
    Node* getNext(Node* add) {
        search.push(add);
        return search.top();
    }
    Node* goUp() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() - 3, current->getBlank()));
        current->child1 = next;
        return next;
    }
    Node* goDown() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() + 3, current->getBlank()));
        current->child2 = next;
        return next;
    }
    Node* goLeft() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() - 1, current->getBlank()));
        current->child3 = next;
        return next;
    }
    Node* goRight() {
        Node* next = new Node(current, current->swap(current->data, current->getBlank() + 1, current->getBlank()));
        current->child4 = next;
        return next;
    }

    priority_queue<Node*,vector<Node*>,compareF> search;
};



int main()
{   
    vector<int> test1{ 1,2,3,4,5,6,7,0,8 };
    //int inp;
   // cout << "Welcome to A* Search Algorithm please choose what heuristic you want to use" << endl << "Type 0 for Uniform Cost Search" << endl << "Type 1 for A* with the Misplaced Tile heuristic" << endl << "Type 2 for A* with the Euclidean Distance heuristic"<<endl;
    //cin >> inp;
   
    Node* testn = new Node(test1, 0, 0);
    Tree* testt = new Tree(testn);
    testt->solve8puzzle();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

