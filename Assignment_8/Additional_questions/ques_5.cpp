#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* helper(vector<int>& pre, vector<int>& in, unordered_map<int, int>& mp, int preS, int preE, int inS, int inE) {
    if (preS > preE) return nullptr;
    int r = pre[preS];
    TreeNode* root = new TreeNode(r);
    int i = mp[r];
    int x = i - inS;
    root->left = helper(pre, in, mp, preS + 1, preS + x, inS, i - 1);
    root->right = helper(pre, in, mp, preS + x + 1, preE, i + 1, inE);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return nullptr;
    unordered_map<int, int> mp;
    int n = preorder.size() - 1;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return helper(preorder, inorder, mp, 0, n, 0, n);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    TreeNode* root = buildTree(preorder, inorder);
    printInorder(root);
    return 0;
}
