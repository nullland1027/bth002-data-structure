//
// Created by Whoami on 2021/4/17.
//

#ifndef DATA_STRUCTURE_LAB_3_MYTREE_H
#define DATA_STRUCTURE_LAB_3_MYTREE_H

#include "Node.h"

using namespace std;


class MyTree {
public:
    Node *root;
public:
    explicit MyTree(int data) {
        root = new Node(data);
    }

    MyTree() {
        root = nullptr;
    }

    bool inEmpty() {
        return root == nullptr;
    }

    /**
     * implement insert element in recursion way
     * @param data
     */
    void insertInRecursion(int data) {
        _insertInRecursion(root, data);
    }

/**
 * help function
 */
private:
    Node *_insertInRecursion(Node *node, int data) {
        if (node == nullptr) {
            node = new Node(data);
            return node;
            //return new Node(data);
        }
        if (data < node->getdata()) node->setLeft(_insertInRecursion(node->getLeft(), data));
        if (data > node->getdata()) node->setRight(_insertInRecursion(node->getRight(), data));
        return node;
    }

public:
    void insertInLooping(int data) {
        if (root == nullptr) {
            root = new Node(data);
            return;
        }
        Node *current = root;
        Node *parent;
        while (current != nullptr) {
            parent = current;
            if (data < current->getdata()) current = current->getLeft();
            else if (data > current->getdata()) current = current->getRight();
        }
        if (data < parent->getdata()) parent->setLeft(new Node(data));
        if (data > parent->getdata()) parent->setRight(new Node(data));
    }

public:
    bool contains(int data) {
        return _search(root, data) != nullptr;
    }

private:
    Node *_search(Node *node, int data) {
        return node == nullptr || node->getdata() == data
               ? node
               : _search(data < node->getdata() ? node->getLeft() : node->getRight(), data);
    }

public:

    int findMinValue() const {
        Node *current = root;
        Node *parent;
        while (current != nullptr) {
            parent = current;
            current = current->getLeft();
        }
        return parent->getdata();
    }


/**
     * print tree in inorder
     * root->left->right
     */
    void printTree() {
        cout << "Inorder: " << endl;
        _inorder(root);
        cout << endl;
    }

private:
    void _inorder(Node *pNode) {
        if (pNode != nullptr) {
            _inorder(pNode->getLeft());
            cout << pNode->getdata() << " ";
            _inorder(pNode->getRight());
        }
    }
    /**
     * print tree in preorder
     */
public:
    void printTreePreorder() {
        cout << "Preorder: " << endl;
        _preorder(root);
        cout << endl;
    }

private:
    void _preorder(Node *pnode) {
        if (pnode != nullptr) {
            cout << pnode->getdata() << " ";
            _preorder(pnode->getLeft());
            _preorder(pnode->getRight());
        }
    }
};


#endif //DATA_STRUCTURE_LAB_3_MYTREE_H
