// CoreData.h

// Guard to prevent errors such as duplication
#pragma once

#include <string>
#include <list>
#include "UserAccount.h"
#include "BankAccount.h"

// CoreData class for reading/translating JSON data to objects our program can use.
// Uses singleton design, don't want to be editing the data from multiple places with different instances out there. 
class CoreData {
private:
    // All of the users in the system
    std::list<UserAccount> users; 

    // For the currently logged in user
    UserAccount currentUser;

    // Private constructor only called first time it is ran
    CoreData();

    // Pulls user data
    void getUserData();
    // instance basically holds an instance of the class, so when a different part of the program wants to use it, the data is already loaded. 
    static CoreData* instance;

    void addUser(UserAccount pUserAccount);

public:
    // Public method to access the singleton instance
    static CoreData& getInstance();
    
    // Create a new user account, add it to user list, display success output, end workful
    void createNewUser(std::string pUsername, std::string pPassword, BankAccount pBankAccount);

    // Gets user from users, should verify username/password first.
    UserAccount getUser(std::string pUsername);

    // Checks users list for username
    bool isUsernameFound(std::string pUsername);
    bool isPasswordCorrect(std::string pUsername, std::string pPassword);

    // Getters/Setters
    UserAccount getCurrentUser();
    void setCurrentUser(UserAccount pCurrentUser);
};


