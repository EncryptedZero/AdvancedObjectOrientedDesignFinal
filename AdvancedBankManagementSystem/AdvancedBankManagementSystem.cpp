//AdvancedBankManagementSystem.cpp

#include "GeneralUtility.h"
#include "CoreData.h"
#include "CoreLogic.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    // Planning logic, commented out methods need more logic

    CoreData& CoreData = CoreData::getInstance();
    //dataUtility.initialDataLoad(); Only loads user data. 

    int x = 0;

    // 4 is exit
    while (x != 4) {
        // Display basic for options
        GeneralUtility::displayOptions();
        cin >> x;
        
        // Handling selection, all logic just returns here when the user is done or runs into an error. Then as long as they didn't
        // select 4, the loop continues. Note creating an account does not log the user in, the user will come back here and have to
        // select login
        CoreLogic::handleOptionSelection(x);
    }
    
    GeneralUtility::pauseOutput();
    GeneralUtility::exitProgram();
}