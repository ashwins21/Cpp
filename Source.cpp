#include<iostream>
#include"MACD.h"
#include "Indicator.h"

#include "Application.h"

#include <quickfix/Session.h>
using std::cout;
using std::string;
using std::endl;




int main() {
	MACD macd1(1, 2, 3);

}

struct info {
	//vector<double> prices;

	string stockExchange;
	string symbol;
	string securityType;
	string maturityMonthYear;
	FIX::Side side;
	FIX::OrdType ordType;
	FIX::Account acc;
	FIX::SessionID id;
};
struct portfolio {
	double cash;
	vector<position>quant;
};
struct position {
	int id;
	int pos;
	int cost;
};


void MakeMarketOrder(const info& p, double quantity) {
	FIX42::NewOrderSingle newOrder;

	newOrder.setField(FIX::ClOrdID(IdHelper::GetNextOrderId()));
	//newOrder.setField(FIX::HandlInst('1'));
	newOrder.setField(FIX::TransactTime());

	//component block: instrument
	newOrder.setField(FIX::SecurityExchange(p.stockExchange));
	newOrder.setField(FIX::Symbol(p.symbol));
	newOrder.setField(FIX::SecurityType(p.securityType));
	newOrder.setField(FIX::MaturityMonthYear(p.maturityMonthYear));

	//component block: trader
	newOrder.setField(FIX::Account(p.acc));
	newOrder.setField(FIX::Rule80A('A'));
	newOrder.setField(FIX::CustomerOrFirm(0));

	newOrder.setField(FIX::OrderQty(quantity));
	newOrder.setField(FIX::Side(p.side));
	newOrder.setField(FIX::OrdType(p.ordType));
	newOrder.setField(FIX::TimeInForce(FIX::TimeInForce_DAY)); //this is default value

	FIX::Session::sendToTarget(newOrder, p.id);
}


void makeorder(int signal, const position& pos1, const info& in, const portfolio& port) {
	if (signal == 1 && pos1.pos <= 0) {
		MakeMarketOrder(in,10.0);
	}
	else if (signal == 0&&pos1.pos!=0) {
		MakeMarketOrder(in, -pos1.pos);
	}
	else if (signal == -1 && pos1.pos >= 0) {
		MakeMarketOrder(in, -10);
	}
}


//int getQuantity(const position& pos1) {
//	return pos1.pos;
//}




