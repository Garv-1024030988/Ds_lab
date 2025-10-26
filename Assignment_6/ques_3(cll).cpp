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
        Node* t = tail->next;
        tail->next = temp;
        tail = temp;
        tail->next = t;
    }

    void display() {
        if (tail == nullptr) {
            cout << "Empty List" << endl;
            return;
        }
        cout << tail->next->val << " ";
        Node* temp = tail->next->next;
        while (temp != tail->next) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << tail->next->val << endl;
    }
};

int size(Node* tail) {
    if (tail == nullptr) return 0;
    int count = 1;
    Node* temp = tail->next;
    while (temp != tail) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Circular c;
    c.push(20);
    c.push(100);
    c.push(40);
    c.push(80);
    c.push(60);
    cout << "Circular Linked List values: ";
    c.display();
    cout << "Size of CLL: " << size(c.tail) << endl;
    return 0;
}
