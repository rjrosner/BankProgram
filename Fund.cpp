#include "Fund.h"


Fund::Fund()
{
	id = 0;
	amount = 0;
}

int Fund::GetId() const
{
	return id;
}

void Fund::SetId(int v)
{
	id = v;
}

double Fund::GetAmount() const
{
	return amount;
}

void Fund::SetAmount(double amt)
{
	amount = amt;
}

string Fund::Desc() const
{
	string names[10] = {
		"Money Market",
		"Prime Money Market", 
		"Long-Term Bond",
		"Short-Term Bond",
		"500 Index Fund",
		"Capital Value Fund",
		"Growth Equity Fund",
		"Growth Index Fund",
		"Value Fund",
		"Value Stock Index"
	};
	if (id >= 0 && id < 10)
		return names[id];
	return "";
}
