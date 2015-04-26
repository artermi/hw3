#include "caculator2.h"

int main(){
	string line;
	vector<struct Unit> thepostfix;
	while(getline(cin,line)){
		line = cleanblank(line);
		transtopos(line,thepostfix);
		printpos(thepostfix);
		cout << "RESULT: "<<caculator(thepostfix) << endl;
		thepostfix.clear();
		line.clear();
	}
	return 0;
}
