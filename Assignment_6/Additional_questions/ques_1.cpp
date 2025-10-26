#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void splitList(Node* head, Node** head1, Node** head2) {
    if (!head) return;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    *head1 = head;
    *head2 = slow->next;

    fast->next = *head2;
    slow->next = *head1;
}

Node* createCircularList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    temp->next = head;
    return head;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createCircularList(arr, n);
    cout << "Original Circular List: ";
    printList(head);

    Node *head1 = nullptr, *head2 = nullptr;
    splitList(head, &head1, &head2);

    cout << "First Half: ";
    printList(head1);

    cout << "Second Half: ";
    printList(head2);

    return 0;
}
