//
// Created by Whoami on 2021/4/17.
//

#ifndef DATA_STRUCTURE_LAB_3_NODE_H
#define DATA_STRUCTURE_LAB_3_NODE_H


class Node {
public:
    Node *left; //A pointer to the left child node
    Node *right; //A pointer to the right child node
    int content; //An integer variable for the content

public:
    explicit Node(int content) {
        left = nullptr;
        right = nullptr;
        this->content = content;
    }

    ~Node() = default;

    Node* getLeft() const {
        return left;
    }

    Node* getRight() const {
        return this->right;
    }

    void setLeft(Node *node) {
        left = node;
    }

    void setRight(Node *node) {
        right = node;
    }

    void setData(int data) {
        this->content = data;
    }
    int getdata() const {
        return content;
    }
};


#endif //DATA_STRUCTURE_LAB_3_NODE_H
