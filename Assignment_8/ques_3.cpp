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
int levels(Node*root){
    if(!root) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}
int min_depth(Node*root){
    if(!root) return 0;
    return 1 +min(min_depth(root->left),min_depth(root->right));
}
Node* inorder_predessor(Node*root){
    root=root->left;
    while(root->right){
        root=root->right;
    }
    return root;
}

Node* delete_Node(Node*root,int val){
    if(!root) return nullptr;
    if(root->val==val){
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        else if(!root->left || !root->right){
            if(root->left) return root->left;
            else return root->right;
        }
        else{
            Node*pre=inorder_predessor(root);
            root->val=pre->val;
            root->left=delete_Node(root->left,pre->val);
        }
    }
    else if(root->val<val){
       root->right= delete_Node(root->right,val);
    }
    else{
        root->left=delete_Node(root->left,val);
    }
    return root;
}
int main() {
    vector<int>v={5,9,2,4,3,0,10,8,13,15};
    Node*root=BST(v);
    inorder(root);
    cout<<endl;
    cout<<"Levels: "<<levels(root)<<endl;
    cout<<"Min depth: "<<min_depth(root)<<endl;
    root=delete_Node(root,9);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;

    return 0;
}
