class Solution {
public:
    int levels(TreeNode*root){
        if(root==nullptr) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void levelOrder(TreeNode*root,vector<int>&v,int level=1){
        if(root==nullptr) return;
        v[level-1]=root->val;
        levelOrder(root->left,v,level+1);
        levelOrder(root->right,v,level+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        int level=levels(root);
        vector<int>result(level);
        levelOrder(root,result);
        return result;
    }
};
