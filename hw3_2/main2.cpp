#include "caculator2.h"
#include <stdio.h>

int main(){
	string line;
	vector<struct Unit> thepostfix;
	while(getline(cin,line)){
		line = cleanblank(line);
		transtopos(line,thepostfix);
		printpos(thepostfix);
		printf( "RESULT: %.6lf\n",caculator(thepostfix));
		thepostfix.clear();
		line.clear();
	}
	return 0;
}
