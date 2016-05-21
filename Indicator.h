#pragma once
#include<vector>
using std::vector;

class Indicator {
protected:
	int signal_;
};

class MACD :public Indicator {
public:
	vector<int> getSignal;
private:
};
