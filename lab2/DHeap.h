//
// Created by Whoami on 2021/4/15.
//

#ifndef DATA_STRUCTURE_LAB_2_DHEAP_H
#define DATA_STRUCTURE_LAB_2_DHEAP_H
using namespace std;

template<typename T>

class DHeap {

    /**
     * This is a Min Heap
     */
public:
    static const int CAP = 50;
    T array[CAP];
    int length;
    int numOfChild{};

    /**
     * TOOL FUNCTIONS START
     */

    /**
     * @param parentIndex
     * @return address of index array head
     */
    int *getChildIndexArray(int parentIndex) {
        int *childIndexArray = new int[numOfChild];
        int *res = &childIndexArray[0];
        for (int i = 0; i < numOfChild; i++) {
            childIndexArray[i] = parentIndex * numOfChild + i + 1;
        }
        return res;
    }

    /**
     * @param parentIndex
     * @return address of element array head
     */
    T *getChildElementArray(int parentIndex) {
        T *childElementArray = new T[numOfChild];
        T *res = &childElementArray[0];
        for (int i = 0; i < numOfChild; i++) {
            childElementArray[i] = array[*getChildIndexArray(parentIndex) + i];
        }
        return res;
    }

    /**
     * @param childIndex
     * @return
     */
    int getParentIndex(int childIndex) {
        return (childIndex - 1) / numOfChild;
    }

    /**
     * @param childIndex
     * @return int parent element
     */
    T getParentElement(int childIndex) {
        return array[getParentIndex(childIndex)];
    }

    bool hasParent(int childIndex) {
        return getParentIndex(childIndex) >= 0;
    }

    bool hasChild(int parentIndex, int childNum) { //childNum:1, 2, 3...
        return numOfChild * parentIndex + childNum < length;
    }

    int getMinIndex(int index) {
        int minChildIndex = *getChildIndexArray(index);
        for (int i = 0; i < numOfChild - 1; i++) {
            if (hasChild(index, i + 2) && *(getChildElementArray(index) + i + 1) < array[minChildIndex]) {
                minChildIndex = *(getChildIndexArray(index) + i + 1);
            }
        }
        return minChildIndex;
    }

    /**
     * let the smaller element upon the root
     */
    void heapifyUp() {
        int index = length - 1;
        while (hasParent(index) && getParentElement(index) > array[index]) {
            T tmp = getParentElement(index);
            array[getParentIndex(index)] = array[index];
            array[index] = tmp;
            index = getParentIndex(index);  // check the parent node
        }
    }

    void heapifyDown() {
        int index = 0;
        while (hasChild(index, 1)) {
            //get min index
            int minChildIndex = getMinIndex(index);

            if (array[index] > array[minChildIndex]) {
                //swap
                T tmp = array[index];
                array[index] = array[minChildIndex];
                array[minChildIndex] = tmp;
            } else {
                break;
            }
            index = minChildIndex;
        }
    }
    /**
     * TOOL FUNCTIONS END
     */

public:
    DHeap(int numOfChild) {
        this->numOfChild = numOfChild;
        length = 0;
    }

    ~DHeap() = default;

    void insert(T element) {
        array[length] = element;
        length++;
        heapifyUp(); // change the position of bigger element
    }

    T deleteMin() { // delete the root
        if (length == 0)
            return -1;
        T res = array[0];
        array[0] = array[length - 1];
        length--;
        heapifyDown();
        return res;
    }


    bool isEmpty() {
        return length == 0;
    }

    void printHeap() {
        for (int i = 0; i < length; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};


#endif //DATA_STRUCTURE_LAB_2_DHEAP_H
