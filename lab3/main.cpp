#include <iostream>
#include "MyTree.h"
#include <cstdlib>
#include <ctime>

#define random(a, b) (rand() % (b - a) + a)
using namespace std;

int main() {
//    int random_array[30];
//    srand((int) time(0));
//    for (int &i : random_array) {
//        i = random(0, 1000);
//    }
//    auto *tree = new MyTree(random_array[0]); // root data is
//    for (int i = 1; i < 30; i++) {
//        tree->insertInRecursion(random_array[i]);
//    }
    MyTree *tree = new MyTree();
    tree->insertInRecursion(0);
    tree->printTree();
    cout << endl;
    tree->printTreePreorder();
    return 0;
}
