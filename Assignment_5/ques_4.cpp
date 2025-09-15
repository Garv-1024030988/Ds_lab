#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int value)
    {
        this->val = value;
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
    void reverse(){
        head = reverseList(head);
    }
    private:
    Node *reverseList(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

};
int main()
{
    LinkedList ll ;
    for(int i = 1 ; i < 5 ; i++)
    ll.insert(i);

    ll.display();
    cout<<endl;
    ll.reverse();
    ll.display();

    return 0;
}
