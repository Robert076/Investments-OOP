#include "portfolio.hpp"
#include <fstream>
#include <algorithm>

Portfolio::Portfolio()
{
	this->instruments = vector<Instrument*>();
	this->addInstrument(new Option("Option1", 10, 20, 15, "CALL"));
	this->addInstrument(new Option("Option2", 15, 10, 12, "PUT"));
	this->addInstrument(new Stock("Stock1", 100, 200, 300));
	this->addInstrument(new Stock("Stock2", 100, 20, 400));
}

void Portfolio::addInstrument(Instrument* i)
{
	this->instruments.push_back(i);
}

vector<Instrument*> Portfolio::getInstruments()
{
	return this->instruments;
}

static bool f(Instrument* a, Instrument* b)
{
	return a->computeProfit() < b->computeProfit();
}

void Portfolio::writeFile(string filename, double profit)
{
	ofstream fout(filename);
	vector<Instrument*> i = this->getInstruments();
	sort(i.begin(), i.end(), f);
	for (auto x : i)
		if (x->computeProfit() < profit)
			fout << x->computeProfit() << " | " <<  x->toString();
}