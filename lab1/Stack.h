//
// Created by Whoami on 2021/4/9.
//

#ifndef LAB1_STACK_H
#define LAB1_STACK_H

using namespace std;

class Stack {
private:
    static const int capacity = 10;
    int data[capacity]{};
    int theSize;

public:
    Stack() // Constructor
    { theSize = 0; }

    // Add a destructor
    ~Stack() = default;

    void Push(int element) {
        if (theSize == 0) {
            data[0] = element;
            theSize++;
        } else if (theSize < capacity) {
            for (int i = 0; i < theSize - 1; i++) {
                data[i + 1] = data[i];
            }
            data[0] = element;
            theSize++;
        } else {
            cout << "The stack is FULL! " << endl;
        }
    }

    int Pop() {
        if (theSize == 0) {
            cout << "The stack is empty, POP ERROR! " << endl;
            return -1;
        } else {
            int res = data[0];
            for (int i = 0; i < theSize - 1; i++) {
                data[i] = data[i + 1];
            }
            theSize--;
            return res;
        }
    }

    /**
     * To show the top element of stack
     * @return int
     */
    int Peek() {
        if (theSize == 0) {
            cout << "The Stack is EMPTY, PEEK ERROR! " << endl;
            return -1;
        } else {
            return data[0];
        }
    }

    int getSize() const {
        return theSize;
    } // To be implemented

    bool isEmpty() const { return theSize == 0; }
};


#endif //LAB1_STACK_H
