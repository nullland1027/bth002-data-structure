#include <iostream>
#include "QuadHeap.h"
#include <cstdlib>
#include <ctime>
#include "DHeap.h"

#define random(a, b) (rand() % (b - a) + a)

using namespace std;

/**
 * Task 1 & Task 2a
 */
void testQuadHeapByMyself() {
    //use random number to insert the heap
    int random_array[12];
    QuadHeap<int> test;
    srand((int) time(0));
    for (int &i : random_array) {
        i = random(0, 20);
    }
    //insert the number in random_array
    for (int &i: random_array) {
        test.insert(i);
    }
    test.printHeap();

    cout << endl;
    cout << test.deleteMin() << endl;
    test.printHeap();
}

/**
 * Task 2b
 */
void testQuadHeap() {
    QuadHeap<int> myheap;
    int insert_array1[7] = {10, 12, 1, 14, 6, 5, 8};
    int insert_array2[8] = {15, 3, 9, 7, 4, 11, 13, 2};
    for (int &i : insert_array1) {
        myheap.insert(i);
    }
    myheap.printHeap();
    myheap.deleteMin();
    myheap.printHeap();
    cout << "------Second Insert-------" << endl;
    for (int &i : insert_array2) {
        myheap.insert(i);
    }
    myheap.printHeap();
    while (!myheap.isEmpty()) {
        myheap.deleteMin();
        myheap.printHeap();
    }
}
/**
 * Task 3 arbitrary number of children heap
 */
void testdHeap() {
    DHeap<int> mydheap(2);
    int random_array[12];
    QuadHeap<int> test;
    srand((int) time(0));
    for (int &i : random_array) {
        i = random(0, 20);
    }
    //insert the number in random_array
    for (int &i: random_array) {
        mydheap.insert(i);
    }

    mydheap.printHeap();
    cout << mydheap.deleteMin() << endl;
    mydheap.printHeap();
}

/**
 * Actually, I dont understand what the problem meaning.
 */
void testTask4() {
    //TODO
}
int main() {
    //testQuadHeap();
    //testdHeap();
    DHeap<int> *heap = new DHeap<int>(2);
}
