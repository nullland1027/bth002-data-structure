package lab2;

public class HaveiChildrenHeap {
    private int capacity;
    private int length;
    private int[] array;
    private int numOfChild;

    public HaveiChildrenHeap(int capacity, int i) {
        this.capacity = capacity;
        length = 0;
        array = new int[capacity];
        numOfChild = i;
    }

    /**
     * HELP FUNCTIONS START
     */
    private int[] getChildrenIndexArray(int parentIndex) {
        int[] childrenIndex = new int[numOfChild];
        for (int i = 0; i < numOfChild; i++) {
            childrenIndex[i] = 2 * parentIndex + i + 1;
        }
        return childrenIndex;
    }
    private int[] getChildrenArray(int parentIndex) {
        int[] children = new int[numOfChild];
        for (int i = 0; i < numOfChild; i++) {
            children[i] = array[getChildrenIndexArray(parentIndex)[i]];
        }
        return children;
    }
    private int get_parent_index(int childIndex) {
        return (childIndex - 1) / numOfChild;
    }
    private int get_parent(int childIndex) {
        return array[get_parent_index(childIndex)];
    }


    private int getParentIndex(int childIndex) {
        return (childIndex - 1) / numOfChild;
    }

    /**
     * HELP FUNCTIONS END
     */

    public static void main(String[] args) {

    }
}
