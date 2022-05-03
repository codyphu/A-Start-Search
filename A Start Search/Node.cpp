#include "Node.h"
#include <iostream>
#include <vector>

Tree::Tree(Node* start) {
    root = start;
    current = start;
    goalNode = nullptr;
    nodes = 1;
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
int Tree::heuristic(Node* arr) {
    if (arr->h = 0) {
        return 0;
    }
    if (arr -> h = 1) {
        return 1;
    }
    if (arr -> h = 2) {
        return 2;
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
    cout << "f=" << current->g + current->h << " g=" << current->g << " h=" << current->h << endl;
    for (int i = 0; i < 9; i++) {
        cout << current->data[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

Node* Tree::goUp() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current)-3));
    Node* next = new Node;
    next->g = current->g + 1;
    next->h = current->h;

    next->data = temp;
    current->child1 = next;
    return next;
}
Node* Tree::goDown() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current) + 3));
    Node* next = new Node;
    next->g = current->g + 1;
    next->h = current->h;

    next->data = temp;
    current->child2 = next;
    return next;
}
Node* Tree::goLeft() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current) - 1));
    Node* next = new Node;
    next->g = current->g + 1;
    next->h = current->h;

    next->data = temp;
    current->child3 = next;
    return next;
}
Node* Tree::goRight() {
    vector<int> temp = current->data;
    swap(temp.at(getZero(current)), temp.at(getZero(current) + 1));
    Node* next = new Node;
    next->g = current->g + 1;
    next->h = current->h;
  
    next->data = temp;
    current->child4 = next;
    return next;
}

void Tree::solve8puzzle() {
    while (checkGoal() != true) {
        int track = getZero(current);
        search.pop();
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

        print();
        current = search.top();


    }
    print();
    cout <<"Nodes Expanded= "<< nodes;;
}
