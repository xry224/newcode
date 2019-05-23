/*
根据前序遍历与中序遍历重建二叉树：
例如：前序XDAGFE，中序ADGXFE
前序遍历首个节点X为根节点，中序遍历中，根节点将结果分为两部分ADG X FE分别为该节点的左子树与右子树。可得知该节点
左右子树节点个数，前序遍历该节点之后的结果先是其左子树然后是其右子树，则可以得到其左子树前序遍历DAG，中序遍历ADG，
右子树前序遍历FE，中序遍历FE，对新子树按照同样方法处理
递归分治
*/
#include <iostream>
#include <string>
using namespace std;
string preorder, minorder;    //前序遍历与中序遍历结果
int prelen, midlen;
class Node
{
public :
	char val;
	Node *lchild, *rchild;
	Node(char ini)
	{
		val = ini;
		lchild = NULL;
		rchild = NULL;
	}
	Node()
	{
		val = ' ';
		lchild = NULL;
		rchild = NULL;
	}
};
void PostOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->val;
	delete root;   //遍历完该节点与其子节点后，删除该节点
}
//递归分治
Node* Build(int pres, int pree, int mids, int mide)   //pres与pree定义当前前序结果，mids与mide为当前中序结果
{
	char val = preorder[pres];
	Node *root = new Node(val);
	int index = minorder.find(val);
	if (mids != index) //左子树不为空
	{
		int len = index - mids;  //计算子树长度
		root->lchild = Build(pres + 1, len + pres, mids, index - 1);
	}
	if (mide != index) //右子树不为空
	{
		int len = mide - index;
		root->rchild = Build(pree + 1 - len, pree, index + 1, mide);
	}

	return root;
}
int main()
{
	while (cin >> preorder >> minorder)
	{
		prelen = preorder.length();
		midlen = minorder.length();
		Node *root = Build(0, prelen - 1, 0, midlen - 1);
		PostOrder(root);
		cout << endl;
	}
}