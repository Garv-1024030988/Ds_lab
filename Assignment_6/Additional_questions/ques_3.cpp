#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* current = head;
    Node* newHead = nullptr;
    Node* prevTail = nullptr;

    while (current) {
        Node* groupHead = current;
        Node* prev = nullptr;
        int count = 0;

        while (current && count < k) {
            Node* nextNode = current->next;
            current->next = prev;
            current->prev = nextNode;
            prev = current;
            current = nextNode;
            count++;
        }

        if (prevTail) prevTail->next = prev;
        prev->prev = prevTail;

        if (!newHead) newHead = prev;
        prevTail = groupHead;
    }

    if (prevTail) prevTail->next = nullptr;
    return newHead;
}

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    for (Node* temp = head; temp; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 8; i++)
        insert(head, i);

    int k = 3;
    cout << "Original List: ";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
