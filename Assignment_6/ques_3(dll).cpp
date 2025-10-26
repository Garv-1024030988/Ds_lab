#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;
    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (head == nullptr) {
            head = tail = temp;
            return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void display() {
        if (!head) {
            cout << "Empty List" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    DLL d;
    d.push(10);
    d.push(20);
    d.push(30);
    d.push(40);
    d.push(50);
    cout << "Doubly Linked List values: ";
    d.display();
    cout << "Length of DLL: " << length(d.head) << endl;
    return 0;
}
