#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp = headA;
    ListNode* ta = headA;
    ListNode* tb = headB;
    int s1 = 0, s2 = 0;

    while (temp != NULL) {
        temp = temp->next;
        s1++;
    }

    temp = headB;
    while (temp != NULL) {
        temp = temp->next;
        s2++;
    }

    if (s1 > s2) {
        temp = headA;
        for (int i = 1; i <= (s1 - s2); i++)
            temp = temp->next;
        ta = temp;
    } else {
        temp = headB;
        for (int i = 1; i <= (s2 - s1); i++)
            temp = temp->next;
        tb = temp;
    }

    while (tb != NULL && ta != NULL) {
        if (tb == ta) return ta;
        tb = tb->next;
        ta = ta->next;
    }

    return NULL;
}

int main() {
    
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    
    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
