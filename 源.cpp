#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef struct node {
	char value;
	node *lchild,*rchild;

}BTreeNode,*BTree;

void createTree(BTree &T)//以先序创建二叉树
{
	char temp;
	cin >> temp;
	if (temp == '#')
	{
		T = NULL;
	}
	else {
		T = (BTreeNode *)malloc(sizeof(BTreeNode));
		T->value = temp;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}
void preOrder(BTree T)
{
	if (T != NULL)
	{
		cout << T->value << " ";
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void inOrder(BTree T)
{
	if (T != NULL)
	{
		inOrder(T->lchild);
		cout << T->value << " ";
		inOrder(T->rchild);
	}
}
void postOrder(BTree T)
{
	if (T != NULL)
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		cout << T->value << " ";
	}
}
void preOrderWithoutcallback(BTree T)
{
	stack<BTree> S;
	BTree p = T;
	while (p || !S.empty())
	{
		if (p)
		{
			cout << p->value << " ";
			S.push(p);
			p = p->lchild;
		}
		else
		{
			p = S.top();
			S.pop();
			p = p->rchild;
		}
	}

}
void inOrderWithoutcallback(BTree T)
{
	stack<BTree> S;
	BTree p = T;
	while (p || !S.empty())
	{
		if (p)
		{
			S.push(p);
			p = p->lchild;
		}
		else
		{
			p = S.top();
			S.pop();
			cout << p->value << " ";
			p = p->rchild;
				
		}
	}
}
void postOrderWithoutcallback(BTree T)
{
	stack<BTree> S;
	BTree p = T;
	S.push(p);
	S.push(p);
	while (!S.empty())
	{
		p = S.top();
		S.pop();
		if (!S.empty() && p == S.top())
		{
			if (p->rchild != NULL)
			{
				S.push(p->rchild);
				S.push(p->rchild);
			}
			if (p->lchild != NULL)
			{
				S.push(p->lchild);
				S.push(p->lchild);
			}
		}
		else {
			cout << p->value << " ";
		}
	}
}
void levelOrder(BTree T)
{
	queue<BTree> Q;
	BTree P;
	Q.push(T);
	while(!Q.empty())
	{
		P = Q.front();
		Q.pop();
		cout << P->value << " ";
		if (P->lchild != NULL)
		{
			Q.push(P->lchild);
		}
		if (P->rchild != NULL)
		{
			Q.push(P->rchild);
		}
	}
}
int main()
{
	BTree T;
	cout << "create Tree: " << endl;
	createTree(T);
	cout << "preOrder : " << endl;
	preOrder(T);
	cout << endl;
	cout << "inOrder : " << endl;
	inOrder(T);
	cout << endl;
	cout << "postOrder :" << endl;
	postOrder(T);
	cout << endl;
	cout << "preOrder without callback :" << endl;
	preOrderWithoutcallback(T);
	cout << endl;
	cout << "inOrder without callback :" << endl;
	inOrderWithoutcallback(T);
	cout << endl;
	cout << "postOrder without callback :" << endl;
	postOrderWithoutcallback(T);
	cout << endl;
	cout << "LevelOrder :" << endl;
	levelOrder(T);
	cout << endl;
	system("pause");
	return 0;
}