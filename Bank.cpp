
#include <iostream>
#include "Bank.h"
using namespace std;


Bank::Bank()
{
}


Bank::~Bank()
{
}

void Bank::Process(const Transaction& tr)
{
	if (tr.GetCode() == "O")
	{
		openAccount(tr);
	}
	else if (tr.GetCode() == "D")
	{
		Deposit(tr);
	}
	else if (tr.GetCode() == "W")
	{
		Withdraw(tr);
	}
	else if (tr.GetCode() == "T")
	{
		Transfer(tr);
	}
	else if (tr.GetCode() == "H")
	{
		History(tr);
	}
}

void Bank::Display() const
{
	tree.Display();
}

void Bank::openAccount(const Transaction& tr)
{
	if (tr.GetAccount().length() != 4)
	{
		cerr << "ERROR: Account " << tr.GetAccount()
			<< " is not valid. Transaction refused." << endl;
		return;

	}


	Account* result = new Account();
	result->SetFirstName(tr.GetFirstName());
	result->SetLastName(tr.GetLastName());
	result->SetNumber(tr.GetAccount());
	if (!tree.Insert(result))
	{
		cerr << "ERROR: Account " << tr.GetAccount()
			<< " is already open. Transaction refused." << endl;
		delete result;
	}
}

void Bank::Deposit(const Transaction& tr)
{
	Account info;
	Account* result = NULL;
	string acc = tr.GetAccount();
	string num = acc.substr(0, acc.length() - 1);
	info.SetNumber(num);

	if (!tree.Retrieve(info, result))
	{
		cerr << "ERROR: Account " << num
			<< " not found. Deposit refused." << endl;
		return;
	}
	result->Deposit(tr);
}

void Bank::Withdraw(const Transaction& tr)
{
	Account info;
	Account* result = NULL;
	string acc = tr.GetAccount();
	string num = acc.substr(0, acc.length() - 1);
	info.SetNumber(num);

	if (!tree.Retrieve(info, result))
	{
		cerr << "ERROR: Account " << num
			<< " not found. Withdraw refused." << endl;
		return;
	}
	result->Withdraw(tr);
}

void Bank::Transfer(const Transaction& tr)
{
	Account info;
	Account* from = NULL;
	Account* to = NULL;
	string acc = tr.GetAccount();
	string num = acc.substr(0, acc.length() - 1);
	info.SetNumber(num);

	if (!tree.Retrieve(info, from))
	{
		cerr << "ERROR: Account " << num
			<< " not found. Transferal refused." << endl;
		return;
	}

	string acc2 = tr.GetAccount2();
	string num2 = acc2.substr(0, acc2.length() - 1);
	info.SetNumber(num2);

	if (!tree.Retrieve(info, to))
	{
		cerr << "ERROR: Account " << num2
			<< " not found. Transferal refused." << endl;
		return;
	}

	if (from->Transfer(tr, true))
	{
		to->Transfer(tr, false);
	}
}

void Bank::History(const Transaction& tr)
{
	Account info;
	Account* result = NULL;
	string acc = tr.GetAccount();
	string num = acc;
	int pos = -1;
	if (acc.length() > 4)
	{
		num = acc.substr(0, acc.length() - 1);
		pos = acc.at(4) - '0';
	}
	info.SetNumber(num);

	if (!tree.Retrieve(info, result))
	{
		cerr << "ERROR: Account " << num
			<< " not found. Transaction refused." << endl;
		return;
	}
	result->History(pos);
}
