#include "DBST.h"
#include <iostream>
#include <vector>
using namespace std;

void DBST::Insert(int ins)
{
	//Insert a node into the BST maintaining BST property
	//Find the place to insert ins
	if (ins < root->value)
	{
		if (root->leftNode == nullptr)
		{
			root->leftNode = new Node(ins);
		}
		else
		{
			InsertWithin(ins, root->leftNode);
		}
	}
	else
	{
		if (root->rightNode == nullptr)
		{
			root->rightNode = new Node(ins);
		}
		else
		{
			InsertWithin(ins, root->rightNode);
		}
	}
	root = Rearrange(root);
}

void DBST::InsertWithin(int ins, Node* r)
{
	//Insert a node into the BST maintaining BST property
	//Find the place to insert ins
	if (ins < r->value)
	{
		if (r->leftNode == nullptr)
		{
			r->leftNode = new Node(ins);
		}
		else
		{
			InsertWithin(ins, r->leftNode);
		}
	}
	else
	{
		if (r->rightNode == nullptr)
		{
			r->rightNode = new Node(ins);
		}
		else
		{
			InsertWithin(ins, r->rightNode);
		}
	}
	r = Rearrange(r);
}

Node* DBST::Rearrange(Node *r)
{
	if ((r->leftNode != nullptr && r->leftNode->NodeSize() > r->NodeSize() * c) || (r->rightNode != nullptr && r->rightNode->NodeSize() > r->NodeSize() * c))
	{
		cout << "Rearrange " << r->value << "\n";
		int nodeCount = r->NodeSize();
		vector<int> arr(nodeCount, 0);
		int idx = 0;
		r->MakeBSTArray(arr, idx);
		Node* newRoot = r->MakeBalancedBST(arr, 0, nodeCount - 1);
		cout << "New Root: " << newRoot->value << "\n";
		return newRoot;
	}
	return r;
}

int Node::NodeSize()
{
	//returns the length of the tree from that node
	int nodeCount = 1;
	if (leftNode != nullptr)
	{
		nodeCount += leftNode->NodeSize();
	}
	if (rightNode != nullptr)
	{
		nodeCount += rightNode->NodeSize();
	}
	return nodeCount;
}

void DBST::PrintD()
{
	int nodeCount = root->NodeSize();
	vector<int> arr(nodeCount, 0);
	int idx = 0;
	root->MakeBSTArray(arr, idx);
	for (int i = 0; i < nodeCount; i++)
	{
		cout << arr[i] << " ";
	}
}

void Node::MakeBSTArray(vector<int>& listy, int& index)
{
	if (leftNode != nullptr)
	{
		leftNode->MakeBSTArray(listy, index);
	}
	if (index >= listy.size())
		return;
	listy[index++] = value;
	if (rightNode != nullptr)
	{
		rightNode->MakeBSTArray(listy, index);
	}
}

Node* Node::MakeBalancedBST(vector<int>& arr, int start, int end)
{
	if (start > end)
		return nullptr;

	int mid = start + (end - start) / 2;
	Node* root = new Node(arr[mid]);

	root->leftNode = MakeBalancedBST(arr, start, mid - 1);
	root->rightNode = MakeBalancedBST(arr, mid + 1, end);

	return root;
}