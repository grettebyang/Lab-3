#include <iostream>

using namespace std;

// Splitting based on predetermined subdivisions of the key range is called key
// space decomposition.In computer graphics, the technique is known as image
// space decomposition

// When a node is added into the right subtree of the right subtree, 
// if the tree gets out of balance, we do a single left rotation.

// If a node is added to the left subtree of the left subtree, 
// the AVL tree may get out of balance, we do a single right rotation.

// Let the newly inserted node be w
//
// Perform standard BST insert for w.
// Starting from w, travel up and find the first unbalanced node.Let z be the first unbalanced node,
// y be the child of z that comes on the path from w to z and x be the grandchild of z that comes on the path from w to z.
// Re - balance the tree by performing appropriate rotations on the subtree rooted with z.
// There can be 4 possible cases that need to be handled as x, y and z can be arranged in 4 ways.

// Following are the possible 4 arrangements:
// y is the left child of z and x is the left child of y(Left Left Case)
// y is the left child of z and x is the right child of y(Left Right Case)
// y is the right child of z and x is the right child of y(Right Right Case)
// y is the right child of z and x is the left child of y(Right Left Case)

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(T _data) {
        data = _data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

template <typename T>
int height(TreeNode<T>* tn) {
    if (tn == nullptr)
        return 0;
    return tn->height;
}

template <typename T>
int getBSTBalance(TreeNode<T>* tn) {
    if (tn == nullptr)
        return 0;
    return height(tn->left) - height(tn->right);
}

template <typename T>
TreeNode<T>* createNode(T _data) {
    return new TreeNode<T>(_data);
}

template <typename T>
TreeNode<T>* leftRotate(TreeNode<T>* _root) {
    TreeNode<T>* y = _root->right;
    TreeNode<T>* Temp = y->right;
    
    y->left = _root;
    _root->right = Temp;

    return y;
}

template <typename T>
TreeNode<T>* rightRotate(TreeNode<T>* _root) {
    TreeNode<T>* x = _root->left;
    TreeNode<T>* Temp = x->right;

    x->right = _root;
    _root->left = Temp;

    return x;
}

template <typename T>
TreeNode<T>* insertNode(TreeNode<T>* _root, T _data) {
    // base case:
    if (_root == nullptr) {
        return createNode(_data);
    }

    if (_data < _root->data)
        _root->left = insertNode(_root->left, _data);
    else if (_data > _root->data)
        _root->right = insertNode(_root->right, _data);
    else
        return _root;

    int b = getBSTBalance(_root);

    if (b > 1 && _data < _root->left->data)
        return rightRotate(_root);

    if (b < -1 && _data > _root->right->data)
        return leftRotate(_root);
    
    if (b > 1 && _data > _root->left->data) {
        _root->left = leftRotate(_root->left);
        return rightRotate(_root);
    }
    if (b < -1 && _data < _root->right->data) {
        _root->right = rightRotate(_root->right);
        return leftRotate(_root);
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
    TreeNode<int>* node = createNode<int>(60);

    insertNode(node, 20);
    insertNode(node, 30);
    insertNode(node, 40);
    insertNode(node, 50);
    insertNode(node, 25);
    insertNode(node, 45);
    insertNode(node, 35);
    insertNode(node, 5);
    insertNode(node, 15);

    traverseInOrder(node);

    delete node;
}
