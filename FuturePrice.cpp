#include"FuturePrice.h"

FuturePrice::FuturePrice(int n) {
	prices_ = vector<vector<double>>();
	prices_ = GeneratePrice(n);
}

vector<vector<double>> FuturePrice::GeneratePrice(int N)
{
	vector<vector<double>> temp;
	//vector<vector<double>> temp;
	temp.resize(N);
	for (auto i = 0; i < N; ++i)
	{
		temp[i].resize(4);
		temp[i][0] = 1;// int from 1 to 10
		temp[i][1] = i % 3; // int 1,2,3
		temp[i][2] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 100) + 50;
		temp[i][3] = 1900 + static_cast<double>(rand()) / RAND_MAX * 100;
	}
	return temp;
}
vector<double>FuturePrice::GetPrice() const{
	return price_;
}
int FuturePrice::GetNumTrade() const{
	return numTrade_;
}