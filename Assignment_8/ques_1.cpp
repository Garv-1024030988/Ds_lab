#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        left=right=nullptr;
    }
};

Node* insert_BST(Node*root,int val){
    if(!root) return new Node(val);
    if(root->val<val){
        root->right=insert_BST(root->right,val);
    }
    else{
        root->left=insert_BST(root->left,val);
    }
    return root;
}

Node* BST(vector<int>&v){
    if(!v.size()) return nullptr;
    Node*root=new Node(v[0]);
    for(int i=1;i<v.size();i++){
        insert_BST(root,v[i]);
    }
    return root;

}
void inorder(Node*root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void preorder(Node*root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root){
    if(!root) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main() {
    vector<int>v={5,9,2,4,3,0,10,8};
    Node*root=BST(v);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}
