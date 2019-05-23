#include <iostream>
#include <string>
using namespace std;
string preorder;
int index;
int len;
class Node
{
public:
	char val;
	Node *lchild, *rchild;
	Node(char ini)
	{
		val = ini;
		lchild = rchild = NULL;
	}
	Node()
	{
		val = '#';
		lchild = rchild = NULL;
	}
};
Node *Build()
{
	if (len == index)
	{
		return NULL;
	}
	char val = preorder[index++];
	if (val == '#')
	{
		return NULL;
	}
	Node *root = new Node(val);
	root->lchild = Build();
	root->rchild = Build();
	return root;
}
void InOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->lchild);
	cout << root->val << " ";
	InOrder(root->rchild);
	delete root;
}
int main()
{
	while (cin >> preorder)
	{
		len = preorder.length();
		index = 0;
		Node *root = Build();
		InOrder(root);
		cout << endl;
	}
	return 0;
}