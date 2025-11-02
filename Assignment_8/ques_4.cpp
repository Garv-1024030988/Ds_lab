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
void valid_BST(Node*root,vector<int>&v){
    if(!root) return;
    valid_BST(root->left,v);
    v.push_back(root->val);
    valid_BST(root->right,v);
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
bool check_BST(Node*root){
    vector<int>v;
    valid_BST(root,v);
    
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]) return false;
    }
    return true;
}

int main() {
    vector<int>v={5,9,2,4,3,0,10,8};
    Node*root=BST(v);
    inorder(root);
    cout<<endl;
    
    if(check_BST(root)){
        cout<<"Valid BST"<<endl;
    }
    else{
        cout<<"Invalid BST"<<endl;
    }

    return 0;
}
