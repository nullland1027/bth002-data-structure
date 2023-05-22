//
// Created by Whoami on 2021/3/16.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include <iostream>


using namespace std;


class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int data) {
        this->data = data;
    }

    void setData(int i) {
        this->data = i;
    }

};
class BinaryTree {
public:
    TreeNode* root;

public:
    BinaryTree() {
        root = nullptr;
    }
    void createTree() {
        root = new TreeNode(0);
        root->left = new TreeNode(1);
        root->right = new TreeNode(2);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(4);
    }
    void preOrder() {
        _preorder(root);
    }

    void _preorder(TreeNode* node) {
        if (node != nullptr) {
            cout << node << " ";
            _preorder(node->left);
            _preorder(node->right);
        }
    }

    void inOrder() {
        _inorder(root);
    }

    void _inorder(TreeNode* node) {
        if (node != nullptr) {
            _inorder(node->left);
            cout << node->data << " ";
            _inorder(node->right);
        }
    }

    void postOrder() {
        _postorder(root);
    }

    void _postorder(TreeNode* node) {
        if (node != nullptr) {
            _preorder(node->left);
            _preorder(node->right);
            cout << node->data << " ";
        }
    }

    TreeNode* search(int data) {
        return _search(root, data);
    }

    TreeNode* _search(TreeNode* node, int data) {
        return node == nullptr || node->data == data
            ? node
            : _search(data < node->data ? node->left : node->right, data);
    }

};


#endif //BINARYTREE_BINARYTREE_H
