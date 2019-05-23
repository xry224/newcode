#include <iostream>
using namespace std;
int father;
class Node
{
public:
	int val;
	Node *lchild, *rchild;
	Node(int val)
	{
		this->val = val;
		lchild = rchild = NULL;
	}
}; 
Node* Insert(Node *root, int val)
{
	if (root == NULL)
	{
		root = new Node(val);
		return root;
	}
	if (val < root->val) //比根节点小，插入左子树
	{
		father = root->val;
		root->lchild = Insert(root->lchild, val);
	}
	else if (val > root->val) //比根节点大，插入右子树
	{
		father = root->val;
		root->rchild = Insert(root->rchild, val);
	}
	return root;
}
int main()
{
	int n;
	while (cin >> n)
	{
		Node *root = NULL;
		father = -1;
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			root = Insert(root, t);
			cout << father << endl;
		}
	}
	return 0;
}