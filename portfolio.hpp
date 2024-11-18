#include "instrument.hpp"
#include <vector>

class Portfolio
{
private:
	vector<Instrument*> instruments;
public:
	Portfolio();
	~Portfolio() {}
	void addInstrument(Instrument* i);
	vector<Instrument*> getInstruments();
	void writeFile(string filename, double profit);
};