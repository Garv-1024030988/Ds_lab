#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool flag = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            flag = true;
            break;
        }
    }
    if (!flag) return nullptr;
    ListNode* temp = head;
    while (temp != slow) {
        temp = temp->next;
        slow = slow->next;
    }
    return slow;
}

void removeLoop(ListNode* head) {
    ListNode* loopNode = detectCycle(head);
    if (!loopNode) return;
    ListNode* temp = loopNode;
    while (temp->next != loopNode)
        temp = temp->next;
    temp->next = nullptr;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;
    removeLoop(head);
    ListNode* temp = head;
    int count = 0;
    while (temp && count < 10) {
        cout << temp->val << " ";
        temp = temp->next;
        count++;
    }
}
