#include "DBST.h"
#include <iostream>
using namespace std;

int main()
{
	Node *root = new Node(10, nullptr);
	DBST *D = new DBST(root, .75);
	D->Insert(4, D->root);
	D->Insert(5, D->root);
	D->Insert(2, D->root);
	//D->Insert(1, D->root);
	//cout << D->root->rightNode->leftNode->value;
	cout << D->root->value << "\n";
	D->root->PrintD();
	return 0;
}


