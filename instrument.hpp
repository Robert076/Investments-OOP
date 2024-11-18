#include <string>
#include <sstream>

using namespace std;

class Instrument
{
protected:
	string name;
	double buyPrice, sellPrice;
public:
	virtual double computeProfit() = 0;
	virtual string toString() = 0;
};

class Stock : public Instrument
{
private:
	double shares;
public:
	Stock(string name = "", double buyPrice = 0, double sellPrice = 0, double shares = 0);
	~Stock() {}
	double computeProfit();
	string toString();
};

class Option : public Instrument
{
private:
	double strikePrice;
	string optionType;
public:
	Option(string name = "", double buyPrice = 0, double sellPrice = 0, double strikePrice = 0, string optionType = "");
	~Option() {}
	double computeProfit();
	string toString();
};