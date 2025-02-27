#include "DBST.h"
#include <iostream>
using namespace std;

void DBST::Insert(int ins, Node *r)
{
	//Insert a node into the BST maintaining BST property
	//Find the place to insert ins
	if (ins < r->value)
	{
		if (r->leftNode == nullptr)
		{
			r->leftNode = new Node(ins, r);
			Rearrange(r);
		}
		else
		{
			Insert(ins, r->leftNode);
		}
	}
	else
	{
		if (r->rightNode == nullptr)
		{
			r->rightNode = new Node(ins, r);
			Rearrange(r);
		}
		else
		{
			Insert(ins, r->rightNode);
		}
	}
}

void DBST::Rearrange(Node *r)
{
	Node* oldNode = r;
	if (r->leftNode != nullptr && r->leftNode->NodeSize() > r->NodeSize() * c)
	{
		//Rotate clockwise
		oldNode = r->leftNode;
		r->leftNode = r->leftNode->rightNode;
		oldNode->parent = r->parent;
		r->parent = oldNode;
		oldNode->rightNode = r;
		Rearrange(r);
		exit;
	}
	else if (r->rightNode != nullptr && r->rightNode->NodeSize() > r->NodeSize() * c)
	{
		//Rotate counterclockwise
		oldNode = r->rightNode;
		r->rightNode = r->rightNode->leftNode;
		oldNode->parent = r->parent;
		r->parent = oldNode;
		oldNode->leftNode = r;
		Rearrange(r);
		exit;
	}
	if (oldNode->parent != nullptr)
	{
		Rearrange(oldNode->parent);
	}
	else
	{
		root = oldNode;
	}
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

void Node::PrintD()
{
	if (leftNode != nullptr)
	{
		leftNode->PrintD();
	}
	cout << value << " ";
	if (rightNode != nullptr)
	{
		rightNode->PrintD();
	}
}