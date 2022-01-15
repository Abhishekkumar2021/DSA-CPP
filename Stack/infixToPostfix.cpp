#include<bits/stdc++.h>
using namespace std;
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
int solvePostfix(string postfix){
    int ans = 0;
    stack<char> expressionStack;
    for(int i=0; i<postfix.length(); i++){
        if(isOperand(postfix[i])){
            expressionStack.push(postfix[i]);
        }
        else{
            int firstOperand = expressionStack.top() - '0';
            expressionStack.pop();
            int secondOperand = expressionStack.top() - '0';
            expressionStack.pop();
            if(postfix[i]=='+'){
                ans = firstOperand + secondOperand;
            }
            if(postfix[i]=='-'){
                ans = secondOperand - firstOperand;
            }
            if(postfix[i]=='*'){
                ans = firstOperand * secondOperand;
            }
            if(postfix[i]=='/'){
                ans = secondOperand / firstOperand;
            }
            char pushItems = ans + '0';
            expressionStack.push(pushItems);
        }
    }
    ans = expressionStack.top() - '0';
    return ans;
}
int main()
{
    string infix = "1*4/(1-2)";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    cout<<solvePostfix(postfix) << endl;
}