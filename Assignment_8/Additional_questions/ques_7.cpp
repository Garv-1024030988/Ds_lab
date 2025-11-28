#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
public:
    DNode* head;

    DoublyLinkedList() { head = nullptr; }

    void insertSorted(int val) {
        DNode* n = new DNode(val);
        if (!head || val < head->data) {
            n->next = head;
            if (head) head->prev = n;
            head = n;
            return;
        }
        DNode* temp = head;
        while (temp->next && temp->next->data < val)
            temp = temp->next;
        n->next = temp->next;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    return root;
}

void inorderToList(Node* root, DoublyLinkedList& l) {
    if (!root) return;
    inorderToList(root->left, l);
    l.insertSorted(root->data);
    inorderToList(root->right, l);
}



int main() {
   DoublyLinkedList l;
    Node* root1 = nullptr;
    root1 = insertBST(root1, 5);
    root1 = insertBST(root1, 3);
    root1 = insertBST(root1, 7);

    Node* root2 = nullptr;
    root2 = insertBST(root2, 4);
    root2 = insertBST(root2, 2);
    root2 = insertBST(root2, 8);
inorderToList(root1, l);
    inorderToList(root2, l);

    cout << "Combined BSTs into sorted doubly linked list:\n";
    l.display();

    return 0;
}
