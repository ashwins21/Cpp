#pragma once
#include <vector>
#include <cmath>
#include <chrono>
using std::vector;

typedef vector<double> onePrice;

class PriceGenerator
{
public:
	vector<onePrice> GeneratePrice(int N);
private:

};