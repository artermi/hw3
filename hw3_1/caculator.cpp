#include "caculator.h"
#include <stdio.h>
#include <stdlib.h>

void dounary(stack<Status>&numstack,int which){
    Status num;
    if(which == postive)
        num = +(numstack.top());
    else if(which == negative)
        num = -(numstack.top());
    else if(which == Lnot)
        num = !(numstack.top());
    else
        num = ~(numstack.top());
    numstack.pop();
    numstack.push(num);
}
void dobinary(stack<Status>&numstack,int which){
    Status num1,num2;
    num2 = numstack.top();numstack.pop();
    num1 = numstack.top();numstack.pop();
    if(which == mutiply)
        num1 *= num2;
    else if(which == over)
        num1 /= num2;
    else if(which == mod)
        num1 %= num2;
    else if(which == plus)
        num1 += num2;
    else if(which == minus)
        num1 -= num2;
    else if(which == left)
        num1 = num1 << num2;
    else if(which == right)
        num1 = num1 >> num2;
    else if(which == And)
        num1 = num1 & num2;
    else if(which == exor)
        num1 = num1 ^ num2;
    else if(which == Or)
        num1 = num1 | num2;
    else if(which == Land)
        num1 = num1 && num2;
    else if(which == Lor)
        num1 = num1 || num2;
    numstack.push(num1);
}


int caculator(const vector<struct Unit>postfix){
    stack<Status>numstack;
    int i = 0;
    int num;
    while(i < postfix.size()){
        switch (postfix[i].kind){
        case Number:
            {
            num =(int) strtol((postfix[i].content).c_str(),NULL,0);
            numstack.push(num);
            }
            break;
        case postive: case negative: case Not:case Lnot:
            dounary(numstack,postfix[i].kind);
            break;
        case mutiply: case over: case mod: case plus: case minus:
        case left: case right: case And: case exor: case Or:
        case Land: case Lor:
            dobinary(numstack,postfix[i].kind);
            break;
        default:
            cout <<"Bugs !!!" << endl;
        }
        i++;
    }
    return numstack.top();
}
