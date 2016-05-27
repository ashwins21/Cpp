#include "DataVector.h"
//#include<iostream>
#include<iterator>



std::map<string, DataVector> datamap;

DataVector::DataVector(string symbol)
	:symbol_(symbol), VectorPrice_(vector<double>())

{};


void printmap() {
	cout << "printmap" << endl;
	for (auto it = datamap.begin(); it != datamap.end(); it++) {
		for (int i = 0; i < it->second.VectorPrice_.size(); i++) {
			cout << it->second.VectorPrice_[i]<<" " << endl;
		}
		cout << endl;
		
		//cout << it->second.symbol_<<endl;
	}
	//for (auto it = datamap.begin(); it != datamap.end(); it++) {
	//		cout << it->first << endl;
	//	}
	
}

void DataVector::update(DataStruct d)
{
	VectorPrice_.push_back(d.price_);
}

void updatemap(DataStruct d)
{
	if (datamap.find(d.symbol_) != datamap.end())
	{
		
		datamap[d.symbol_].update(d);
	}
	else
	{
		DataVector d1(d.symbol_);
		d1.update(d);
		datamap[d.symbol_] = d1;
		//datamap[d.id_] = d1;
		//d1.update(d);
		//cout << datamap[d.id_].VectorPrice_[0] << endl;
		//cout << datamap[d.id_].VectorPrice_[0]<<"hi" << endl;
	}
	//cout << datamap.size()<<"size"<<endl;
	//printmap();
};