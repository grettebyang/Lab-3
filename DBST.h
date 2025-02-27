#pragma once

struct Node
{
	int value;
	Node* parent;
	Node* leftNode;
	Node* rightNode;

	Node(int data, Node* parent)
	{
		this->value = data;
		this->parent = parent;
		this->leftNode = nullptr;
		this->rightNode = nullptr;
	}

	int NodeSize();
	void PrintD();
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

	void Insert(int ins, Node *r);
	void Rearrange(Node *r);
};
