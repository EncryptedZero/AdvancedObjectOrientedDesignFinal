#pragma once
#include "Account.h"
#include "BankAccount.h"
#include <iostream>

/*
	UserAccount is the user's account as in like login/logout, but the user has their own bankAccount as well
	This would allow for the user to have a savings account or a checking account and be able to operate on both.
	Would just use a list of BankAccounts instead.
*/
class UserAccount : public Account{
	private:
		BankAccount bankAccount;
		void withdraw();
		void deposit();
		void printTransactionHistory();

	public:
		// Constructors/Destructor
		UserAccount(std::string pUsername, std::string pPassword, BankAccount bankAccount);
		UserAccount(UserAccount& pUserAccount);
		~UserAccount();

		// Overriden methods from Account
		void displayMenuOptions();
		void handleMenuSelection(int pMenuSelection);

		// Getters/Setters
		BankAccount getBankAccount();
		void setBankAccount(BankAccount pBankAccount);
};

