#include"MACD.h"

MACD::MACD(int n1, int n2, int m) :n1_(n1), n2_(n2), m_(m),numTrade_(0),last_(vector<double>(4)) {
};

int MACD::getn1() {
	return n1_;
};

MACD* MACD::clone() {
	return new MACD(n1_, n2_, m_);
}

void MACD::GetLast(FuturePrice &p) const{
	vector<double> pp = p.GetPrice();	
	vector<double> ema1(pp.size()-n1_+1);
	vector<double>ema2(pp.size()-n2_+1);
	vector<double>macd(ema1.size());
	vector<double>macdEma(macd.size()-m_+1);
	double avg=0.0;
	for (int i = 0; i < n1_; i++) {
		avg += pp[i];
	}
	ema1[0] = avg / (n1_);
	for (unsigned int i = 1; i < (pp.size()-n1_+1); i++) {

		double bb = ema1[i-1]*alpha + pp[i+n1_-1] * (1 - alpha);
		ema1[i] = bb;
	}
	for (int i = 0; i < n2_; i++) {
		avg += pp[i];
	}
	ema2[0] = avg / n2_;
	for (unsigned int i = 1; i < pp.size()-n2_ + 1; i++) {

		double cc = ema2[i - 1] * alpha + pp[i + n2_ - 1] * (1 - alpha);
		ema2[i] = cc;
	}
	for (unsigned int i = 0; i < macd.size(); i++) {
		macd[i] = ema1[i] - ema2[i+n1_];
	}
	for (int i = 0; i < m_; i++) {
		avg += macd[i];
	}
	macdEma[0] = avg / m_;
	for (unsigned int i = 1; i < macd.size() - m_; i++) {
		double dd = macdEma[i - 1] * alpha + macd[i + m_ - 1] * (1 - alpha);
		macdEma[i] = dd;
	}
	last_[0] = ema1[ema1.size() - 1];
	last_[1] = ema2[ema2.size() - 1];
	last_[2] = macd[macd.size() - 1];
	last_[3] = macdEma[macdEma.size() - 1];
	numTrade_ = p.GetNumTrade();
}

void MACD::Update(FuturePrice &p) const {
	int t1 = numTrade_ - p.GetNumTrade();
	vector<double> pp = p.GetPrice();
	if (t1 <= 0) {
		return;
	}
	
	else if (t1 >= 1 && t1<=50) {
		while (t1 > 0) {
			last_[0] = last_[0] * alpha + pp[pp.size() - t1] * (1 - alpha);
			last_[1] = last_[1] * alpha + pp[pp.size() - t1] * (1 - alpha);
			last_[2] = last_[1] - last_[0];
			last_[3] = last_[3] * alpha + last_[2] * (1 - alpha);
			t1 -= 1;
		}
	}
	else GetLast(p);
	numTrade_ = p.GetNumTrade();
}

int MACD::GetNumTrade() const{
	return numTrade_;
}

int MACD::GetSignal(FuturePrice &p) const{
	if (numTrade_ > 50) {
		Update(p);
	}
	else {
		GetLast(p);
	}
	if (last_[3] > 0 && last_[4] > 0) {
		return 1;
	}
	else if (last_[3] < 0 && last_[4] < 0) {
		return -1;
	}
	else return 0;

};