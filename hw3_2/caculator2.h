#ifndef CACULATOR_H_INCLUDED
#define CACULATOR_H_INCLUDED
#include "postfix2.h"
#include <cmath>

void dounary(stack<Status>&numstack,int which);
void dobinary(stack<Status>&numstack,int which);
Status caculator(const vector<struct Unit>postfix);


#endif // CACULATOR_H_INCLUDED
