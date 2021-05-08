/*
Emi Anyakpor

5/7/21

Version: 1.2

Description: Given a string comprising of opening and closing characters of 
parenthesis braces, brackets, or curlies check for balancing.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

    bool checkParenthesis(char open, char close)
    {
        if(open == '(' && close == ')')
        {
            return true;
        }
        else if(open == '{' && close == '}')
        {
            return true;
        }
        else if(open = '[' && close == '[')
        {
            return true;
        }
        else 
        {
            return false;
        }
        
    }
    bool isParenthesisBalanced(string exp)
    {
        stack<char> s;
        for(int i = 0; i < exp.length(); ++i)
        {
            if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                s.push(exp[i]);
            }
            else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if(s.empty() || !checkParenthesis(s.top(), exp[i]))
                {
                    return false;
                }
                else 
                {
                    s.pop();
                }
            }
        }
    }
int main()
{
    string expression;
    cout << "Please enter a phrase in between parameters, bracks or curlies.\n";
    cin >> expression;
    if(isParenthesisBalanced(expression))
    {
        cout << "\n its balanced.";
    }
    else 
    {
        cout << "\n its not balanced.";
    }
    

    return 0;
}
