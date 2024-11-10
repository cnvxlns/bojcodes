#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char value;
    Node *next;
    Node *prev;

    Node(char val) : value(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node *head;  // Dummy head to simplify boundary cases
    Node *cur;   // Cursor node
public:
    LinkedList() {
        head = new Node('\0'); // Dummy node
        cur = head; // Cursor starts at the dummy node
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Move cursor left
    void L() {
        if (cur != head) { // Only move if cursor is not at the dummy head
            cur = cur->prev;
        }
    }

    // Move cursor right
    void D() {
        if (cur->next != nullptr) {
            cur = cur->next;
        }
    }

    // Delete character to the left of the cursor
    void B() {
        if (cur != head) { // Only delete if cursor is not at the start
            Node* toDelete = cur;
            cur = cur->prev; // Move cursor left before deletion
            if (toDelete->next) {
                toDelete->next->prev = cur;
            }
            cur->next = toDelete->next;
            delete toDelete;
        }
    }

    // Insert character to the right of the cursor
    void P(char val) {
        Node* newnode = new Node(val);
        newnode->prev = cur;
        newnode->next = cur->next;
        if (cur->next != nullptr) {
            cur->next->prev = newnode;
        }
        cur->next = newnode;
        cur = newnode; // Move cursor to the new node
    }

    // Print the list from the first real node (skip dummy head)
    void printList() {
        Node* current = head->next; // Start from the first actual character
        while (current != nullptr) {
            cout << current->value;
            current = current->next;
        }
        cout << endl;
    }
};

void Solve() {
    LinkedList editor;
    string init;
    cin >> init;

    // Initialize the linked list with initial text
    for (char ch : init) {
        editor.P(ch);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'P') {
            char val;
            cin >> val;
            editor.P(val);
        } else if (cmd == 'L') {
            editor.L();
        } else if (cmd == 'D') {
            editor.D();
        } else if (cmd == 'B') {
            editor.B();
        }
    }

    editor.printList();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    Solve();
    return 0;
}
