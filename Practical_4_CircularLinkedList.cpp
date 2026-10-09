
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertEnd(int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void insertPosition(int value, int pos) {
    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    if (head == NULL) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (pos > 1 && temp->next == head && pos > 2) {
        // Continue only if the requested position is valid.
        int count = 1;
        Node* p = head;
        while (p->next != head) {
            count++;
            p = p->next;
        }
        if (pos > count + 1) {
            cout << "Invalid position!\n";
            return;
        }
    }

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}

void deleteBeginning() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    Node* last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    delete temp->next;
    temp->next = head;
}

void deletePosition(int pos) {
    if (head == NULL || pos < 1) {
        cout << "Invalid position or empty list!\n";
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        cout << "Invalid position!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main() {
    int choice, value, pos;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    while (head != NULL)
        deleteBeginning();

    return 0;
}
