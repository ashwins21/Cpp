#pragma once
class MakeOrder {
public:
	MakeOrder(int ticker, int signal, double volume, bool market);
	//fix Order();
private:
	int ticker_;
	int signal_;
	double volume_;
	bool market_;
};
