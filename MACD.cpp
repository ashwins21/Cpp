#include"MACD.h"

MACD::MACD(int n1, int n2, int m) :n1_(n1), n2_(n2), m_(m) {
};

int MACD::getn1() {
	return n1_;
};

MACD* MACD::clone() {
	return new MACD(n1_, n2_, m_);
}

int MACD::GetSignal(FuturePrice &p) const {
	//if p.rollingmean


	return 0;
};