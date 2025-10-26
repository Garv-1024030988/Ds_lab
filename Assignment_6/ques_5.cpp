#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class Circular {
public:
    Node* tail;
    Circular() {
        tail = nullptr;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (tail == nullptr) {
            tail = temp;
            tail->next = tail;
            return;
        }
        Node* head = tail->next;
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }
};

bool isCircular(Node* head) {
    if (head == nullptr) return false;

    Node* temp = head->next;
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
    Circular cll;
    cll.push(10);
    cll.push(20);
    cll.push(30);

    Node* head = cll.tail->next;

    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is NOT circular." << endl;

    
    Node* normal = new Node(1);
    normal->next = new Node(2);
    normal->next->next = new Node(3);

    if (isCircular(normal))
        cout << "The normal list is circular." << endl;
    else
        cout << "The normal list is NOT circular." << endl;

    return 0;
}
