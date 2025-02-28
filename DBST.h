#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct GBSTTreeNode {
    T data;
    GBSTTreeNode* left;
    GBSTTreeNode* right;

    GBSTTreeNode(T _data) {
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};


//template <typename T>
//static GBSTTreeNode<int>* gbtn = nullptr;
struct GBST {
    //total number of nodes, includes root node
    template <typename T>
    int getSubtreeSize(GBSTTreeNode<T>* root) {
        if (root == nullptr)
            return 0;
        return getSubtreeSize(root->left) + getSubtreeSize(root->right) + 1;
    }

    template <typename T>
    GBSTTreeNode<T>* createNode(T _data) {
        return new GBSTTreeNode<T>(_data);
    }

    template <typename T>
    GBSTTreeNode<T>* insertNode(GBSTTreeNode<T>* _root, T _data) {
        // base case:
        if (_root == nullptr) {
            return createNode(_data);
        }

        // Special rule: Duplicates are treated as less than than _root, and therefore put as left node
        if (_data <= _root->data) {
            _root->left = insertNode(_root->left, _data);
        }
        else if (_data > _root->data) {
            _root->right = insertNode(_root->right, _data);
        }

        return _root;
    }

    template <typename T>
    void traverseInOrder(GBSTTreeNode<T>* _root, int level = 0) {
        if (_root != nullptr) {
            cout << "Level: " << level << " |";
            cout << getSubtreeSize(_root->left) << " <- left subtree size || right subtree size -> " << getSubtreeSize(_root->right) << endl;

            traverseInOrder(_root->left, level + 1);
            // Message To Grette: to print tree in-order: Uncomment this
            //cout << _root->data << " ";
            traverseInOrder(_root->right, level + 1);
        }
    }
};
