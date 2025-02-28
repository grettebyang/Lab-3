#pragma once
#include <vector>
using namespace std;

struct Node
{
	int value;
	//Node* parent;
	Node* leftNode;
	Node* rightNode;

	Node(int data)
	{
		this->value = data;
		//this->parent = parent;
		this->leftNode = nullptr;
		this->rightNode = nullptr;
	}

	int NodeSize();
	void MakeBSTArray(vector<int>& listy, int& index);
	Node* MakeBalancedBST(vector<int>& arr, int start, int end);
};

struct DBST
{
	float c;
	Node *root;

	DBST(Node* root, float c)
	{
		this->root = root;
		this->c = c;
	}

	void Insert(int ins);
	void InsertWithin(int ins, Node* r);
	Node* Rearrange(Node *r);
	void PrintD();
};
