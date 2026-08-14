#include <iostream>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;

    // Postfix expression: 23*54*+9-
    string postfix = "23*54*+9-";

    for (char ch : postfix) {

        // If operand, push it onto the stack
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        // If operator, pop two operands and perform operation
        else {
            int op2 = s.pop();
            int op1 = s.pop();

            switch (ch) {
                case '+':
                    s.push(op1 + op2);
                    break;

                case '-':
                    s.push(op1 - op2);
                    break;

                case '*':
                    s.push(op1 * op2);
                    break;

                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }

    cout << "Result = " << s.pop() << endl;

    return 0;
}