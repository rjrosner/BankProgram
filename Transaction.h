#ifndef Transaction_H
#define Transaction_H

#include <string>
#include <iostream>
using namespace std;

class Transaction
{
public:
	Transaction();

	bool Load(istream& in);

	string GetCode() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetAccount() const;
	void SetAccount(string acc);
	string GetAccount2() const;
	void SetAccount2(string acc);
	double GetAmount() const;
	void SetAmount(double amt);

	bool GetFail() const;
	void SetFail(bool f);

	// return description
	void Display() const;

private:
	string code;
	string first;   // open account
	string last;
	string account;  
	string account2;  // transfer target
	double amount;
	bool fail;
};

#endif
