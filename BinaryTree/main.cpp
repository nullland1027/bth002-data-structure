#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree tree;
    tree.createTree();
    cout << tree.root->data << tree.root->left->data
         << tree.root->right->data << tree.root->right->left->data
         << tree.root->right->right->data << endl;
//    cout << "inorder"<<endl;
//    tree.inOrder();
//    cout << "preorder"<<endl;
//    tree.preOrder();
//    cout<<"postorder"<<endl;
//    tree.postOrder();
    cout << tree.search(1);

    return 0;
}
