class Solution {
public:
    TreeNode* helper(vector<int>&in,vector<int>&post,unordered_map<int,int>&mp,int inS,int inE,int postS,int postE){
        if(postS > postE || inS > inE) return nullptr;
        
        int r=post[postE];
        TreeNode*root=new TreeNode(r);
        int i=mp[r];
        int x=i-inS;
        root->left=helper(in,post,mp,inS,i-1,postS,postS+x-1);
        root->right=helper(in,post,mp,i+1,inE,postS+x,postE-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n=postorder.size()-1;
        for(int i=0;i<=n;i++){
            mp[inorder[i]]=i;
        }
        return helper(inorder,postorder,mp,0,n,0,n);
    }
};
