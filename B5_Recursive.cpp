/*Recursive*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};
class tree
{
public:
	node *create()
	{
		node *p;
		int x;
		p = new node;
		cout << "ENTER DATA-: ";
		cin >> x;
		p->data = x;
		if (x == -1)
		{
			return NULL;
		}
		cout << "ENTER LEFT CHILD OF " << x << "- ";
		p->left = create();
		cout << "ENTER RIGHT CHILD OF " << x << "- ";
		p->right = create();
		return p;
	}
	void preorder(node *t)
	{
		if (t != NULL)
		{
			cout << t->data;
			preorder(t->left);
			preorder(t->right);
		}
	}
	void postorder(node *t)
	{
		if (t != NULL)
		{
			postorder(t->left);
			postorder(t->right);
			cout << t->data;
		}
	}
	void inorder(node *t)
	{
		if (t != NULL)
		{
			inorder(t->left);
			cout << t->data;
			inorder(t->right);
		}
	}
};
int main()
{
	tree t;
	node *root;
	root = t.create();
	cout << "PREORDER SEQUENCE-:";
	t.preorder(root);
	cout << endl;
	cout << "POSTORDER SEQUENCE-:";
	t.postorder(root);
	cout << endl;
	cout << "INORDER SEQUENCE-:";
	t.inorder(root);
	return 0;
}
