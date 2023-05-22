//
// Created by Whoami on 2021/4/8.
//

#ifndef LAB1_NODE_H
#define LAB1_NODE_H

template<typename T>
class Node {
private:
    T data;
    Node *next;
    Node *prev;

public:
    Node() {
        data = 0;
        next = nullptr;
    }

    Node(T d) {
        data = d;
        next = nullptr;
    }

    ~Node() {
        delete next;
    }

    T getData() {
        return data;
    }

    void setData(T d) {
        data = d;
    }

    Node *getNext() {
        return next;
    }

    void setNext(Node *n) {
        next = n;
    }

    Node *getPrevious() {
        return prev;
    }

    void setPrevious(Node *n) {
        prev = n;
    }
};


#endif //LAB1_NODE_H
