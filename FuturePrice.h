#pragma once
#include <vector>
//#include "PriceGenerator.h"
//#include "CurrentPosition.h"
using std::vector;

class FuturePrice
{
public:
	FuturePrice(int n = 30);
	vector<vector<double>> GeneratePrice(int n);
	vector<double>GetPrice()const;
	int GetNumTrade()const;
protected:
	vector <vector<double>>prices_;
	int time_;
	int numTrade_;
	vector<double>price_;
};