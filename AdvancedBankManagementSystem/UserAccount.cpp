#include "UserAccount.h"
#include "GeneralUtility.h"
#include "BankAccount.h"
#include "Transaction.h"
#include "Account.h"
#include <iostream>
#include <cstdlib>=


UserAccount::UserAccount(std::string pUsername, std::string pPassword, BankAccount pBankAccount)
	: Account(pUsername, pPassword)
{
	bankAccount = pBankAccount;
}

UserAccount::UserAccount(UserAccount& pUserAccount)
	: Account(pUserAccount.getUsername(), pUserAccount.getPassword())
{
	setBankAccount(pUserAccount.getBankAccount());
}

UserAccount::~UserAccount()
{
	std::cout << "The user has been eliminated." << std::endl;
}

// Implement UserAccount version of menu options
void UserAccount::displayMenuOptions()
{
	std::cout << std::endl;
	std::cout << "Welcome " << getUsername() << "! What would you like to do?" << std::endl;
	std::cout << "1. Balance Inquiry" << std::endl;
	std::cout << "2. Withdraw" << std::endl;
	std::cout << "3. Desposit" << std::endl;
	std::cout << "4. Print transaction history" << std::endl;
	std::cout << "5. Logout" << std::endl;
	std::cout << std::endl;

	// Just getting the user menu selection
	int menuSelection;
	std::cin >> menuSelection;
	handleMenuSelection(menuSelection);
}

// Handle menu selection on userAccount
void UserAccount::handleMenuSelection(int pMenuSelection)
{
	switch (pMenuSelection) {
		case 1:
			std::cout << "$" << bankAccount.getBalance() << std::endl;
			GeneralUtility::pauseOutput();
			displayMenuOptions();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			deposit();
			break;
		case 4:

			break;
		case 5:
			std::cout << "User " << getUsername() << " has been logged out." << std::endl;
			break;
	}
}

void UserAccount::deposit() {
	// First get how much they need to deposit
	double amount;
	std::cout << "How much would you like to deposit? " << std::endl;
	std::cin >> amount;

	// Error trapping
	if (amount <= 0) {
		std::cout << "Cannot deposit 0 or less dollars" << std::endl;
		return;
	}

	std::string memo;
	std::cout << "Add a memo or press enter to leave blank." << std::endl;
	std::cin >> memo;

	// Create transaction, add to transaction list. 
	Transaction tempTransaction(amount, memo);
	bankAccount.addTransaction(tempTransaction);

	// Display message
	std::cout << "You have successfully deposited $" << amount << std::endl;
	std::cout << "Your new balance is $" << bankAccount.getBalance();

	// Pausing to wait for input, then displaying menu options
	GeneralUtility::pauseOutput();
	displayMenuOptions();
}

// Printing in depth account log
void UserAccount::printTransactionHistory()
{
	// Just getting transactions 
	std::list<Transaction> transactions = bankAccount.getTransactions();

	// First displaying balance
	std::cout << "Current Balance: $" << bankAccount.getBalance() << std::endl;

	// Loop through transaction list and display transactions
	for (auto i = transactions.rbegin(); i != transactions.rend(); i++) {
		// literating through with rbegin and rend return a pointer, so we must get the value that is pointed to
		Transaction transaction = *i;
		
		// Displaying transactions, literating through like this goes in reverse order which is perfect as we want most recent transactions first.
		transaction.printTransactionDetails();
	}

	// Pausing to wait for input, then displaying menu options
	GeneralUtility::pauseOutput();
	displayMenuOptions();
}

void UserAccount::withdraw() {
	// First get how much they need to withdraw
	double amount;
	std::cout << "How much would you like to withdraw? " << std::endl;
	std::cin >> amount;

	// Easter eggs for when the professor is testing it :)
	if (amount == 0) {
		std::cout << "You want to withdraw zero dollars? Mmm okay, done." << std::endl;
		return;
	}

	if (amount < 0) {
		std::cout << "Trying to steal money I see, get a day job." << std::endl;
		return;
	}

	// Make sure the user has enough menu.
	if (amount > bankAccount.getBalance()) {
		std::cout << "Account only contains " << bankAccount.getBalance() << ". Cannot preform withdrawal." << std::endl;
		return;
	}

	// Change to negative after guard statement, we don't keep information on withdrawals vs deposits just positive or negative values
	amount *= -1;

	std::string memo;
	std::cout << "Add a memo or press enter to leave blank." << std::endl;
	std::cin >> memo;

	// Create transaction, add to transaction list. 
	Transaction tempTransaction(amount, memo);
	bankAccount.addTransaction(tempTransaction);

	// Pausing to wait for input, then displaying menu options
	GeneralUtility::pauseOutput();
	displayMenuOptions();
}

BankAccount UserAccount::getBankAccount()
{
	return bankAccount;
}

void UserAccount::setBankAccount(BankAccount pBankAccount)
{
	bankAccount = pBankAccount;
}
