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
Node* search_node(Node*root,int val){
    if(!root) return nullptr;
    if(root->val==val) return root;
    else if(root->val<val){
        return search_node(root->right,val);
    }
    else{
        return search_node(root->left,val);
    }
}
Node* max_node(Node*root){
    if(!root) return root;
    if(!root->right) return root;
    return max_node(root->right);
}
Node* min_node(Node*root){
    if(!root) return root;
    if(!root->left) return root;
    return min_node(root->left);
}
void inorder_successor(Node*root,Node*&succ,int val){
    
    if(!root) return;
    if(root->val>val) {
        succ=root;
        inorder_successor(root->left,succ,val);
    }
    else  inorder_successor(root->right,succ,val);
}
void inorder_predessor(Node*root,Node*&pre,int val){
    if(!root) return;
    if(root->val<val){
        pre=root;
        inorder_predessor(root->right,pre,val);

    }
    else inorder_predessor(root->left,pre,val);
}
int main() {
    vector<int>v={10,9,2,15,12,18,17,1,7,3};
    Node*root=BST(v);
    inorder(root);
    cout<<endl;
    Node*n=search_node(root,15);
    if(n){
        
        cout<<"Found: "<<n->val<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    n=max_node(root);
    cout<<"Max Node val: "<<n->val<<endl;
    n=min_node(root);
    cout<<"Min Node val: "<<n->val<<endl;
    Node*succ=nullptr;
    inorder_successor(root,succ,12);
    cout<<"Inorder Successor of 12: "<<succ->val<<endl;
    Node*pre=nullptr;
    inorder_predessor(root,pre,7);
    cout<<"Inorder Predessor of 7: "<<pre->val;
    return 0;
}
