#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertDoubly(DNode*& head, int val) {
    DNode* newNode = new DNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void removeEvenDoubly(DNode*& head) {
    DNode* temp = head;
    while (temp) {
        if (temp->data % 2 == 0) {
            DNode* toDelete = temp;
            if (temp->prev) temp->prev->next = temp->next;
            else head = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
}

void displayDoubly(DNode* head) {
    for (DNode* temp = head; temp; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}

int main() {
    DNode* dHead = nullptr;
    insertDoubly(dHead, 10);
    insertDoubly(dHead, 15);
    insertDoubly(dHead, 20);
    insertDoubly(dHead, 25);
    insertDoubly(dHead, 30);

    cout << "Original Doubly Linked List: ";
    displayDoubly(dHead);

    removeEvenDoubly(dHead);

    cout << "After removing even nodes (DLL): ";
    displayDoubly(dHead);

    return 0;
}
