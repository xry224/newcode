/*
输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
输入描述：
输入第一行包括一个整数n(1<=n<=100)。
接下来的一行包括n个整数。
输出描述：
可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
每种遍历结果输出一行。每行最后一个数据之后有一个空格。

输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。
*/
//二叉排序树，左子树节点值必定小于等于其根节点，右子树节点值必定大于等于其根节点
//相等的情况下，视具体情况插入或者忽略
/*
    4
   / \
  2   6
 / \
1  3
*/
#include <iostream>
using namespace std;
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
void PreOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->val << " ";
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void InOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->lchild);
	cout << root->val << " ";
	InOrder(root->rchild);
}
void PostOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->val << " ";
	delete root;
}

Node* Insert(Node *root, int val)
{
	if (root == NULL)
	{
		root = new Node(val);
		return root;
	}
	if (val < root->val) //比根节点小，插入左子树
	{
		root->lchild = Insert(root->lchild, val);
	}
	else if (val > root->val) //比根节点大，插入右子树
	{
		root->rchild = Insert(root->rchild, val);
	}
	/*else if (val == root->val)  //相等直接忽略
	{
		return NULL;
	}*/
	return root;
}
void Test(Node *root)
{
	root->lchild = new Node(2);
	root->rchild = new Node(3);
}
int main()
{
	int n;
	while (cin >> n)
	{
		int t;
		Node *root = NULL;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			root = Insert(root, t);
		}
		PreOrder(root);
		cout << endl;
		InOrder(root);
		cout << endl;
	    PostOrder(root);
		cout << endl;
	}
	return 0;
}