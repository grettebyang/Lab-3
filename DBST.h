#pragma once

struct DBST
{
	int value;
	int c;
	DBST *parent;
	DBST *leftNode;
	DBST *rightNode;

	DBST(int data, DBST* parent, int c)
	{
		this->value = data;
		this->c = c;
		this->leftNode = nullptr;
		this->rightNode = nullptr;
		this->parent = parent;
	}

	void Insert(int ins);
	void Rearrange();
	int NodeSize();
};