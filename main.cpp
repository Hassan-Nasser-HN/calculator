//
// Created by 20111 on 27/06/2026.
//
#include <iostream>
#include <calculator.h>
#include <string>
#include <stack>
using namespace std;

string infix_to_postfix(string exp);
double operation(string exp);

int main() {
    string expression;
    char answer;
    do {
        cout << "Enter an expression: "<<endl;
        cin >> expression;

        string exp= infix_to_postfix(expression);
        double result = operation(exp);
        cout << "result: "<<result << endl;

        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> answer;

    }while (answer == 'Y' || answer == 'y');




}

string infix_to_postfix(string exp) {

     stack<char> op;
     string result;
    for(int i = 0; i < exp.length(); i++){

        char c = exp[i];
        //-------------------1-------------------
        if(isdigit(c)){ result.push_back(c); }
        //-------------------2--------------------
        else if(c=='+' || c=='-' || c=='*' || c=='/'){
            //----------------------2.1------------------------
            if(op.empty() || op.top()=='(') {op.push(c); }
             //----------------------2.2-------------------------
           else if((op.top()=='+' || op.top()=='-') && (c=='*' || c=='/')) {op.push(c);}
            //----------------------2.3---------------------------
            else if((op.top()=='*' || op.top()=='/') && (c=='+' || c=='-')){
                while(!op.empty() && (op.top()=='*' || op.top()=='/') && op.top()!='(') {
                    result.push_back(op.top());
                    op.pop();
                }
                op.push(c);
            }
            //-------------------------2.4-----------------------------
            else if((op.top()=='*' || op.top()=='/') && (c=='*' || c=='/')){
                while(!op.empty() && (op.top()=='*' || op.top()=='/') && op.top()!='(') {
                    result.push_back(op.top());
                    op.pop();
                }
                op.push(c);
            }
            //---------------------2.5----------------------------------
            else if((op.top()=='+' || op.top()=='-') && (c=='+' || c=='-')){

                while(!op.empty() && (op.top()=='+' || op.top()=='-') && op.top()!='('){
                    result.push_back(op.top());
                    op.pop();
                }
                op.push(c);
            }
            //------------------------end---------------------------------
        }
        // ------------------3--------------------
        else if(c=='('){ op.push(c);}
       //--------------------4----------------------
        else if(c==')'){
            while(!op.empty() && op.top()!='('){
               result.push_back(op.top());

                op.pop();

            }
            if(!op.empty()){

                op.pop();
            }
        }
    }

    //------------5-----------------
    while(!op.empty()){op.pop();}

    cout << endl;

  return result;
};
//double operation(string exp){};