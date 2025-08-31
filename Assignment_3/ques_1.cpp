#include <iostream>
using namespace std;

#define MAX 100

int stack2[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow!\n";
    }
    else
    {
        stack2[++top] = val;
        cout << val << " pushed.\n";
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow!\n";
    }
    else
    {
        cout << stack2[top--]<< " popped.\n";
    }
}

bool isEmpty() { return (top == -1); }
bool isFull() { return (top == MAX - 1); }

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
    {
        cout << stack2[i]<< " ";
    }
    cout << endl;
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Top element: " << stack2[top] << endl;
    }
}

void printMenu()
{
    cout << "\n--- Stack Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. isEmpty\n";
    cout << "4. isFull\n";
    cout << "5. Display\n";
    cout << "6. Peek\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    int choice, val;

    while (true)
    {
        printMenu();
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> val;
            push(val);
        }
        else if (choice == 2)
            pop();
        else if (choice == 3)
            cout << (isEmpty() ? "Yes, Empty.\n" : "Not Empty.\n");
        else if (choice == 4)
            cout << (isFull() ? "Yes, Full.\n" : "Not Full.\n");
        else if (choice == 5)
            display();
        else if (choice == 6)
            peek();
        else if (choice == 7)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
