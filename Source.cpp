#include<iostream>
#include"MACD.h"
#include "Indicator.h"
using std::cout;
using std::endl;


int main() {
	FuturePrice f1;
	MACD macd1(1, 2, 3);
	cout << macd1.getn1() << endl;
	cout << macd1.GetSignal(f1) << endl;
}