#include <iostream>
#include <vector>

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

// total number of nodes, includes root node
template <typename T>
int getSubtreeSize(TreeNode<T>* root) {
    if (!root)
        return 0;
    return getSubtreeSize(root->left) + getSubtreeSize(root->right) + 1;
}

template <typename T>
TreeNode<T>* createNode(T _data) {
    return new TreeNode<T>(_data);
}

template <typename T>
void makeArrOfBST(TreeNode<T>* _root, std::vector<T>& listy, int& index) {
    if (_root == nullptr)
        return;

    makeArrOfBST(_root->left, listy, index);
    if (index >= listy.size())
        return;
    listy[index++] = _root->data;
    makeArrOfBST(_root->right, listy, index);
}

template <typename T>
void getArrFromBST(TreeNode<T>* _root, std::vector<T>& listy, int& index) {
    if (_root == nullptr)
        return;

    makeArrOfBST(_root->left, listy, index);
    if (index >= listy.size())
        return;
    listy[index++] = _root->data;
    makeArrOfBST(_root->right, listy, index);
}

template <typename T>
TreeNode<T>* rebalanceTree(TreeNode<T>* node) {
    int nodeCount = getSubtreeSize(node) - 1;
    vector<T> listy(nodeCount, 0);
    int index = 0;
    makeArrOfBST(node, listy, index);

    // root node is median value (rounded down)
    TreeNode<T>* balancedTreeNode = createNode<T>(listy[floor(nodeCount / 2)]);

    for (int i = 0; i < listy.size() - 1; i++) {
        insertNode(balancedTreeNode, listy[i], 1, true);
    }
    return balancedTreeNode;
}

template <typename T>
TreeNode<T>* insertNode(TreeNode<T>* _root, T _data, float _c, bool _isBalanced) {
    // base case:
    if (_root == nullptr) {
        return createNode(_data);
    }

    int treeSize = floor(getSubtreeSize(_root));
    if (getSubtreeSize(_root->left) < _c * treeSize || getSubtreeSize(_root->right) < _c * treeSize)
        _isBalanced = false;

    // Special rule: Duplicates are treated as less than than _root, and therefore put as left node
    if (_data <= _root->data) {
        //cout << "Insert l " << endl;
        _root->left = insertNode(_root->left, _data, _c, _isBalanced);
    }
    else if (_data > _root->data) {
        //cout << "Insert r " << endl;
        _root->right = insertNode(_root->right, _data, _c, _isBalanced);
    }

    if (!_isBalanced) {
        return rebalanceTree(_root);
    }

    return _root;
}

template <typename T>
void traverseInOrder(TreeNode<T>* _root) {
    // THese 2 just for demonstration purposes, remove later

    if (_root != nullptr) {
        traverseInOrder(_root->left);
        //cout << _root->data << " ";
        cout << getSubtreeSize(_root->left) << " <- left subtree size || right subtree size -> " << getSubtreeSize(_root->right) << endl;
        traverseInOrder(_root->right);
    }
}

int main()
{
    TreeNode<int>* node = createNode<int>(60);

    float c = 1;
    insertNode(node, 45, c, true);
    insertNode(node, 30, c, true);
    insertNode(node, 40, c, true);
    insertNode(node, 65, c, true);
    insertNode(node, 25, c, true);
    insertNode(node, 85, c, true);
    insertNode(node, 32, c, true);
    insertNode(node, 62, c, true);
    insertNode(node, 63, c, true);
    insertNode(node, 64, c, true);
    insertNode(node, 65, c, true);

    // exclude root with -1
    int nodeCount = getSubtreeSize(node) - 1;

    // first param is hardcoded as number of nodes
    // This code should make the BST into a balanced one:

    vector<int> listy(7, 0);
    int index = 0;
    makeArrOfBST(node, listy, index);

    // root node is median value (rounded down)
    TreeNode<int>* reBalancedTreeNode = createNode<int>(listy[floor(7 / 2)]);

    for (int i = 0; i < listy.size() - 1; i++) {
        insertNode(reBalancedTreeNode, listy[i], 0, true);
    }

    traverseInOrder(reBalancedTreeNode);
}
