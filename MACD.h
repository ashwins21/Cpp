#pragma once
#include "Indicator.h"
#include <vector>
using std::vector;

class MACD :public Indicator {
public:
	//MACD();
	MACD(int n1 = 26, int n2 = 12, int m = 9);
	int getn1();
	virtual int GetSignal(FuturePrice &p) const;
	virtual MACD* clone();
private:
	int n1_;
	int n2_;
	int m_;

};