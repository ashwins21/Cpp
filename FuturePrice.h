#pragma once
#include <vector>
//#include "PriceGenerator.h"
//#include "CurrentPosition.h"
using std::vector;

class FuturePrice
{
public:
	FuturePrice(int n= 30);
	vector<vector<double>> GeneratePrice(int n);

protected:
	vector <vector<double>>prices_;
	int time_;
};