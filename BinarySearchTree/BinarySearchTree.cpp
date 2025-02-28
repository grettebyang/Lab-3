#include <iostream>
#include <vector>
#include <random>

#include "DBST.h"
#include "GBST.h"

#include <ctime>

using namespace std;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(0, 999);

// Dynamic BST with lower constant
DBST dbst;
TreeNode<int>* makeBigDynamicTree(int _count, float _c) {
    TreeNode<int>* node = nullptr;

    bool isBalanced = true;
    for (int i = 0; i < _count; i++) {
        int randomNum = dist(gen);
        node = dbst.insertNode(node, randomNum, _c, isBalanced);
    }
    return node;
}

GBST gbst;
GBSTTreeNode<int>* makeBigGenericTree(int count) {
    GBSTTreeNode<int>* node = nullptr;

    for (int i = 0; i < count; i++) {
        int randomNum = dist(gen);
        node = gbst.insertNode(node, randomNum);
    }
    return node;
}

// Dynamic BST with higher constant
DBST ubdst;
TreeNode<int>* makeBigDynamicTreeUnbalanced(int _count, float _c) {
    TreeNode<int>* node = nullptr;
    bool isBalanced = true;

    for (int i = 0; i < _count; i++) {
        int randomNum = dist(gen);
        node = ubdst.insertNode(node, randomNum, _c, isBalanced);
    }
    return node;
}

int main()
{
    TreeNode<int>* node1 = makeBigDynamicTree(1000, 0.5f);
    dbst.countChildren(node1);
    //dbst.traverseInOrder(node1);
    cout << node1->data;
    cout << endl;

    //GBSTTreeNode<int>* node2 = makeBigGenericTree(1000);
    ////gbst.traverseInOrder(node2);
    //gbst.countChildren(node2);
    //cout << node2->data;
    //cout << endl;

    //TreeNode<int>* node3 = makeBigDynamicTreeUnbalanced(1000, 1.0f);
    ////ubdst.traverseInOrder(node3);
    //ubdst.countChildren(node3);
    //cout << node3->data;
    //cout << endl;
}
