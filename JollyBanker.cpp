//JollyBanker MAIN FILE**

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
#include "Transaction.h"
#include "Bank.h"

int main()
{
	// phrase 1, load transaction
	ifstream infile("BankTrans.txt");
	queue<Transaction> trans;
	Transaction tmp;

	while (tmp.Load(infile))
		trans.push(tmp);
	infile.close();

	// phrase 2, process
	Bank bank;
	while (!trans.empty())
	{
		bank.Process(trans.front());
		trans.pop();
	}

	// phrase 3, display accounts
	cout << endl;
	cout << "Processing Done. Final Balances" << endl;
	bank.Display();

	
	return 0;
}
