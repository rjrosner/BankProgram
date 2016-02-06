//ROMMEL ROSNER

#include <iostream>
#include "Account.h"
using namespace std;

Account::Account()
{
	for (int i = 0; i < 10; i++)
	{
		funds[i].SetId(i);
		funds[i].SetAmount(0);
	}
}

string Account::GetNumber() const
{
	return number;
}

string Account::GetFirstName() const
{
	return first;
}

string Account::GetLastName() const
{
	return last;
}

void Account::SetNumber(string num)
{
	number = num;
}

void Account::SetFirstName(string name)
{
	first = name;
}

void Account::SetLastName(string name)
{
	last = name;
}

void Account::Display() const
{
	cout << first << " " << last << " Account ID: " << number << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "    ";
		cout << funds[i].Desc() << ": $" << funds[i].GetAmount() << endl;
	}
	cout << endl;
}

void Account::Deposit(const Transaction& tr)
{
	int pos = tr.GetAccount().at(4) - '0';
	funds[pos].SetAmount(funds[pos].GetAmount() + tr.GetAmount());
	history[pos].push(tr);
}

bool Account::Withdraw(int pos, double amount)
{
	if (funds[pos].GetAmount() >= amount)
	{
		funds[pos].SetAmount(funds[pos].GetAmount() - amount);
		return true;
	}

	if (pos > 3)
		return false;

	int pos2 = pos - 1;
	if (pos % 2 == 0)
		pos2 = pos + 1;

	if (funds[pos].GetAmount() + funds[pos2].GetAmount() < amount)
		return false;

	amount -= funds[pos].GetAmount();
	funds[pos].SetAmount(0);


	funds[pos2].SetAmount(funds[pos2].GetAmount() - amount);
	return true;
}

void Account::Withdraw(const Transaction& tr)
{
	int pos = tr.GetAccount().at(4) - '0';
	double oldAmt = funds[pos].GetAmount();

	if (Withdraw(pos, tr.GetAmount()))
	{
		if (oldAmt >= tr.GetAmount())
			history[pos].push(tr);
		else
		{
			Transaction tmp = tr;
			tmp.SetAmount(oldAmt);
			history[pos].push(tmp);

			tmp.SetAmount(tr.GetAmount() - oldAmt);
			int pos2 = pos - 1;
			if (pos % 2 == 0)
				pos2 = pos + 1;
			string acc2 = number + (char)(pos2 + '0');
			tmp.SetAccount(acc2);
			history[pos2].push(tmp);
		}
	}
	else
	{
		cerr << "ERROR: Not enough funds to withdraw "
			<< tr.GetAmount() << " from " << first << " "
			<< last << " " << funds[pos].Desc() << endl;
		Transaction tmp = tr;
		tmp.SetFail(true);
		history[pos].push(tmp);
	}

}

bool Account::Transfer(const Transaction& tr, bool from)
{
	int pos;
	if (!from)
	{
		pos = tr.GetAccount2().at(4) - '0';
		funds[pos].SetAmount(funds[pos].GetAmount() + tr.GetAmount());
		history[pos].push(tr);
		return true;
	}

	pos = tr.GetAccount().at(4) - '0';
	if (Withdraw(pos, tr.GetAmount()))
	{
		history[pos].push(tr);
		return true;
	}
	else
	{
		cerr << "ERROR: Not enough funds to transfer "
			<< tr.GetAmount() << " from " << first << " "
			<< last << " " << funds[pos].Desc() << endl;
		Transaction tmp = tr;
		tmp.SetFail(true);
		history[pos].push(tmp);
	}
	return false;
}

void Account::History(int pos)
{
	if (pos >= 0)
	{
		cout << "Transaction History for " << first << " "
			<< last << " " << funds[pos].Desc() << ": $"
			<< funds[pos].GetAmount() << endl;
		FundHistory(pos);
	}
	else
	{
		cout << "Transaction History for " << first << " "
			<< last << " by fund." << endl;
		for (int i = 0; i < 10; i++)
		{
			if (!history[i].empty())
			{
				cout << funds[i].Desc() << ": $" << funds[i].GetAmount() << endl;
				FundHistory(i);
			}
		}
	}
}

void Account::FundHistory(int pos)
{
	int sz = history[pos].size();
	for (int i = 0; i < sz; i++)
	{
		Transaction tr = history[pos].front();
		history[pos].pop();
		history[pos].push(tr);
		cout << "  ";
		tr.Display();
		if (tr.GetFail())
			cout << " (Failed)";
		cout << endl;
	}
}
