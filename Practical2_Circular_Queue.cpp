#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Add element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
    }

    // Remove element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int value = arr[front];

        if (front == rear) {
            // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        return value;
    }

    // Display elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % capacity;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue: ";
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(60);
    q.enqueue(70);

    cout << "Queue after circular insertion: ";
    q.display();

    return 0;
}