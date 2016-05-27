#pragma once
#include<iostream>
#include "DataStruct.h"
#include <vector>
#include <map>
using std::cout;
using std::endl;

using std::vector;
using std::map;


struct DataVector
{
	DataVector() {} ;
	DataVector(string symbol);
	void update(DataStruct d);

	string symbol_;
	vector<double> VectorPrice_;

};




void printmap();

void updatemap(DataStruct d);
