#include <iostream>
#include "SalesItem.h"
using namespace std;

int main(){
	SalesItem si1, si2;

	cin >> si1;
	cin >> si2;
	
	if(si1.IsSame(si2)){
		SalesItem siSum;
		siSum.Assignment(siSum.Add(si1, si2));
		siSum.PutValue();
	}
	else{
		si1.PutValue();
		si2.PutValue();
	}

	return 0;
}