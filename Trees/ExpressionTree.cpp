#include<bits/stdc++.h>
using namespace std;
class ExpTree{
    public:
    char data;
    ExpTree *left,*right;
    ExpTree(){
        data = '\0';
        left = NULL;
        right = NULL;
    }
    ~ExpTree(){
        delete left;
        delete right;
        cout<<data<<" Deleted!\n";
    }

};

bool isOperand(char ch)
{
    return ((ch <= '9' && ch >= '0') || (ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'));
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
string infixToPostfix(string infix)
{
    string output = "";
    stack<char> pendingOperators;
    for (int i = 0; i < infix.size(); i++)
    {
        if (isOperand(infix[i]))
        {
            output += infix[i];
        }
        else
        {
            if (infix[i] == '(')
            {
                pendingOperators.push(infix[i]);
                continue;
            }
            if (infix[i] == ')')
            {
                while (pendingOperators.top() != '(')
                {
                    output += pendingOperators.top();
                    pendingOperators.pop();
                }
                pendingOperators.pop();
                continue;
            }
            if (pendingOperators.size() == 0)
            {
                pendingOperators.push(infix[i]);
            }
            else if (precedence(infix[i]) > precedence(pendingOperators.top()))
            {
                pendingOperators.push(infix[i]);
            }
            else
            {
                char top = pendingOperators.top();
                while (precedence(infix[i]) <= precedence(top) && !pendingOperators.empty())
                {
                    top = pendingOperators.top();
                    if (top == '(')
                        break;
                    pendingOperators.pop();
                    output += top;
                }
                pendingOperators.push(infix[i]);
            }
        }
    }
    while (!pendingOperators.empty())
    {
        char top = pendingOperators.top();
        output += top;
        pendingOperators.pop();
    }
    return output;
}
