#include <iostream>
#include <string>
#include <vector>
#include <stack>

#define Status double

#define MAX 30

#define Number 0
#define open 1
#define close 2
#define postive 3
#define negative 4
#define Lnot 5
#define Not 6
#define mutiply 7
#define over 8
#define mod 9
#define plus 10
#define minus 11
#define left 12
#define right 13
#define And 14
#define exor 15
#define Or 16
#define Land 17
#define Lor 18
#define SinC 19
#define CosC 20
#define ExpC 21
#define LogC 22
#define PowC 23
#define SqrtC 24
#define FabC 25
#define comma 26

using namespace std;
struct Unit{
	int level;
	int kind;
	Status content;
};
string cleanblank(string &str);
void infixtopostfix(const vector<struct Unit> &infix,vector<struct Unit>&postfix);
void transtopos(const string &line,vector<struct Unit> &postfix);
void printpos(const vector<struct Unit> &postfix);
