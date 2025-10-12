#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    int count = 0;
    int cycle = 0;
    ListNode* lastHead = nullptr;

    do {
        count = 0;
        ListNode* last = curr;

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        cycle++;
        last->next = curr;
        ListNode* temp = curr;

        if (cycle == 1) {
            head = prev;
        } else {
            lastHead->next = prev;
        }

        count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        lastHead = last;
        if (count < k) break;

    } while (true);

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    cout << "Original list: ";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
