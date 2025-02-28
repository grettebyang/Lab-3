#include "DBST.h"
#include <iostream>
#include <random>
using namespace std;

DBST *CreateD(int n, float c)
{
	//Create a random BST of size n
	Node* root = new Node(rand() % 30);
	cout << "Initial Root: " << root->value << "\n";
	DBST *D = new DBST(root, c);
	for (int i = 0; i < n-1; i++)
	{
		int newVal = rand() % 30;
		cout << "Insert #" << i + 1 << ": " << newVal << "\n";
		D->Insert(newVal);
	}
	return D;
}

int main()
{
	srand(time(0));
	DBST* D = CreateD(20, .75);
	cout << "Final Root: " << D->root->value << "\n";
	D->PrintD();
	return 0;
}


