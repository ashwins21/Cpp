#pragma once
//#include "FuturePrice.h"
#include <vector> 
using std::vector;

class Indicator
{
public:
	virtual int GetSignal(FuturePrice p, vector<double>v) const=0;
	virtual Indicator* clone() const = 0;
	Indicator() {};
};
