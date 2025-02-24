#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T _data) {
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
TreeNode<T>* createNode(T _data) {
    return new TreeNode<T>(_data);
}

template <typename T>
TreeNode<T>* insertNode(TreeNode<T>* _root, T _data) {
    if (_root == nullptr) {
        return createNode(_data);
    }
    if (_data < _root->data) {
        _root->left = insertNode(_root->left, _data);
    }
    else if (_data > _root->data) {
        _root->right = insertNode(_root->left, _data);
    }

    return _root;
}

// always print left node first
template <typename T>
void traverseInOrder(TreeNode<T>* _root) {
    if (_root != nullptr) {
        traverseInOrder(_root->left);
        cout << _root->data << " ";
        traverseInOrder(_root->right);
    }
}

int main()
{
    TreeNode<char>* node = createNode<char>('C');
    node->data = 'F';
    cout << node->data << endl;

    insertNode(node, 'F');
    insertNode(node, 'C');
    insertNode(node, 'B');
    insertNode(node, 'D');
    insertNode(node, 'A');

    traverseInOrder(node);

    delete node;

}
