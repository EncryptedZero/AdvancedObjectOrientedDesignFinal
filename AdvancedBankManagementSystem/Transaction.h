//Transaction.h

#pragma once
#include <string>

class Transaction
{
	private:

		double amount;

		std::string date;

		std::string memo;
	public:
		Transaction(double pAmount, std::string pMemo);
		Transaction(Transaction& t);
		~Transaction();

		double getAmount();
		void setAmount(double pAmount);

		// date is autoset with constructor
		std::string getDate();

		std::string getMemo();
		void setMemo(std::string pMemo);

		// prints transaction's details
		void printTransactionDetails();
};

