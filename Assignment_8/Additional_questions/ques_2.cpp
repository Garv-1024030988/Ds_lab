#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void displayTree(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    displayTree(root->left);
    displayTree(root->right);
}
int levels(Node*root){
    if(root==nullptr){
        return 0;
    }
    return 1+max(levels(root->left),levels(root->right));
}
int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    Node* h=new Node(10);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    g->right=h;
    displayTree(a);
    cout << endl;
    cout<<"Levels: "<<levels(a)<<endl;
    return 0;
}
