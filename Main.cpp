#include "DBST.h"
#include <iostream>
using namespace std;

//The greater the value of c, the more "unbalanced" the tree may be

int main()
{
	Node *root = new Node(10, nullptr);
	DBST *D = new DBST(root, .75);
	D->Insert(4, D->root);
	D->Insert(5, D->root);
	D->Insert(2, D->root);
	D->Insert(1, D->root);
	D->Insert(4, D->root);
	D->Insert(54, D->root);
	D->Insert(24, D->root);
	D->Insert(14, D->root);
	D->Insert(44, D->root);
	D->Insert(54, D->root);
	D->Insert(24, D->root);
	D->Insert(14, D->root);
	//cout << D->root->rightNode->leftNode->value;
	cout << D->root->value << "\n";
	D->root->PrintD();
	return 0;
}


