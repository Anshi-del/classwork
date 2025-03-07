#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE 100

class Stack {
    char data[MAX_SIZE];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
         return top == -1; 
         }
    bool isFull() {
         return top == MAX_SIZE - 1; 
         }

    void push(char c) {
        if (!isFull()) {
            data[++top] = c;
        } else {
            cout << "Stack is full. Cannot push " << c << endl;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
            return '\0';
        }
    }

    char peek() {
        if (!isEmpty()) {
            return data[top];
        } else {
            cout << "Stack is empty." << endl;
            return '\0';
        }
    }
};

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
        else if (c == '^')
        return 3;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == ' ') {
            i++;
            continue;
        }

        if (infix[i] == '(') {
            s.push(infix[i]);
            i++;
        } 
        else if (infix[i] == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();
            }
            i++;
        } else if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
            i++;
        } else {
            while (!s.isEmpty() && s.peek() != '(' && precedence(s.peek()) >= precedence(infix[i])) {
                postfix[j++] = s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }

    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    cout << "Enter an infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
} 