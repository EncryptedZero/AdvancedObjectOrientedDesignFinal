// GeneralUtility.h

// Guard to prevent errors such as duplication
#pragma once

/*
    A general utility class to basic non-data related utlities (see DataUtility.h/cpp).
    Static methods only currently.
*/
class GeneralUtility {
private:
    
public:

    // Basic print options.
    static void displayOptions();

    // To pauseOutput such as "Create new user" "Press enter to continue"
    static void pauseOutput();

    // Exit the program 
    static void exitProgram();
};
