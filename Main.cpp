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

// useless: 
//template <typename T>
//TreeNode<T>* rebalanceTree(TreeNode<T>* node) {
//    int nodeCount = getSubtreeSize(node) - 1;
//    int median = nodeCount / 2;
//    // preallocate listy to have same slots as nodeCount with 0 for placeholder
//    vector<T> listy(nodeCount, 0);
//    int idx = 0;
//    makeArrOfBST(node, listy, idx);
//
//    // root node is median value of list
//    TreeNode<T>* balancedTreeRoot = createNode<T>(median);
//
//    // erase median
//    listy.erase(listy.begin() + median);
//        
//    bool lol2 = true;
//    // good loop to avoid going out of range when you have no clue what's going on
//    for (auto& val : listy) {
//        insertNode(balancedTreeRoot, val, 1.0f, lol2);
//    }
//    return balancedTreeRoot;
//}

template <typename T>
TreeNode<T>* buildBalancedBSTFromSortedArray(vector<T>& arr, int start, int end) {
    if (start > end) 
        return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode<T>* root = new TreeNode<T>(arr[mid]);

    root->left = buildBalancedBSTFromSortedArray(arr, start, mid - 1);
    root->right = buildBalancedBSTFromSortedArray(arr, mid + 1, end);

    return root;
}

template <typename T>
TreeNode<T>* insertNode(TreeNode<T>* _root, T _data, float _c, bool& _isBalanced) {
    // base case:
    if (_root == nullptr) {
        return createNode(_data);
    }

    int treeSize = getSubtreeSize(_root);
    if (getSubtreeSize(_root->left) > int(_c * treeSize) || getSubtreeSize(_root->right) > int(_c * treeSize))
        _isBalanced = false;

    // Special rule: Duplicates are treated as less than than _root, and therefore put as left node
    if (_data <= _root->data) {
        _root->left = insertNode(_root->left, _data, _c, _isBalanced);
    }
    else if (_data > _root->data) {
        _root->right = insertNode(_root->right, _data, _c, _isBalanced);
    }

    // rebalance when we propagate back upwards, make a function of this garbage later (maybe lambda?)
    if (!_isBalanced) {
        int nodeCount = getSubtreeSize(_root);
        vector<T> arr(nodeCount, 0);
        int idx = 0;
        makeArrOfBST(_root, arr, idx);
        return buildBalancedBSTFromSortedArray(arr, 0, nodeCount - 1);
    }

    return _root;
}

template <typename T>
void traverseInOrder(TreeNode<T>* _root, int level = 0) {
    if (_root != nullptr) {
        cout << "Level: " << level << " |";
        cout << getSubtreeSize(_root->left) << " <- left subtree size || right subtree size -> " << getSubtreeSize(_root->right) << endl;

        traverseInOrder(_root->left, level + 1);
        // Message To Grette: to print tree in-order: Uncomment this
        //cout << _root->data << " ";
        traverseInOrder(_root->right, level + 1);
    }
}

int main()
{
    // root node:
    TreeNode<int>* node = nullptr;
    // adjust c between 0.5 to 1
    float c = 0.5;
    bool isBalanced = true;

    node = insertNode(node, 45, c, isBalanced);
    node = insertNode(node, 30, c, isBalanced);
    node = insertNode(node, 40, c, isBalanced);
    node = insertNode(node, 65, c, isBalanced);
    node = insertNode(node, 25, c, isBalanced);
    node = insertNode(node, 85, c, isBalanced);
    node = insertNode(node, 32, c, isBalanced);
    node = insertNode(node, 62, c, isBalanced);
    node = insertNode(node, 63, c, isBalanced);
    node = insertNode(node, 64, c, isBalanced);
    node = insertNode(node, 65, c, isBalanced);

    traverseInOrder(node);
}



