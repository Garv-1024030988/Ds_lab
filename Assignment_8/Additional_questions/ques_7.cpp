#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insertBST(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = insertBST(root->left, x);
    else root->right = insertBST(root->right, x);
    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

list<int> mergeToDLL(const vector<int>& a, const vector<int>& b) {
    list<int> dll;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) dll.push_back(a[i++]);
        else dll.push_back(b[j++]);
    }
    while (i < a.size()) dll.push_back(a[i++]);
    while (j < b.size()) dll.push_back(b[j++]);
    return dll;
}

list<int> mergeBSTs(Node* root1, Node* root2) {
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);
    return mergeToDLL(a, b);
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    root1 = insertBST(root1, 5);
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 7);

    root2 = insertBST(root2, 4);
    root2 = insertBST(root2, 1);
    root2 = insertBST(root2, 6);

    list<int> dll = mergeBSTs(root1, root2);

    for (int x : dll) cout << x << " ";
    cout << endl;
}
