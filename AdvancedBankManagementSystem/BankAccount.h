#pragma once

#include <string>
#include <list>
#include "Transaction.h"

// Doesn't inheriet from Account.h, just a naming issue but this is the best name to describe the object.
class BankAccount
{
	private:
		std::string accountType;
		std::list<Transaction> transactions;

	public:
		BankAccount(std::string pAccountType);
		~BankAccount();

		std::string getAccountType();
		void setAccountType(std::string pAccountType);

		void setTransactions(std::list<Transaction> pTransactions);
		std::list<Transaction> getTransactions();

		// Calculates based off transactions
		double getBalance();

		//Methods to add transactions.
		void addTransaction(Transaction pTransaction);
};

