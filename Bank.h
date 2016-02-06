#ifndef Bank_H
#define Bank_H

#include "Account.h"
#include "BSTree.h"
#include "Transaction.h"

class Bank
{
public:
	Bank();
	~Bank();

	void Process(const Transaction& tr);
	void Display() const;

	// transactions
	void openAccount(const Transaction& tr);
	void Deposit(const Transaction& tr);
	void Withdraw(const Transaction& tr);
	void Transfer(const Transaction& tr);
	void History(const Transaction& tr);

private:
	BSTree tree;
}; 

#endif
