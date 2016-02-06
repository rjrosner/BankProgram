#ifndef Account_H
#define Account_H

#include <queue>
#include "Fund.h"
#include "Transaction.h"
using namespace std;

class Account
{
public:
	Account();

	string GetNumber() const;
	string GetFirstName() const;
	string GetLastName() const;

	void SetNumber(string num);
	void SetFirstName(string name);
	void SetLastName(string name);

	void Display() const;

	void Deposit(const Transaction& tr);
	void Withdraw(const Transaction& tr);
	bool Transfer(const Transaction& tr, bool from);
	void History(int pos);
private:
	void FundHistory(int pos);

	bool Withdraw(int pos, double amount);

	Fund funds[10];
	queue<Transaction> history[10];

	string first;
	string last;
	string number;
};
#endif


