#include "DBST.h"
using namespace std;

void DBST::Insert(int ins)
{
	//Insert a node into the BST maintaining BST property
	//Find the place to insert ins
	if (ins < value)
	{
		if (leftNode == nullptr)
		{
			leftNode = new DBST(ins, this, c);
			Rearrange();
		}
		else
		{
			leftNode->Insert(ins);
		}
	}
	else
	{
		if (rightNode == nullptr)
		{
			rightNode = new DBST(ins, this, c);
			Rearrange();
		}
		else
		{
			rightNode->Insert(ins);
		}
	}
}

void DBST::Rearrange()
{
	if (leftNode->NodeSize() > NodeSize() * c)
	{
		//Rotate clockwise
		DBST* oldLeftNode = leftNode;
		leftNode = leftNode->rightNode;
		oldLeftNode->parent = parent;
		parent = oldLeftNode;
		oldLeftNode->rightNode = this;
	}
	else if (rightNode->NodeSize() > NodeSize() * c)
	{
		//Rotate counterclockwise
		DBST* oldRightNode = rightNode;
		rightNode = rightNode->leftNode;
		oldRightNode->parent = parent;
		parent = oldRightNode;
		oldRightNode->leftNode = this;
	}
	if (parent != nullptr)
	{
		parent->Rearrange();
	}
}

int DBST::NodeSize()
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