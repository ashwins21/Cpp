#include <iostream>
#include "PriceGenerator.h"
#include <Windows.h>

int main() {
	PriceGenerator priceGenerator;
	vector<onePrice> myPrices = priceGenerator.GeneratePrice(100);  //This is the final prices vector you want.
	for (auto iter = myPrices.cbegin(); iter != myPrices.cend(); ++iter) {
		Sleep(300);
		for (auto& i : *iter) {
			std::cout << "  " << i;
		}
		std::cout << std::endl;
	}
}