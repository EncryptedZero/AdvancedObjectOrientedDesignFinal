#include "Account.h"

Account::Account(std::string pUsername, std::string pPassword)
{
	username = pUsername;
	password = pPassword;
	isManagerAccount = false;
}

Account::Account(Account &pAccount)
{
	username = pAccount.getUsername();
	password = pAccount.getPassword();
}

std::string Account::getUsername()
{
	return username;
}

void Account::setUsername(std::string pUsername)
{
	username = pUsername;
}

std::string Account::getPassword()
{
	return password;
}

void Account::setPassword(std::string pPassword)
{
	password = pPassword;
}
