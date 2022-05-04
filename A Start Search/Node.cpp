#include "Node.h"
#include <iostream>
#include <vector>
#include <math.h>

Tree::Tree(Node* start) {
    root = start;
    current = start;
    goalNode = nullptr;
    nodes = 1;
    newh = 0;
    search.push(start);
}

bool Tree::checkGoal() {
    for (int i = 0; i < 9; i++) {
        if (current->data[i] != goal[i]) {
            return false;
        }
    }
    return true;
}

int Tree::getY(int a) {
    int y=1;
    while (a-3 > 0) {
        a -= 3;
        y++;
    }
    return y;
}
int Tree::getX(int a) {
    a += 1;
    while (a - 3 > 0) {
        a -= 3;
    }
    return a;
}

double Tree::heuristic(Node* next) {
    double heur = 0;
    if (newh == 0) {
        return 0;
    }
    if (newh == 1) {
        for (int i = 0; i < 9; i++) {
            if (i == 0) {
                if (next->data[8] != 0) {
                    heur++;
                }
            }
            else if (next->data[i - 1] != i) {
                heur++;
            }
        }
        return heur;
    }
    if (newh == 2) {
        for (int i = 0; i < 9; i++) {
            if (next->data[i] == 0) {
                heur+=sqrt(pow(((getX(i)) - 3), 2) + pow((getY(i) - 3), 2));
            }
            else if (next->data[i] == 1) {
                heur += sqrt(pow(((getX(i)) - 1), 2) + pow((getY(i) - 1), 2));
            }
            else if (next->data[i] == 2) {
                heur += sqrt(pow(((getX(i)) - 2), 2) + pow((getY(i) - 1), 2));
            }
            else if (next->data[i] == 3) {
                heur += sqrt(pow(((getX(i)) - 3), 2) + pow((getY(i) - 1), 2));
            }
            else if (next->data[i] == 4) {
                heur += sqrt(pow(((getX(i)) - 1), 2) + pow((getY(i) - 2), 2));
            }
            else if (next->data[i] == 5) {
                heur += sqrt(pow(((getX(i)) - 2), 2) + pow((getY(i) - 2), 2));
            }
            else if (next->data[i] == 6) {
                heur += sqrt(pow(((getX(i)) - 2), 2) + pow((getY(i) - 3), 2));
            }
            else if (next->data[i] == 7) {
                heur += sqrt(pow(((getX(i)) - 1), 2) + pow((getY(i) - 3), 2));
            }
            else if (next->data[i] == 8) {
                heur += sqrt(pow(((getX(i)) - 2), 2) + pow((getY(i) - 3), 2));
            }
        }
        return heur;
    }
    return 0;
}

int Tree::getZero(Node* arr) {
    for (int i = 0; i < 9; i++) {
        if (arr->data[i] == 0) {
            return i;
        }
   }
    return 0;
}
void Tree::print() {
    cout << "The best state to expand this node with g=" << current->g << " h=" << heuristic(current) << " is..." << endl;
    for (int i = 0; i < 9; i++) {
        cout << current->data[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}



bool Tree::checkDuplicate(vector<int> arr) {
    int track = 0;
    for (int i = 0; i < copys.size(); i++) {
        for (int j = 0; j < 9; j++) {
            if (copys[i][j] == arr[j]) {
                track++;
            }
        }
    }
    if (track == 9) {
        return true;
    }
    return false;
}

Node* Tree::goUp() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current)-3));
    if (checkDuplicate(temp)) {
        return nullptr;
    }
    copys.push_back(temp);
    Node* next = new Node;
    next->parent = current;
    next->g = current->g + current->h + 1;
    next->data = temp;
    next->h = heuristic(next);
    current->child1 = next;
    return next;
}
Node* Tree::goDown() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current) + 3));
    if (checkDuplicate(temp)) {
        return nullptr;
    }
    copys.push_back(temp);
    Node* next = new Node;
    next->parent = current;
    next->g = current->g + current->h+1;
    next->data = temp;
    next->h = heuristic(next);
    current->child2 = next;
    return next;
}
Node* Tree::goLeft() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current) - 1));
    if (checkDuplicate(temp)) {
        return nullptr;
    }
    copys.push_back(temp);
    Node* next = new Node;
    next->parent = current;
    next->g = current->g + current->h + 1;
    next->data = temp;
    next->h = heuristic(next);
    current->child3 = next;
    return next;
}
Node* Tree::goRight() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current) + 1));
    if (checkDuplicate(temp)) {
        return nullptr;
    }
    copys.push_back(temp);
    Node* next = new Node;
    next->parent = current;
    next->g = current->g + current->h + 1;
    next->data = temp;
    next->h = heuristic(next);
    current->child4 = next;
    return next;
}

void Tree::solve8puzzle() {
    while (checkGoal() != true) {
        int track = getZero(current);
        search.pop();
        if (track != 0 && track != 1 && track != 2) {
            Node* up = goUp();
            if(up!=nullptr){
                search.push(up);
                nodes++;
            }
        }
        if (track != 6 && track != 7 && track != 8) {
            Node* down = goDown();
            if (down != nullptr) {
                search.push(down);
                nodes++;
            }
        }
        if (track != 0 && track != 3 && track != 6) {
            Node* left = goLeft();
            if (left != nullptr) {
                search.push(left);
                nodes++;
            }
        }
        if (track != 2 && track != 5 && track != 8) {
            Node* right = goRight();
            if (right != nullptr) {
                search.push(right);
                nodes++;
            }
        }

        print();
        current = search.top();
    }
    goalNode = current;

    cout << "Goal Reached!!!"<<endl<< "This search expanded " << nodes <<" total nodes"<< endl;
    cout << "The max number of nodes in queue is "  << search.size() + 1 << endl;
    cout << "The depth of the goal node is " << getDepth() << endl;
}

void Tree::backtrackFromGoal() {
    current = goalNode;
    while (current->parent != nullptr) {
        backtrackPrint();
        if (getZero(current) - getZero(current->parent)==1) {
            cout << "Right Operator" << endl << endl;
        }
        else if (getZero(current) - getZero(current->parent) == -1) {
            cout << "Left Operator" << endl<<endl;
        }
        else if (getZero(current) - getZero(current->parent) == 3) {
            cout << "Down Operator" << endl << endl;
        }
        else if (getZero(current) - getZero(current->parent) == -3) {
            cout << "Up Operator" << endl << endl;
        }
        current = current->parent;
    }
    backtrackPrint();
    
}
void Tree::backtrackPrint(){
    for (int i = 0; i < 9; i++) {
        cout << current->data[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int Tree::getDepth() {
    int track=1;
    current = goalNode;
    while (current->parent != nullptr) {
        track++;
        current = current->parent;
    }
    return track;
}
