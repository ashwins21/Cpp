#pragma once
#include "Indicator.h"
#include "FuturePrice.h"
#include <vector>
using std::vector;

class MACD :public Indicator{
public:
	MACD(int n1=26, int n2=12, int m=9);
	virtual int GetSignal(FuturePrice &p,vector<double>v);
	virtual MACD* clone() const=0;
private:
	int n1_;
	int n2_;
	int m_;

};
