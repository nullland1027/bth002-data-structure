//
// Created by Whoami on 2021/4/8.
//

#ifndef LAB1_LINKEDLIST_H
#define LAB1_LINKEDLIST_H

#include "Node.h"

using namespace std;

template<typename T>
class LinkedList {
private:
    Node<T> *head; // create a head node
    int length;
public:

    LinkedList() {
        length = 0;
        head = nullptr;
    }

    virtual ~LinkedList() = default;


    int getSize() {
        return length;
    }

    void addLast(T ele) {
        auto *node = new Node<T>(ele);
        if (head == nullptr) {
            head = node;
            head->setNext(nullptr);
            head->setPrevious(nullptr);
        } else {
            Node<T> *trav = head;
            for (int i = 0; i < length - 1; i++) {
                trav = trav->getNext();
            }
            trav->setNext(node);
            node->setPrevious(trav);
            node->setNext(nullptr);
        }
        length++;
    }

    void addFirst(T ele) {
        auto *node = new Node<T>(ele);
        if (head == nullptr) {
            head = node;
            node->setNext(nullptr);
            node->setPrevious(nullptr);
        } else {
            node->setNext(head);
            head->setPrevious(node);
            head = node;
        }
        length++;
    }

    T removeFirst() {
        if (length == 0) {
            cout << "Remove Error" << endl;
            return -1;
        } else {
            Node<T> *trav = head;
            head = head->getNext();
            int res = trav->getData();
            trav->setNext(nullptr);
            head->setPrevious(nullptr);
            delete trav;
            length--;
            return res;
        }
    }

    T removeLast() {
        if (length == 0) {
            cout << "Remove Error" << endl;
            return -1;
        } else if (length == 1) {
            int res = head->getData();
            delete head;
            length--;
            return res;
        } else {
            int res;
            Node<T> *trav = head;
            Node<T> *trav2 = head;
            for (int i = 0; i < length - 1; i++) {
                trav = trav->getNext();
            }
            for (int i = 0; i < length - 2; i++) {
                trav2 = trav2->getNext();
            }
            res = trav->getData();
            delete trav;
            trav2->setNext(nullptr);
            length--;
            return res;
        }
    }

    T returnNth(int nth) {
        if (nth <= length) {
            int res;
            Node<T> *trav = head;
            for (int i = 0; i < nth - 1; i++) {
                trav = trav->getNext();
            }
            res = trav->getData();
            return res;
        } else {
            cout << "Out Range Error!" << endl;
            return -1;
        }
    }

    void printList() {
        Node<T> *trav = head;
        for (int i = 0; i < length; i++) {
            cout << trav->getData() << ", ";
            trav = trav->getNext();
        }
    }

    bool isEmpty() {
        return length == 0;
    }
};


#endif //LAB1_LINKEDLIST_H
