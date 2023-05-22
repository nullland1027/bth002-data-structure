#include <iostream>
#include "AList.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Circle.h"

using namespace std;

/**
 * Task 1a
 */
void testAList() {
    auto *mylist = new AList();
    for (int i = 0; i < 5; i++) {
        mylist->AddFirst(i);
    }
    mylist->PrintList();
    cout << endl;
    mylist->AddLast(10);
    mylist->PrintList();
    cout << endl;
    mylist->Empty() ? cout << "empty" : cout << "not empty";
    mylist->RemoveFirst();
    mylist->RemoveLast();
    cout << endl;
    cout << "Now the first element is " << mylist->ReturnNth(1) << endl;
    mylist->PrintList();
    mylist->insert(100, 1);
    cout << endl << "After insert 100 in index of 1" << endl;
    mylist->PrintList();
    delete mylist;
}

/**
 * Task 1b
 */
void testADTList() {
    auto *myLinkedList = new LinkedList<int>();
    myLinkedList->isEmpty() ? cout << "Is empty" << endl : cout << "Not empty" << endl;
    for (int i = 0; i < 10; ++i) {
        myLinkedList->addLast(i);
    }
    for (int i = 0; i < 10; i++) {
        myLinkedList->addFirst(i);
    }
    myLinkedList->printList();
    cout << endl;
    int f_number = myLinkedList->removeFirst();
    int l_number = myLinkedList->removeLast();
    cout << "The removed first element is " << f_number << endl;
    cout << "The removed last element is " << l_number << endl;
    myLinkedList->printList();
    cout << endl << myLinkedList->returnNth(1) << endl;
    cout << myLinkedList->getSize();

    //deletion
    while (!myLinkedList->isEmpty()) {
        myLinkedList->removeLast();
    }
    myLinkedList->printList();
    delete myLinkedList;
}

/**
 * Task 2
 */
void testStack() {
    Stack *mystack = new Stack();
    for (int i = 0; i < 10; ++i) {
        mystack->Push(i);
    }
    cout << "Size is " << mystack->getSize() << endl;
    mystack->isEmpty() ? cout << "Is empty" << endl : cout << "Not empty" << endl;
    cout << "top is " << mystack->Peek() << endl;
    cout << "pop element is " << mystack->Pop() << endl;
    cout << "Now top is " << mystack->Peek() << endl;
    delete mystack;
}

/**
 * Task 3
 */
void testQueue() {
    Queue<double> myQueue;
    myQueue.enQueue(1.1);
    myQueue.enQueue(2.2);
    myQueue.enQueue(3.3);
    myQueue.print();
    cout << endl;
    myQueue.deQueue();
    myQueue.print();
    cout << endl;
    myQueue.isEmpty() ? cout << "Yes" : cout << "No";
}

/**
 * Task 4
 */
void testJosephCircle() {
    int numberOfPeople = 7;
    int numberOfPass = 2;

    Circle mycircle(numberOfPeople, numberOfPass);
    for (int i = 0; i < numberOfPeople; i++) {
        mycircle.addPeople(i + 1);
    }

    while (mycircle.getCurrentPeople() != 1) {
        mycircle.removePeople();
    }
    cout << "The last man is " << mycircle.getPeopleNumber();
}


int main() {
//    testAList();
//    testADTList();
//    testStack();
//    testQueue();
    testJosephCircle();

    auto aaa = new LinkedList<int>;

    return 0;
}
