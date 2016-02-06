#ifndef Fund_H
#define Fund_H

#include <string>
using namespace std;

class Fund
{
public:
	Fund();

	int GetId() const;
	void SetId(int v);
	double GetAmount() const;
	void SetAmount(double amt);

	// description of the fund
	string Desc() const;

private:
	int id;
	double amount;
};

#endif
