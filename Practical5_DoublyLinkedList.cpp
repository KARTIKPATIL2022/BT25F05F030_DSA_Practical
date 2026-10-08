#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBeginning(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    cout << "Node inserted at beginning.\n";
}

// Insert at end
void insertEnd(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;

        cout << "Node inserted at end.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    newNode->prev = temp;
    temp->next = newNode;

    cout << "Node inserted at end.\n";
}

// Insert at specific position
void insertPosition(int value, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1)
    {
        insertBeginning(value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Position does not exist.\n";
        return;
    }

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    cout << "Node inserted at position " << position << ".\n";
}

// Delete from beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;

    cout << "Node deleted from beginning.\n";
}

// Delete from end
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    if (head->next == NULL)
    {
        head = NULL;
        delete temp;

        cout << "Node deleted from end.\n";
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    delete temp;

    cout << "Node deleted from end.\n";
}

// Delete from specific position
void deletePosition(int position)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (position <= 0)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1)
    {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Position does not exist.\n";
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Node deleted from position " << position << ".\n";
}

// Display forward
void displayForward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Forward List: ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Display backward
void displayBackward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    cout << "Backward List: ";

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

int main()
{
    int choice, value, position;

    do
    {
        cout << "\n========== DOUBLY LINKED LIST ==========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display Forward\n";
        cout << "8. Display Backward\n";
        cout << "9. Exit\n";
        cout << "=========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
                cout << "Enter value: ";
                cin >> value;

                cout << "Enter position: ";
                cin >> position;

                insertPosition(value, position);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> position;

                deletePosition(position);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}