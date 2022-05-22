//NON RECURSIVE
#include <iostream>
#include <stack>
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
		node *p = new node;
		int x;
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
	void preorder(node *root)
	{
		if (root == NULL)
		{
			return;
		}
		stack<node *> stack;
		stack.push(root);
		while (!stack.empty())
		{
			node *current = stack.top();
			stack.pop();
			cout << current->data << " ";
			if (current->right)
			{
				stack.push(current->right);
			}
			if (current->left)
			{
				stack.push(current->left);
			}
		}
	}
	void postorder(node *root)
	{
		stack<node *> stk;
		stk.push(root);
		stack<int> out;
		while (!stk.empty())
		{
			node *current = stk.top();
			stk.pop();
			out.push(current->data);
			if (current->left)
			{
				stk.push(current->left);
			}
			if (current->right)
			{
				stk.push(current->right);
			}
		}
		while (!out.empty())
		{
			cout << out.top() << " ";
			out.pop();
		}
	}
	void inorder(node *root)
	{
		stack<node *> stack;
		node *current = root;
		while (!stack.empty() || current != NULL)
		{
			if (current != NULL)
			{
				stack.push(current);
				current = current->left;
			}
			else
			{
				current = stack.top();
				stack.pop();
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
};
int main()
{
	tree t;
	node *root;
	root = t.create();
	cout << "PREORDER SEQUENCE-: ";
	t.preorder(root);
	cout << endl;
	cout << "POSTORDER SEQUENCE-: ";
	t.postorder(root);
	cout << endl;
	cout << "INORDER SEQUENCE-: ";
	t.inorder(root);
	return 0;
}
