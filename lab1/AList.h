//
// Created by ZHANG HAOHAN on 2021/4/8.
//

#ifndef LAB1_ALIST_H
#define LAB1_ALIST_H

using namespace std;

class AList {
private:
    static const int capacity = 10;
    int data[capacity]{};
    int theSize;

public:
    AList() // Constructor
    { theSize = 0; }

    // Add a destructor
    ~AList() = default;

    /**
     * Add element into the head of list
     * @param element
     */
    void AddFirst(int element) {
        if (theSize < capacity) {
            for (int i = theSize; i > 0; i--) { // Make room for the new first element.
                data[i] = data[i - 1];
            }
            data[0] = element; // Add the new element first.
            theSize++;
        }
    }

    /**
     * Add element into the back of list
     * @param element
     */
    void AddLast(int element) {
        if (theSize < capacity) {
            data[theSize] = element; // Add the new element first.
        }
        theSize++;
    }

    /**
     * Remove element from the head of list
     * @param element
     */
    int RemoveFirst() {
        if (theSize > 0) {
            int res;
            res = data[0];
            for (int i = 0; i < theSize; i++) {
                data[i] = data[i + 1];
            }
            theSize--;
            return res;
        }
        return 0;
    }

    /**
     * Remove element from the back of list
     * @param element
     */
    int RemoveLast() {
        // Should add exception handling when theSize = 0.
        if (theSize > 0) {
            int temp = data[theSize - 1]; // Get the value of last element, which should be returned
            theSize--; // Decrease the number of elements
            return temp;
        }
        return 0;
    }

    /**
     * return the nth element of list
     * @param n
     * @return int
     */
    int ReturnNth(int n) {
        if (n <= theSize) {
            return data[n - 1];
        }
        return 0;
    }

    /**
     * Like toString
     */
    void PrintList() {
        for (int i = 0; i < theSize; i++) {
            cout << data[i] << " ";
        }
    }

    /**
     *
     * @return the length of list
     */
    int Size() {
        return theSize;
    }

    /**
     *
     * @return if list is empty
     */
    bool Empty() { return theSize == 0; }

    /**
     * HOW TO MOVE
     * @param element
     * @param index
     */
    void insert(int element, int index) {
        if (theSize < capacity) {
            //this part of insertion operation is wrong
//            for (int i = index; i < theSize; i++) {
//                data[i + 1] = data[i];
//            }

            for (int i = theSize + 1; i > index; i--) {
                data[i] = data[i - 1];
            }
            data[index] = element;
            theSize++;
        }
    }
};


#endif //LAB1_ALIST_H
