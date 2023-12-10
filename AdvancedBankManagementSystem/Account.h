#pragma once
#include <string>

class Account
{
	private:
		bool isManagerAccount;
		std::string username;
		std::string password;
	public:
		// Basic constructors
		Account(std::string pUsername, std::string pPassword);
		Account(Account &pAccount);
		~Account();

		// Getters/Setters
		std::string getUsername();
		void setUsername(std::string pUsername);

		std::string getPassword();
		void setPassword(std::string pPassword);

		// Virtual methods to be overwritten in sub classes
		virtual void displayMenuOptions();
		virtual void handleMenuSelection(int pMenuSelection);
};

