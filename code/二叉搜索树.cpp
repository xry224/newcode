#include <iostream>
#include <string>
using namespace std;
string str;
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
	str += (root->val + '0');
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
	str += (root->val + '0');
	InOrder(root->rchild);
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
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		string seq1;
		string seq2;
		str = "";
		cin >> seq1;
		Node *root1 = NULL;
		//构造第一棵二叉排序树
		for (int i = 0; i < seq1.length(); i++)
		{
			root1 = Insert(root1, seq1[i] - '0');
		}
		PreOrder(root1);
		InOrder(root1);
		string res1 = str;   //第一棵二叉树的前序遍历结果与中序遍历结果
		while (n--)
		{
			str = "";
			cin >> seq2;
			Node *root2 = NULL;
			//构造后面的二叉排序树
			for (int i = 0; i < seq2.length(); i++)
			{
				root2 = Insert(root2, seq2[i] - '0');
			}
			PreOrder(root2);
			InOrder(root2);
			if (res1 == str)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}