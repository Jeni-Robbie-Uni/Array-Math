/***************************************************************************************************
File: ArrayMath.cpp
Author : <Jeni Robbie>
Assignment 1- Question 1
Description: Function definitions
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/


#include "ArrayMath.h"

// Validates string length is up to 50 characters
bool inputSizeValidation(string userInput, const int maxLength) {
    // if inout length is longer than max, display error
    if (userInput.length() > maxLength)
    {
        cout << "Invalid length. Please enter a positive integer with less than 51 digits" << endl;
        return false;
    }
    else
    {
       return true;
    }
}
// Validates that inputs are characters between 0 and 9
bool asciiRangeValidation(string userInput, int smallest, int largest) {
    // If input is not a character between 0 and 9, display error
    for (int i = 0; i < userInput.length(); i++)
    {
        int intval = (int)userInput[i]; // Convert character into corresponding ascii integer
        if (intval < smallest || intval > largest)
        {
            cout << "Invalid input. Please enter a positive integer with less than 51 digits" << endl;
            return false;
        }
    }
    return true;
}

// Compares two integer arrays to check if the difference will be a negative number
bool negativeNumber(const int aSize, int array1[], int array2[])
{
    bool isNegative = true;
    for (int i = 0; i < aSize; i++)
    {
        // if character at this position in array1 is larger than the same integer at this index, 
        if (array1[i] > array2[i])
        {
            isNegative = false;
            break;
        }
        else if (array1[i] < array2[i])
        {
            isNegative = true;
            break;
        }
    }
    return isNegative;
}
// Subtracts two arrays of integers as if they are whole numbers
void arraySubtraction(const int aSize, int array1[], int array2[], int results[])
{
    int count = aSize - 1;
    while (count >= 0)
    {
        // if the int at this index in array 1 is less than the same in array 2, subtract from next unit, and add 10 to the current array1 number
        if (array1[count] < array2[count])
        {
            array1[count - 1] -= 1;
            array1[count] += 10;
            results[count] = array1[count] -array2[count];
        }
        else
        {
            results[count] = array1[count] - array2[count];
        }

        count--;
    }
}

// Converts a string representation of an integer into an array of integers
void intStringToArray(const int aSize, string input1, string input2, int sDifference, int array1[], int array2[])
{
    for (int x = 0; x < aSize; x++)
    {
        // Determine which string is longer and add leading 0s as appropriate
        if (input1.length() <= input2.length())
        {
            array2[x] = (input2[x] - '0');  // convert character to integer
            // Add leading 0s to the smaller number
            if (x < sDifference)
            {
                array1[x] = 0;
            }
            else
            {
                int v = x - sDifference;
                array1[x] = (input1[v] - '0');
            }
        }
        else
        {
            array1[x] = (input1[x] - '0');  // convert character to integer
            // Add leading 0s to the smaller number
            if (x < sDifference)
            {
               array2[x] = 0;
            }
            else
            {
                int v = x - sDifference;
                array2[x] = (input2[v] - '0');

            }
        }

    }
}
// Prints an arrayy of numbers with negative sign if necessary
void printArray(const int aSize, int result[], bool negative)
{
    cout << "The difference between the first integer and second integer added is : ";
    if (negative == true)
        cout << "-";

    int startPos = 0;   // Indicates starting index of array, without leading 0s

    // Determine where to start printing to ignore leading 0s
    for (int i = 0; i < aSize; i++)
    {
        if (result[i] == 0)
            startPos += 1;
        else
            break;
    }

    for (int i = startPos; i < aSize; i++)
    {
        cout << result[i];
    }
    
    cout << endl;
}

// Requests user input for exit condition
string getExitOrContinueResponse()
{  
    string response;
    cout << "Do you want to start again? Enter y for yes or any other key to exit." << endl;
    cin >> response;
    return response;

}

// Validates the exit condition
bool validateExitResponse(string userinput) {
    // Only accept single character responses
    if (userinput.length() > 1)
        return true;
    else if (userinput == "Y" || userinput == "y")  // Accepts case insensitive input
        return false;
    else
        return true;

}
// Gets user input
string getUserInputNumber(int asciiChar1, int asciiChar2, int maxLength)
{
    string input;
    bool charValid;
    bool sizeValid=true;
    do
    {
        cin >> input;

        charValid = asciiRangeValidation(input, asciiChar1, asciiChar2);
        if (charValid == false)     // Stop loop early if initial validation fails
            continue;
        sizeValid = inputSizeValidation(input, maxLength);

    } while (sizeValid == false || charValid == false);

    return input;
}
// Checks whether two strings are identical 
bool areEqual(string input1, string input2) {
    if (input1 == input2)
        return true;
    else
        return false;
}
// Finds different in number of characters between two strings
int findLengthDifference(string input1, string input2) {
    int temp = input1.length() - input2.length();
    return abs(temp);   // Returns only non-negative numbers
}

// Returns the length of the longer string
int findGreatestLength(string input1, string input2) {
    if (input1.length() >= input2.length())
        return input1.length();
    else
        return input2.length();
}