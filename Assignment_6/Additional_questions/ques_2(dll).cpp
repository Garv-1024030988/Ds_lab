#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

bool hasEvenParity(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count % 2 == 0;
}

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void removeEvenParityNodes() {
        Node* current = head;
        
        while (current != nullptr) {
            Node* nextNode = current->next;
            
            if (hasEvenParity(current->data)) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                
                delete current;
            }
            
            current = nextNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    
    cout << "Doubly Linked List:\n";
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    
    cout << "Original list: ";
    dll.display();
    
    dll.removeEvenParityNodes();
    cout << "After removing even parity nodes: ";
    dll.display();
    
    return 0;
}
