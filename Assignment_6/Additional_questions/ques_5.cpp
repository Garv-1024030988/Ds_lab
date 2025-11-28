#include <iostream>
using namespace std;

#define dim 3

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
};

Node* createNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    temp->up = NULL;
    temp->down = NULL;
    return temp;
}

Node* constructDoublyListUtil(int mtrx[][dim], int i, int j, Node* curr, Node* upCurr)
{
    if (i >= dim || j >= dim) {
        return NULL;
    }

    Node* temp = createNode(mtrx[i][j]);

    temp->prev = curr;
    if(curr) curr->next = temp;

    temp->up = upCurr;
    if(upCurr) upCurr->down = temp;

    temp->next = constructDoublyListUtil(mtrx, i, j + 1, temp, (upCurr ? upCurr->next : NULL));
    temp->down = constructDoublyListUtil(mtrx, i + 1, j, NULL, temp);

    return temp;
}

Node* constructDoublyList(int mtrx[][dim])
{
    return constructDoublyListUtil(mtrx, 0, 0, NULL, NULL);
}

void display(Node* head)
{
    Node* rPtr;
    Node* dPtr = head;

    while (dPtr) {
        rPtr = dPtr;
        while (rPtr) {
            cout << rPtr->data << " ";
            rPtr = rPtr->next;
        }
        cout << "\n";
        dPtr = dPtr->down;
    }
}

int main()
{
    int mtrx[dim][dim] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    Node* list = constructDoublyList(mtrx);
    display(list);
    return 0;
}
