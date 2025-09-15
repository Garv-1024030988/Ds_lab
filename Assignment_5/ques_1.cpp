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
public:
    int size;
    Node *head;
    Node *tail;
    LinkedList()
    {
        this->head = this->tail = NULL;
        size = 0;
    }
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAt(int val, int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Index out of range" << endl;
            return;
        }

        if (idx == 0)
        {
            insertAtHead(val);
            return;
        }
        if (idx == size)
        {
            insertAtEnd(val);
            return;
        }
        Node *t = new Node(val);
        Node *temp = head;
        for (int i = 1; i < idx; i++)
        {
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
        size++;
    }
    int get(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "invalid index" << endl;
            return -1;
        }
        else if (idx == 0)
            return head->val;
        else if (idx == size - 1)
            return tail->val;
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx; i++)
            {
                temp = temp->next;
            }
            return temp->val;
        }
    }
    void deleteAtHead()
    {
        if (size == 0)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        size--;
        delete temp;
        if (size == 0)
        {
            tail = NULL;
        }
    }
    void deleteAtTail()
    {
        if (size == 0)
            return;
        if (size == 1)
        {
            delete head;
            head = tail = NULL;
            size = 0;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;

        tail = temp;
        tail->next = NULL;
        size--;
    }
    void deleteAt(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid index";
            return;
        }
        if(idx==0){
            deleteAtHead();
            return;
        }
        if(idx==size-1){
            deleteAtTail();
            return;
        }
        Node*temp=head;
        for(int i=1;i<idx;i++){
            temp=temp->next;
        }
        Node* delNode=temp->next;
        temp->next=delNode->next;
        delete delNode;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(50);
    ll.insertAtHead(20);
    ll.insertAt(100, 0);
    ll.insertAt(200, 3);
    ll.insertAt(300, 1);
    ll.insertAt(400, 5);
    ll.insertAt(500, 9);
    ll.display();
    cout << ll.size << endl;
    cout << ll.get(4) << endl;
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtHead();
    ll.display();
    cout << ll.size << endl;
    ll.deleteAt(2);
    ll.display();

    return 0;
}
