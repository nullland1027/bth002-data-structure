package lab2;

import lab1.LinkedList;
import lab1.Node;

/**
 * use array
 * data越大排在越前面
 */
public class PriorityQueue {
    private int data;


    public static void main(String[] args) {
        PriorityQueueInLinkedList myqueue = new PriorityQueueInLinkedList();
        myqueue.enQueue(1);
        myqueue.enQueue(0);
        myqueue.enQueue(2);
        myqueue.enQueue(10);
        myqueue.enQueue(5);
        System.out.println(myqueue.peek());
        myqueue.print();
        System.out.println();
        System.out.println(myqueue.dequeue());
        myqueue.print();
    }
}

/**
 * use linked list in lab1
 */
class PriorityQueueInLinkedList {

    public int length;
    public Node head;

    public PriorityQueueInLinkedList() {
        length = 0;
    }

    public void enQueue(int data) { // 相当于add last
        Node node = new Node(data);
        if (head == null) {
            head = node;
        } else {
            Node cur = head;
            if (head.data < data) {
                node.next = head;
                head = node;
            } else {
                while (cur.next != null && cur.next.data > data) {
                    cur = cur.next;
                }
                node.next = cur.next;
                cur.next = node;
            }
        }
        length++;
    }

    public int peek() {
        return head.data;
    }

    public int dequeue() { //相当于remove first
        int res = head.data;
        head = head.next;
        length--;
        return res;
    }

    public void print() {
        Node cur = head;
        System.out.print(cur.data);
        for (int i = 0; i < length - 1; i++) {
            cur = cur.next;
            System.out.print(" " + cur.data);
        }
    }
}
