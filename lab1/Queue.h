//
// Created by Whoami on 2021/4/9.
//

#ifndef LAB1_QUEUE_H
#define LAB1_QUEUE_H

using namespace std;

template<typename T>
class Queue {
private:
    int size;
    static const int CAPACITY = 10;
    T queue[CAPACITY];
    int front;
    int back;
public:
    Queue() {
        size = 0;
        front = 0;
        back = -1;
    }

    ~Queue() = default;
    /**
     * into the queue
     * @param element
     */
    void enQueue(T element) {
        if (size < CAPACITY) {
            back = (back + 1) % CAPACITY;
            queue[back] = element;
            size++;
        } else {
            cout << "enQueue ERROR, queue is FULL! " << endl;
        }

    }

    /**
     * out of the queue
     */
    void deQueue() {
        if (size > 0) {
            front = (front + 1) % CAPACITY;
            size--;
        } else {
            cout << "deQueue ERROR! " << endl;
        }

    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        for (int i = front; i < back + 1; i++) {
            cout << queue[i] << ", ";
        }
    }
};


#endif //LAB1_QUEUE_H
