#include<iostream>
#define MAXSIZE 50
using namespace std;

class Stack
{
    char s[MAXSIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(char);
    char pop();
    bool isFull();
    bool isEmpty();
    char getTop();
    int ISP(char);
    int ICP(char);
    void infixToPostfix(char infix[]);
};

int Stack::ISP(char ch)
{
    switch (ch)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        case '#':
            return -1;
    }
}

int Stack::ICP(char ch)
{
    switch (ch)
    {
        case '(':
            return 4;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        case '#':
            return -1;
    }
}

void Stack::infixToPostfix(char infix[])
{
    Stack s;
    int i = 0;
    s.push('#');
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];
        i++;

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            cout << ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.getTop() != '(')
            {
                cout << s.pop();
            }
            s.pop(); // Pop the '('
        }
        else
        {
            while (ISP(s.getTop()) >= ICP(ch))
            {
                cout << s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (s.getTop() != '#')
    {
        cout << s.pop();
    }
}

char Stack::getTop()
{
    char t = '\0';
    if (top == -1)
        cout << "Stack is underflow...!" << endl;
    else
        t = s[top];
    return t;
}

bool Stack::isFull()
{
    if (top == MAXSIZE - 1)
        return true;
    else
        return false;
}

bool Stack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void Stack::push(char x)
{
    if (top == MAXSIZE - 1)
        cout << "Stack is overflow..!" << endl;
    else
    {
        top++;
        s[top] = x;
    }
}

char Stack::pop()
{
    char t = '\0';
    if (top == -1)
        cout << "Stack is underflow...!" << endl;
    else
    {
        t = s[top];
        top--;
    }
    return t;
}

int main()
{
    Stack s;

    char infixExpression[MAXSIZE];

    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    cout << "Postfix expression: ";
    s.infixToPostfix(infixExpression);

    cout << endl;

    return 0;
}