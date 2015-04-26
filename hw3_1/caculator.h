#ifndef CACULATOR_H_INCLUDED
#define CACULATOR_H_INCLUDED
#include "postfix.h"
#include <cmath>

void dounary(stack<Status>&numstack,int which);
void dobinary(stack<Status>&numstack,int which);
int caculator(const vector<struct Unit>postfix);


#endif // CACULATOR_H_INCLUDED
