// GeneralUtility.cpp

// Call to header file
#include "GeneralUtility.h"
#include <iostream>
#include <cstdlib>
// Literally so the user can unpause output with any key instead of having to press enter. Better UX, we don't care about clunky code for our usages.
#include <conio.h>

using namespace std;

// Display's basic options
void GeneralUtility::displayOptions() {
    cout << "Please enter the number of your choice:" << endl;
    cout << "1. User Login" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Manager Login" << endl;
    cout << "4. Exit" << endl;
}


// Pause in output
void GeneralUtility::pauseOutput() {
    cout << "Press any key to continue..." << endl;

    // Wait for the user to press any key to continue logic. 
    _getch();
}

// Exits program
void GeneralUtility::exitProgram() {
    // Not sure if it needs to be a function but better than having to relook it up.
    exit(0);
}