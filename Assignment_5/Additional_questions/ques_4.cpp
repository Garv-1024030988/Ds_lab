#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *rotateLeft(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *last = nullptr;
    int l = 0;
    while (temp != nullptr)
    {
        last = temp;
        temp = temp->next;
        l++;
    }
    if (l == 0 || l == 1)
    {
        return head;
    }
    int idx = k % l;
    if (idx == 0)
    {
        return head;
    }
    temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    last->next = head;
    head = temp->next;
    temp->next = nullptr;
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    head = rotateLeft(head, k);

    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
