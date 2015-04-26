#include "caculator2.h"
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
    else if(which == SinC)
	num = sin(numstack.top());
    else if(which == CosC)
	num = cos(numstack.top());
    else if(which == ExpC)
	num = exp(numstack.top());
    else if(which == LogC)
	    num = log(numstack.top());
    else if(which == SqrtC)
	    num = sqrt(numstack.top());
    else if(which == FabC)
	    num = fabs(numstack.top());
  //  else
//        num = ~(numstack.top());
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
    else if(which == mod);
//        num1 %= num2;
    else if(which == plus)
        num1 += num2;
    else if(which == minus)
        num1 -= num2;
    else if(which == left);
//        num1 = num1 << num2;
    else if(which == right);
  //      num1 = num1 >> num2;
    else if(which == And);
//        num1 = num1 & num2;
    else if(which == exor);
//        num1 = num1 ^ num2;
    else if(which == Or);
//        num1 = num1 | num2;
    else if(which == Land)
        num1 = num1 && num2;
    else if(which == Lor)
        num1 = num1 || num2;
    else if(which ==PowC)
	    num1 = pow(num1,num2);
    numstack.push(num1);
}


Status caculator(const vector<struct Unit>postfix){
    stack<Status>numstack;
    int i = 0;
    while(i <(int) postfix.size()){
        switch (postfix[i].kind){
        case Number:
            numstack.push(postfix[i].content);
            break;
        case postive: case negative: case Not:case Lnot:
	case SinC: case CosC: case ExpC: case LogC: case SqrtC: case FabC:
            dounary(numstack,postfix[i].kind);
            break;
        case mutiply: case over: case mod: case plus: case minus:
        case left: case right: case And: case exor: case Or:
	case Land: case Lor: case PowC:
            dobinary(numstack,postfix[i].kind);
            break;
        default:
            cout <<"Bugs !!!" << endl;
        }
        i++;
    }
    return numstack.top();
}
