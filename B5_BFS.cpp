//BFS
#include <iostream>
#include <queue>
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
 void levelorder(node *root)
 {
 if (root == NULL)
 {
 return;
 }
 queue<node *> q;
 q.push(root);
 while (q.empty() == false)
 {
 node *node = q.front();
 cout << node->data << " ";
 q.pop();
 if (node->left != NULL)
 {
 q.push(node->left);
 }
 if (node->right != NULL)
 {
 q.push(node->right);
 }
 }
 }
};
int main()
{
 tree t;
 node *root;
 root = t.create();
 t.levelorder(root);
 return 0;
}