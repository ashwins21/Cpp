#pragma once
#include <string>
#include <vector>


using std::vector;
using std::string;



struct DataStruct
{
	DataStruct(string symbol, double price, double quantity);

	string symbol_;
	double price_;
	double quantity_;


	//static int count_;

};



