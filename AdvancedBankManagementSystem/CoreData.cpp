// CoreData.cpp
/*
    Purpose of this file is to hold all data in a singleton design. This is our working memory, then program is exited
    the user data should be saved to UserData.JSON
    Should contain internal methods for operating on data
    External data procressing will be handled in the FileUtility class
    Should not out put in this file
*/

#include "CoreData.h"
#include "GeneralUtility.h"
#include <string>

// Keep commented out, causes weird issues with string type mismatching in method parameters being this and header file
// using namespace std;

// Initialize the static instance to nullptr
CoreData* CoreData::instance = nullptr;

// Private constructor
CoreData::CoreData() {
    // None needed currenly
}

// Basic method to add user to use list
void CoreData::addUser(UserAccount pUserAccount)
{
    users.push_back(pUserAccount);
}

// Public method to access the singleton instance
CoreData& CoreData::getInstance() {
    // Create the instance if it doesn't exist
    if (instance == nullptr) {
        instance = new CoreData();
    }
    return *instance;
}

// Checks if user is in list users (users list isn't loaded correctly yet.)
bool CoreData::isUsernameFound(std::string pUsername) {
    // Loops through all users and compares to username
    for(UserAccount user : users) {
        if (user.getUsername() == pUsername) {
            return true;
        }
    }
    return false;
}

UserAccount CoreData::getCurrentUser()
{
    return currentUser;
}

void CoreData::setCurrentUser(UserAccount pCurrentUser)
{
    currentUser = pCurrentUser; 
}

bool CoreData::isPasswordCorrect(std::string pUsername, std::string pPassword) {
    // Loops through all users and compares to username
    for (UserAccount user : users) {
        if (user.getUsername() == pUsername) {
            if (user.getPassword() == pPassword) {
                return true;
            }
        }
    }
    return false;
}

// Create new user
void CoreData::createNewUser(std::string pUsername, std::string pPassword, BankAccount pBankAccount) {

    UserAccount newUser(pUsername, pPassword, pBankAccount);
    addUser(newUser);
}

UserAccount CoreData::getUser(std::string pUsername)
{
    for (UserAccount user : users) {
        if (user.getUsername() == pUsername) {
            return user;
        }
    }
}
