#include <iostream>
using namespace std;

class Node {
public:
    char val;
    Node* next;
    Node* prev;
    Node(char val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DLL {
public:
    Node* head;
    DLL() {
        head = nullptr;
    }

    void push(char val) {
        Node* temp = new Node(val);
        if (head == nullptr) {
            head = temp;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = temp;
        temp->prev = t;
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

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (head != tail && tail->next != head) {
        if (head->val != tail->val) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    DLL d;
    d.push('r');
    d.push('a');
    d.push('d');
    d.push('a');
    d.push('r');
    cout << "Doubly Linked List values: ";
    d.display();
    cout << (isPalindrome(d.head) ? "Palindrome" : "Not Palindrome") << endl;
    return 0;
}
