/*
Emi Anyakpor

5/7/21

Version: 1.2

Description: Given a string comprising of opening and closing characters of 
parenthesis braces, brackets, or curlies check for balancing.
*/
#include <iostream>
#include <vector> // to traverse the stack list with an vector
#include <stack> // so I don't have to make a stack class with pop/push functions
using namespace std;

    bool checkParenthesis(char open, char close) // neatly checks if open or close
    {
        if(open == '(' && close == ')') // I have all three type of parameters
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
    bool isParenthesisBalanced(string exp) // the function that goes through the list
    {
        stack<char> s; 
        for(int i = 0; i < exp.length(); ++i) // traverse the list.
        {
            if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                s.push(exp[i]); // will push the opening symbol onto stack
            }
            else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                // two things can happen where if stack is empty or 
                // the open parenthesis is not the same as the close
                // it will return false or end the function.
                // however if the if statement is false open parenthesis will be
                // popped from list this will repeat until list is empty.
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
    string expression; // string variable
    cout << "Please enter a phrase in between parameters, bracks or curlies.\n";
    cin >> expression; // user inputed expression
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
