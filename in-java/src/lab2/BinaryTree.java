package lab2;

import lab1.Node;

class TreeNode {
    public int data;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(int data) {
        this.data = data;
    }
}


public class BinaryTree {
    public TreeNode root;

    public void create() {
        root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(4);
        root.right.left = new TreeNode(3);
        root.right.right = new TreeNode(5);
    }

    public void preorder() {
        _preorder(root);
    }

    private void _preorder(TreeNode node) {
        if (node != null) {
            System.out.print(node.data);
            _preorder(node.left);
            _preorder(node.right);
        }
    }

    public void inorder() {
        _inorder(root);
    }

    private void _inorder(TreeNode node) {
        if (node != null) {
            _inorder(node.left);
            System.out.print(node.data);
            _inorder(node.right);
        }
    }

    public void postorder() {
        _postorder(root);
    }

    private void _postorder(TreeNode node) {
        if (node != null) {
            _preorder(node.left);
            _preorder(node.right);
            System.out.println(node.data);
        }
    }

    /**
     * only when the tree is BST can use this method
     *
     * @param data
     * @return
     */
    public TreeNode search(int data) {
        return _search(root, data);
    }


    private TreeNode _search(TreeNode node, int data) {
//        if (node == null || node.data == data) {
//            return node;
//        } else {
//            if (data < node.data) {
//                return _search(node.left, data);
//            } else {
//                return _search(node.right, data);
//            }
//        }

        return node == null || node.data == data
                ? node
                : _search(data < node.data ? node.left : node.right, data);
    }

    /**
     * BST的插入算法
     *
     * @param data
     */
    public void insert(int data) {
        _insert(this.root, data);
    }

    private TreeNode _insert(TreeNode root, int data) {
//        if (root == null)
//            return new TreeNode(data);
        if (root == null) {
            root = new TreeNode(data);
            return root;
        }

        if (data < root.data) root.left = _insert(root.left, data);
        if (data > root.data) root.right = _insert(root.right, data);
        return root;
    }

    /**
     *  BST的删除算法
     *
     * @param data
     */

    public void delete(int data) {
        _delete(root, data);
    }

    private TreeNode _delete(TreeNode node, int data) {
        if (node == null)
            return null;

        if (data < node.data) {
            node.left = _delete(node.left, data);
        } else if (data > node.data) {
            node.right = _delete(node.right, data);
        } else {  //找到了要删除的节点
            if (node.left == null) return node.right;

        }
        return node;

    }


    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        //tree.root = new TreeNode(2);
        tree.insert(1);
        System.out.println(tree.root.data);
        //System.out.println(tree.root.left.data);
    }
}
