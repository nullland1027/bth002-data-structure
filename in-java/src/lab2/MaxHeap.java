package lab2;


import java.util.Arrays;
import java.util.NoSuchElementException;

/**
 * max heap
 * 最大节点在根部
 * 使用数组实现
 * author: ZHANG HAOHAN
 */
public class MaxHeap {
    private int capcity;
    public int length;
    private int[] array;

    public MaxHeap(int capcity) {
        this.capcity = capcity;
        length = 0;
        array = new int[capcity];
    }

    /**
     * 接下来的函数，找到父节点和子节点的index 的关系即可
     * HELP FUNCTIONS START
     */
    //得到节点的index
    private int getLeftChildIndex(int parentIndex) {
        return 2 * parentIndex + 1;
    }

    private int getRightChildIndex(int parentIndex) {
        return 2 * parentIndex + 2;
    }

    private int getParentIndex(int childIndex) {
        return (childIndex - 1) / 2;
    }

    // 判断是否有左右子节点 or parent node
    private boolean hasLeftChild(int parentIndex) {
        return getLeftChildIndex(parentIndex) < length;
    }

    private boolean hasRightChild(int parentIndex) {
        return getRightChildIndex(parentIndex) < length;
    }

    private boolean hasParent(int childIndex) {
        return getParentIndex(childIndex) >= 0;
    }

    //得到节点的值
    private int getLeftChild(int parentIndex) {
        return array[getLeftChildIndex(parentIndex)];
    }

    private int getRightChild(int parentIndex) {
        return array[getRightChildIndex(parentIndex)];
    }

    private int getParent(int childIndex) {
        return array[getParentIndex(childIndex)];
    }

    private void heapifyUp() {
        int index = length - 1;  //从最后一个节点开始
        while (hasParent(index) && getParent(index) < array[index]) {
            int temp = array[getParentIndex(index)];
            array[getParentIndex(index)] = array[index];
            array[index] = temp;
            index = getParentIndex(index);
        }
    }
    private void heapifyDown() {
        int index = 0;
        while (hasLeftChild(index)) {
            int largerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && getRightChild(index) > getLeftChild(index)) {
                largerChildIndex = getRightChildIndex(index);
            }
            if (array[index] < array[largerChildIndex]) {
                int temp = array[largerChildIndex];
                array[largerChildIndex] = array[index];
                array[index] = temp;
                index = largerChildIndex;
            }
        }
    }
    /**
     * HELP FUNCTIONS END
     */

    public void insert(int data) {
        if (length == capcity) {
            array = Arrays.copyOf(array, capcity * 2);
            capcity = capcity * 2;
        }
        array[length] = data;
        length++;
        heapifyUp();
    }

    public int pop() {
        if (length == 0) {
            throw new NoSuchElementException();
        }
        int res = array[0];
        array[0] = array[length - 1];
        length--;
        heapifyDown();
        return res;
    }

    public int peek() {
        if (length == 0) {
            throw new NoSuchElementException();
        }
        return array[0];
    }

    public void print() {
        for (int i = 0; i < this.length; i++) {
            System.out.print(this.array[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        MaxHeap myheap = new MaxHeap(10);
//        myheap.insert(1);
//        myheap.insert(2);
//        myheap.insert(0);
//        myheap.insert(10);
//
//        for (int i = 0; i < myheap.length; i++) {
//            System.out.print(myheap.array[i] + " ");
//        }
//        System.out.println();
//        System.out.println(myheap.peek()); //10
//        System.out.println(myheap.pop());  //10
//        for (int i = 0; i < myheap.length; i++) {
//            System.out.print(myheap.array[i] + " ");
//        }

        myheap.array[0] = 10;
        myheap.array[1] = 9;
        myheap.array[2] = 8;
        myheap.array[3] = 7;
        myheap.array[4] = 6;
        myheap.length = 5;
        myheap.print();
        myheap.insert(11);
        myheap.print();
    }

}

