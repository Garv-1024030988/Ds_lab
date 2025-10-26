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

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }
        
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        
        last->next = newNode;
        newNode->next = head;
    }

    void removeEvenParityNodes() {
        if (head == nullptr) return;
        
        Node* current = head;
        Node* previous = nullptr;
        
        do {
            Node* nextNode = current->next;
            
            if (hasEvenParity(current->data)) {
                if (previous == nullptr) {
                    if (current->next == head) {
                        head = nullptr;
                    } else {
                        Node* last = head;
                        while (last->next != head) {
                            last = last->next;
                        }
                        last->next = head->next;
                        head = head->next;
                    }
                } else {
                    previous->next = current->next;
                }
                
                delete current;
                current = nextNode;
            } else {
                previous = current;
                current = nextNode;
            }
            
        } while (current != head && head != nullptr);
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty list\n";
            return;
        }
        
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << "\n";
    }
};

int main() {
    CircularLinkedList cll;
    
    cout << "Circular Linked List:\n";
    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    
    cout << "Original list: ";
    cll.display();
    
    cll.removeEvenParityNodes();
    cout << "After removing even parity nodes: ";
    cll.display();
    
    return 0;
}
