#include "UserAccount.h"
#include "ManagerAccount.h"

// Guard to prevent errors such as duplication
#pragma once

/*
    A general utility class to basic non-data related utlities (see DataUtility.h/cpp).
    Static methods only currently.
*/
class CoreLogic {
private:
    static void userLogin();
    static void createAccount();
    static void managerLogin();
public:
    // Handles core logic
    static void handleOptionSelection(int pOptionSelection);
};