#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* node) {
    return node && !node->left && !node->right;
}

int sumOfLeftLeaves(Node* root) {
    if (root == nullptr)
        return 0;

    int sum = 0;

    if (root->left) {
        if (isLeaf(root->left))
            sum += root->left->val;
        else
            sum += sumOfLeftLeaves(root->left);
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}


int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of all left leaves: " << sumOfLeftLeaves(root) << endl;

    return 0;
}
