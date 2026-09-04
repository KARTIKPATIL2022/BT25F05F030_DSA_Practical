#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

// Insert a node
void insertNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    cout << "Node inserted successfully.\n";
}

// Delete a node
void deleteNode(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* current = head;
    Node* previous = tail;

    do {
        if (current->data == value) {

            // Only one node
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            }

            // Delete head
            else if (current == head) {
                head = head->next;
                tail->next = head;
            }

            // Delete other node
            else {
                previous->next = current->next;

                if (current == tail) {
                    tail = previous;
                }
            }

            delete current;
            cout << "Node deleted successfully.\n";
            return;
        }

        previous = current;
        current = current->next;

    } while (current != head);

    cout << "Node not found.\n";
}

// Display the list
void display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Circular Linked List ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertNode(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}