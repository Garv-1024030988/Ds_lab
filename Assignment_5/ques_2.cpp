#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList
{
    int size;
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insert(int val)
    {
        if (size == 0)
        {
            Node *temp = new Node(val);
            head = tail = temp;
            size++;
            return;
        }
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
        size++;
        return;
    }
    int peek()
    {
        if (size == 0)
        {
            cout << "List empty" << endl;
            return -1;
        }
        return tail->val;
    }
    void display()
    {
        if (size == 0)
        {
            cout << "List empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    void delDup(int val)
    {
        if (size == 0)
        {
            cout << "list empty" << endl;
            return;
        }
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *gen = dummy;
        while (gen != NULL && gen->next != NULL)
        {
            if (gen->next->val == val)
            {
                gen->next = gen->next->next;
            }
            else
                gen = gen->next;
        }
        head = dummy->next;
    }
};
int main()
{
    LinkedList ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(20);
    ll.insert(20);
    ll.insert(20);
    ll.insert(30);
    ll.insert(20);
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);

    ll.display();
    ll.delDup(20);
    cout << endl;
    ll.display();

    return 0;
}
