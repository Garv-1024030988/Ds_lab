#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int v) : data(v), next(nullptr), prev(nullptr) {}
};

class DLL {
    Node* head = nullptr;
public:
    void insertBeg(int v) {
        Node* n = new Node(v);
        if (head) { n->next = head; head->prev = n; }
        head = n;
    }
    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* t = head; while (t->next) t = t->next;
        t->next = n; n->prev = t;
    }
    void insertAfter(int k, int v) {
        Node* t = head; while (t && t->data != k) t = t->next;
        if (!t) return; Node* n = new Node(v);
        n->next = t->next; n->prev = t;
        if (t->next) t->next->prev = n; t->next = n;
    }
    void insertBefore(int k, int v) {
        if (head && head->data == k) { insertBeg(v); return; }
        Node* t = head; while (t && t->data != k) t = t->next;
        if (!t) return; Node* n = new Node(v);
        n->next = t; n->prev = t->prev; t->prev->next = n; t->prev = n;
    }
    void delNode(int k) {
        Node* t = head; while (t && t->data != k) t = t->next;
        if (!t) return;
        if (t->prev) t->prev->next = t->next; else head = t->next;
        if (t->next) t->next->prev = t->prev;
        delete t;
    }
    void search(int k) {
        Node* t = head; int pos = 1;
        while (t) { if (t->data == k) { cout << "Found at " << pos << "\n"; return; } t = t->next; pos++; }
        cout << "Not found\n";
    }
    void display() {
        for (Node* t = head; t; t = t->next) cout << t->data << " ";
        cout << "\n";
    }
};

class CLL {
    Node* head = nullptr;
public:
    void insertBeg(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; head->next = head; return; }
        Node* t = head; while (t->next != head) t = t->next;
        t->next = n; n->next = head; head = n;
    }
    void insertEnd(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; head->next = head; return; }
        Node* t = head; while (t->next != head) t = t->next;
        t->next = n; n->next = head;
    }
    void insertAfter(int k, int v) {
        Node* t = head;
        if (!t) return;
        do {
            if (t->data == k) { Node* n = new Node(v); n->next = t->next; t->next = n; return; }
            t = t->next;
        } while (t != head);
    }
    void insertBefore(int k, int v) {
        if (!head) return;
        Node* t = head; Node* p = nullptr;
        do {
            if (t->data == k) {
                Node* n = new Node(v);
                if (!p) { Node* last = head; while (last->next != head) last = last->next;
                          last->next = n; n->next = head; head = n; }
                else { p->next = n; n->next = t; }
                return;
            }
            p = t; t = t->next;
        } while (t != head);
    }
    void delNode(int k) {
        if (!head) return;
        Node *t = head, *p = nullptr;
        do {
            if (t->data == k) {
                if (!p) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    if (last == head) head = nullptr;
                    else { last->next = head->next; head = head->next; }
                } else p->next = t->next;
                delete t; return;
            }
            p = t; t = t->next;
        } while (t != head);
    }
    void search(int k) {
        if (!head) { cout << "Not found\n"; return; }
        Node* t = head; int pos = 1;
        do { if (t->data == k) { cout << "Found at " << pos << "\n"; return; }
             t = t->next; pos++; } while (t != head);
        cout << "Not found\n";
    }
    void display() {
        if (!head) { cout << "Empty\n"; return; }
        Node* t = head;
        do { cout << t->data << " "; t = t->next; } while (t != head);
        cout << "\n";
    }
};

int main() {
    DLL dll; CLL cll;
    int listType, ch, v, k;
    do {
        cout << "\n1.DLL  2.CLL  3.Exit\nChoose: "; cin >> listType;
        if (listType == 3) break;
        cout << "1.InsBeg 2.InsEnd 3.InsAfter 4.InsBefore 5.Delete 6.Search 7.Display 8.Back\nChoice: ";
        cin >> ch; if (ch == 8) continue;
        if (ch==1||ch==2||ch==3||ch==4) { cout << "Val: "; cin >> v; }
        if (ch==3||ch==4||ch==5||ch==6) { cout << "Key: "; cin >> k; }

        if (listType == 1) {
            if (ch==1) dll.insertBeg(v);
            else if (ch==2) dll.insertEnd(v);
            else if (ch==3) dll.insertAfter(k,v);
            else if (ch==4) dll.insertBefore(k,v);
            else if (ch==5) dll.delNode(k);
            else if (ch==6) dll.search(k);
            else if (ch==7) dll.display();
        } else {
            if (ch==1) cll.insertBeg(v);
            else if (ch==2) cll.insertEnd(v);
            else if (ch==3) cll.insertAfter(k,v);
            else if (ch==4) cll.insertBefore(k,v);
            else if (ch==5) cll.delNode(k);
            else if (ch==6) cll.search(k);
            else if (ch==7) cll.display();
        }
    } while (true);
}
