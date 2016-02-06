#include <iostream>
#include "Transaction.h"
using namespace std;

Transaction::Transaction()
{
	amount = 0;
	fail = false;
}

bool Transaction::Load(istream& in)
{
	code = "";
	in >> code;
	if (code == "O")
	{
		in >> last >> first >> account;
	}
	else if (code == "D")
	{
		in >> account >> amount;
	}
	else if (code == "W")
	{
		in >> account >> amount;
	}
	else if (code == "T")
	{
		in >> account >> amount >> account2;
	}
	else if (code == "H")
	{
		in >> account;
	}
	else
	{
		return false;
	}
	return true;
}

string Transaction::GetCode() const
{
	return code;
}

string Transaction::GetFirstName() const
{
	return first;
}

string Transaction::GetLastName() const
{
	return last;
}

string Transaction::GetAccount() const
{
	return account;
}

void Transaction::SetAccount(string acc)
{
	account = acc;
}

string Transaction::GetAccount2() const
{
	return account2;
}

void Transaction::SetAccount2(string acc)
{
	account2 = acc;
}

double Transaction::GetAmount() const
{
	return amount;
}

void Transaction::SetAmount(double amt)
{
	amount = amt;
}

bool Transaction::GetFail() const
{
	return fail;
}

void Transaction::SetFail(bool f)
{
	fail = f;
}

void Transaction::Display() const
{
	cout << code << " ";

	if (code == "O")
	{
		cout << last << " " << first << " " << account;
	}
	else if (code == "D")
	{
		cout << account << " " << amount;
	}
	else if (code == "W")
	{
		cout << account << " " << amount;
	}
	else if (code == "T")
	{
		cout << account << " " << amount << " " << account2;
	}
	else if (code == "H")
	{
		cout << account;
	}

}
