#pragma once
#include <vector>
using std::vector;


class FuturePrice
{
public:
	FuturePrice();
	void GetTrades(DataInput da, CurrentPosition& cur);
	//update current position and
	//append Pnl to list.
	vector <double,double>RollingMean(int time);
	vector <double,double>RollingStd(int time);
	vector <double,double>GetRollingTrades();
protected:
	vector <double,double>trades_;
	int time_;
	//vector <double,double>rollingMean_;
	//vector <double,double>rollingStd_;
}
