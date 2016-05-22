#pragma once
#include"FuturePrice.h"
#include <vector> 
using std::vector;

class Indicator
{
public:
	virtual int GetSignal(FuturePrice &p) const = 0;
	virtual Indicator* clone() = 0;
	Indicator() {};
};