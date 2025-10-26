#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

class DoublyLL {
public:
    Node *head;
    DoublyLL() : head(NULL) {}

    void insertNode(int data) {
        Node *n = new Node(data);
        if (!head) {
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void correctPointer() {
        Node *temp = head;
        while (temp && temp->next) {
            if (temp->next->prev != temp)
                temp->next->prev = temp;
            temp = temp->next;
        }
    }

    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLL ll;
    ll.head = new Node(1);
    ll.head->next = new Node(2);
    ll.head->next->prev = ll.head;
    ll.head->next->next = new Node(3);
    ll.head->next->next->prev = ll.head; // wrong pointer
    ll.head->next->next->next = new Node(4);
    ll.head->next->next->next->prev = ll.head->next->next;

    cout << "Before correction: ";
    ll.display();

    ll.correctPointer();

    cout << "After correction: ";
    ll.display();

    return 0;
}
