#include <iostream>
#include <vector>
#include <random>

#include "DBST.h"
#include "GBST.h"


using namespace std;

DBST dbst;
TreeNode<int>* makeBigDynamicTree(int count) {
    TreeNode<int>* node = nullptr;

    float c = 0.5;
    bool isBalanced = true;

    for (int i = 0; i < count; i++) {
        int randomNum = rand() % 100;
        node = dbst.insertNode(node, randomNum, c, isBalanced);
    }

    return node;
}

GBST gbst;
GBSTTreeNode<int>* makeBigGenericTree(int count) {
    GBSTTreeNode<int>* node = nullptr;

    for (int i = 0; i < count; i++) {
        int randomNum = rand() % 100;
        node = gbst.insertNode(node, randomNum);
    }

    return node;
}

int main()
{

    TreeNode<int>* node = makeBigDynamicTree(1000);

    dbst.traverseInOrder(node);

    cout << node->data;

    cout << endl;

    //GBSTTreeNode<int>* node = makeBigGenericTree(1000);

    //gbst.traverseInOrder(node);

    //cout << node->data;

    //cout << endl;

    // hardcoded:
    // -----------------------------------------------------------------------------------------------------------------------------------------
    // Dynamic, self-balancing BST:
    //BST dbst;

    //// root node:
    //TreeNode<int>* node = nullptr;

    //// adjust c between 0.5 to 1
    //float c = 0.5;
    //bool isBalanced = true;

    //node = dbst.insertNode(node, 45, c, isBalanced);
    //node = dbst.insertNode(node, 30, c, isBalanced);
    //node = dbst.insertNode(node, 40, c, isBalanced);
    //node = dbst.insertNode(node, 65, c, isBalanced);
    //node = dbst.insertNode(node, 25, c, isBalanced);
    //node = dbst.insertNode(node, 85, c, isBalanced);
    //node = dbst.insertNode(node, 32, c, isBalanced);
    //node = dbst.insertNode(node, 62, c, isBalanced);
    //node = dbst.insertNode(node, 63, c, isBalanced);
    //node = dbst.insertNode(node, 64, c, isBalanced);
    //node = dbst.insertNode(node, 65, c, isBalanced);
    //node = dbst.insertNode(node, 67, c, isBalanced);

    //dbst.traverseInOrder(node);

    //cout << node->data;

    //cout << endl;
    //cout << endl;
    //cout << endl;
    // 

    // -----------------------------------------------------------------------------------------------------------------------------------------
    // Generic BST:
    //GBST gbst;

    //// root node:
    //GBSTTreeNode<int>* gnode = nullptr;

    //// adjust c between 0.5 to 1

    //gnode = gbst.insertNode(gnode, 45);
    //gnode = gbst.insertNode(gnode, 30);
    //gnode = gbst.insertNode(gnode, 40);
    //gnode = gbst.insertNode(gnode, 65);
    //gnode = gbst.insertNode(gnode, 25);
    //gnode = gbst.insertNode(gnode, 85);
    //gnode = gbst.insertNode(gnode, 32);
    //gnode = gbst.insertNode(gnode, 62);
    //gnode = gbst.insertNode(gnode, 63);
    //gnode = gbst.insertNode(gnode, 64);
    //gnode = gbst.insertNode(gnode, 65);
    //gnode = gbst.insertNode(gnode, 67);
    //gnode = gbst.insertNode(gnode, 68);

    //gbst.traverseInOrder(gnode);

    //cout << node->data;
}

