package lab1;



public class LinkedList {
    public Node head;
    public int length;

    public LinkedList() {
        length = 0;
    }

    public void append(int data) {
        Node node = new Node(data);
        if (head == null) {
            head = node;
        } else {
            Node cur = head;
            for (int i = 0; i < length - 1; i++) {
                cur = cur.next;
            }
            cur.next = node;
        }
        length++;
    }

    public void removeLast() {
        Node cur = head;
        for (int i = 0; i < length - 1; i++) {
            cur = cur.next;
        }
        cur.next = null;
        length--;
    }

    public void print() {
        System.out.println("");
        Node cur = head;
        System.out.print(head.data);
        for (int i = 0; i < length - 1; i++) {
            cur = cur.next;
            System.out.print(" " + cur.data);
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        for (int i = 0; i < 10; i++) {
            list.append(i);
        }
        list.print();
        list.removeLast();
        list.print();
        list.removeLast();
        list.print();
    }

}


