#include "CoreLogic.h"
#include "CoreData.h"
#include "GeneralUtility.h"
#include "BankAccount.h"
#include "Account.h"
#include "UserACcount.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>


 void CoreLogic::userLogin()
{
    // Declaring variables
    std::string pUsername, pPassword;
    CoreData coreData = CoreData::getInstance();

    std::cout << "Please enter username: ";
    std::cin >> pUsername;
    // if username is not found
    if (!coreData.isUsernameFound(pUsername)) {
        // breaks logic
        std::cout << "Username not found" << std::endl;
        return;
    }
            
    std::cout << "Please enter password: ";
    std::cin >> pPassword;
    if (!coreData.isPasswordCorrect(pUsername,pPassword)) {
        std::cout << "Password is incorrect, contact admin for password information." << std::endl;
        return;
    }

    coreData.setCurrentUser(coreData.getUser(pUsername));

    // Make sure to return pointer
    return;
}

void CoreLogic::createAccount()
{
    try {
        // Creating variable to use later 
        std::string pUsername;
        std::string pPassword;
        std::string pBankAccountType;

        // Getting instance of CoreData
        CoreData oCoreData = CoreData::getInstance();

        // Header
        std::cout << "Account Creation" << std::endl;

        // Getting username
        std::cout << "Please enter username: ";
        std::cin >> pUsername;

        // If pUsername is taken, put them in an infinite loop
        while(oCoreData.isUsernameFound(pUsername)) {
            std::cout << "Username taken" << std::endl;
            std::cout << "Please enter a different username: ";
            std::cin >> pUsername;
        }

        // Getting password
        std::cout << "Please enter password: ";
        std::cin >> pPassword;

        std::cout << "What type of account would you like to create?" << std::endl;
        std::cin >> pBankAccountType;

        // Creating an empty bankAccount
        BankAccount pBankAccount(pBankAccountType);

        // Add everything to the user
        oCoreData.createNewUser(pUsername, pPassword, pBankAccount);

        std::cout << "Account has successfully been created." << std::endl;
        GeneralUtility::pauseOutput();
    }
    catch (...) {
        std::cout << "An error was encountered while trying to create an account" << std::endl;
        GeneralUtility::pauseOutput();
    }
}

void CoreLogic::handleOptionSelection(int pOptionSelection) {
    // Creating a pointer to an account
    Account* CurrentAccount;

    // This is the outer menu's core logic, it is looped in the main 
    switch (pOptionSelection) {
    case 1:
        CoreLogic::userLogin();
        break;
    case 2:
        CoreLogic::createAccount();
        return;
    case 3:
        CurrentAccount = CoreLogic::managerLogin();
        break;
    case 4:
        GeneralUtility::exitProgram();
        return;
    default:
        return;
    }

    // Basicially can be null if logins fail.
    if(CurrentAccount == NULL){
        return;
    }
    // Should only get here from userLogin or managerLogin as the rest are return statements.
    
    // Gotta return the options value and if it's exit, break the loop/or just loop inside options and not out here.
    int x = 1;
    while (true) {
        // Might have to be careful with pointer, not sure how that works with methods
        CurrentAccount -> options;
    }
}