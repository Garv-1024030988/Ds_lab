#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

Node* add(Node* poly1, Node* poly2) {
    Node* resultHead = nullptr;
    Node* resultTail = nullptr;

    while (poly1 != nullptr && poly2 != nullptr) {
        int c = 0;
        int p = 0;

        if (poly1->pow > poly2->pow) {
            c = poly1->coeff;
            p = poly1->pow;
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            c = poly2->coeff;
            p = poly2->pow;
            poly2 = poly2->next;
        } else {
            c = poly1->coeff + poly2->coeff;
            p = poly1->pow;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        Node* newNode = new Node(c, p);
        if (!resultHead) {
            resultHead = resultTail = newNode;
        } else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
    }

    while (poly1 != nullptr) {
        Node* newNode = new Node(poly1->coeff, poly1->pow);
        if (!resultHead) resultHead = resultTail = newNode;
        else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
        poly1 = poly1->next;
    }

    while (poly2 != nullptr) {
        Node* newNode = new Node(poly2->coeff, poly2->pow);
        if (!resultHead) resultHead = resultTail = newNode;
        else {
            resultTail->next = newNode;
            resultTail = newNode;
        }
        poly2 = poly2->next;
    }

    return resultHead;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next != nullptr) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = new Node(5, 3);
    poly1->next = new Node(4, 2);
    poly1->next->next = new Node(2, 0);

    Node* poly2 = new Node(3, 4);
    poly2->next = new Node(2, 3);
    poly2->next->next = new Node(1, 2);
    poly2->next->next->next = new Node(6, 0);

    Node* sum = add(poly1, poly2);

    cout << "Polynomial 1: ";
    print(poly1);

    cout << "Polynomial 2: ";
    print(poly2);

    cout << "Sum: ";
    print(sum);

    return 0;
}
