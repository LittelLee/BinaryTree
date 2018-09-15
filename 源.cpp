#include<iostream>
#include<stack>
using namespace std;
typedef struct node {
	char value;
	node *lchild,*rchild;

}BTreeNode,*BTree;

void createTree(BTree &T)
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
	system("pause");
	return 0;
}