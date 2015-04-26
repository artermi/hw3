#include "postfix2.h"
string theprintoperator[MAX]{
	" ",
	"( ",  ") ", "p ", "n ","! ",
	"~ ", "* " , "/ ", "% ","+ ",
	"- ", "<< ", ">> ","& ","^ ",
	"| ", "&& ","|| ","sin ","cos ",
	"exp ","log ","pow ","sqrt ","fab ",
	", "
};
Unit operators[MAX] ={
	{0,0,0},
	{11,1,0},{-1,2,0},{9,3,0},{9,4,0},{9,5,0},
	{9,6,0},{8,7,0},{8,8,0},{8,9,0},{7,10,0},
	{7,11,0},{6,12,0},{6,13,0},{5,14,0},{4,15,0},
	{3,16,0},{2,17,0},{1,18,0},{10,19,0},{10,20,0},
	{10,21,0},{10,22,0},{10,23,0},{10,24,0},{10,25,0},
	{-1,26,0},
};
string cleanblank(string &str){
	int i = 0;
	string thenew;
	while(i <(int) str.size()){
		if(  str[i] != ' ' )
			thenew += str[i];
		i ++;
	}
	return thenew;
}

void infixtopostfix(const vector<struct Unit> &infix,vector<struct Unit>&postfix){
	stack<struct Unit> opers;
	int i = 0;
	while(i <(int) infix.size()){
		if(infix[i].kind == Number)
			postfix.push_back(infix[i]);
		else if(opers.empty() || (infix[i].level > (opers.top()).level)){
            opers.push(infix[i]);
		}
		else{
			while(!opers.empty() && infix[i].level <= (opers.top()).level && (opers.top()).level < 10){
                    if(infix[i].level == 9  && infix[i].level == (opers.top()).level)
                        break;
                    postfix.push_back(opers.top());opers.pop();
			}

			if(infix[i].kind == close){
				opers.pop();
			}
			else if(infix[i].kind == comma)
			else
				opers.push(infix[i]);
		}
		i++;
	}
	while(!opers.empty()){
		postfix.push_back(opers.top() );opers.pop();
	}
}
void transtopos(const string &line,vector<struct Unit> &postfix){
	int i = 0;
	vector<struct Unit> infix;
	Status temp = -1;
	string :: size_type sz;
	Unit u0 = {0,Number,0};
	while(i < (int) line.size()){
		while(i <(int) line.size() && !isdigit(line[i]) && line[i] != '.'){
			if(line[i] == '-' || line[i] == '+'){
				if(i == 0 ||( (!isdigit(line[i-1]))  && line[i - 1] != ')')){
					if(line[i] == '+')
						infix.push_back(operators[postive]);
					else
						infix.push_back(operators[negative]);
				}
				else if(line[i] == '+')
					infix.push_back(operators[plus]);
				else
					infix.push_back(operators[minus]);
			}
			else if(line[i] == '*')
				infix.push_back(operators[mutiply]);
			else if(line[i] == '/')
				infix.push_back(operators[over]);
			else if(line[i] == '%')
				infix.push_back(operators[mod]);
			else if(line[i] == '&'){
				if(line[i + 1] == '&'){
					infix.push_back(operators[Land]);
					i++;
				}
				else
					infix.push_back(operators[And]);
			}
			else if(line[i] == '^')
				infix.push_back(operators[exor]);
			else if(line[i] == '|'){
				if(line[i + 1] == '|'){
					infix.push_back(operators[Lor]);
					i++;
				}
				else
					infix.push_back(operators[Or]);
			}
			else if(line[i] == '(')
				infix.push_back(operators[open]);
			else if(line[i] == ')')
				infix.push_back(operators[close]);
			else if(line[i] == '~')
				infix.push_back(operators[Not]);
			else if(line[i] == '!')
				infix.push_back(operators[Lnot]);
			else if(line[i] == '<'){
				infix.push_back(operators[left]);
				i++;
			}
			else if(line[i] == '>'){
				infix.push_back(operators[right]);
				i++;
			}
			else if(line[i] == 's' && line[i+1] == 'i'){
				infix.push_back(operators[SinC]);
				i += 3;
			}
			else if(line[i] == 's' && line[i+1] =='q'){
				infix.push_back(operators[SqrtC]);
				i += 4;
			}
			else if(line[i] == 'c'){
				infix.push_back(operators[CosC]);
				i += 3;
			}
			else if(line[i] == 'e'){
				infix.push_back(operators[ExpC]);
				i += 3;
			}
			else if(line[i] == 'l'){
				infix.push_back(operators[LogC]);
				i += 3;
			}
			else if(line[i] == 'p'){
				infix.push_back(operators[PowC]);
				i += 3;
			}
			else if(line[i] == 'f'){
				infix.push_back(operators[Fab]);
				i += 3;
			}
			else if(line[i] == ',')
				infix.push_back(operators[comma]);
			i ++;
		}
		if(i <(int) line.size() &&  (isdigit(line[i]) || line[i] == '.'){
			temp = stod(line.substr(i),&sz);
			i += sz;
		}
		if(temp != -1){
			u0.content = temp;
			infix.push_back(u0);
		}
			temp = -1;
	}
	infixtopostfix(infix,postfix);

};
void printpos(const vector<struct Unit> &postfix){
	int i;
	cout << "Postfix Exp: ";
	for(i = 0; i <(int) postfix.size(); i++){
		if(postfix[i].kind == Number)
			cout << postfix[i].content << " ";
		else
			cout << theprintoperator[(postfix[i].kind)];
	}
	cout << endl;
}
