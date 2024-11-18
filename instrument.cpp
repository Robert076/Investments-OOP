#include "instrument.hpp"

Stock::Stock(string name, double buyPrice, double sellPrice, double shares)
{
	this->name = name;
	this->buyPrice = buyPrice;
	this->sellPrice = sellPrice;
	this->shares = shares;
}

double Stock::computeProfit()
{
	return (this->sellPrice - this->buyPrice) * this->shares;
}

string Stock::toString()
{
	stringstream buffer;
	buffer << "Name: " << this->name << " | Type: Stock | Buy Price: $" << this->buyPrice << " | Sell price: $" << this->sellPrice << " | Shares: " << this->shares << endl;
	return buffer.str();
}

Option::Option(string name, double buyPrice, double sellPrice, double strikePrice, string optionType)
{
	this->name = name;
	this->buyPrice = buyPrice;
	this->sellPrice = sellPrice;
	this->strikePrice = strikePrice;
	this->optionType = optionType;
}

double Option::computeProfit()
{
	if (this->optionType == "CALL")
		return this->sellPrice - this->strikePrice;
	else
		return this->strikePrice - this->buyPrice;
}

string Option::toString()
{
	stringstream buffer;
	buffer << "Name: " << this->name << " | Type: Option | Buy Price: $" << this->buyPrice << " | Sell price: $" << this->sellPrice << " | Strike price: " << this->strikePrice << " | Type: " << this->optionType << endl;
	return buffer.str();
}