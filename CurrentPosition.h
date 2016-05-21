#pragma once
#include<vector>
using std::vector;

class CurrentPosition{
public:
	CurrentPosition();
	vector <double,double,double> getPosition();
	void UpdatePosition(fix::msg);
	double GetPnL();
	void UpdatePnL(DataInput);

private:
	vector <int, long/* volume*/> position_;
	double cash_;
	double pnl_;
	vector <double,double> PnLList_;
}
