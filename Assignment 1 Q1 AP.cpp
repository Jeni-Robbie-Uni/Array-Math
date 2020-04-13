
/**
****************************************************************************************************
File: Assignment1 Q1 AP.cpp
Author : <Jeni Robbie>
Assignment 1- Question 1
Program description:
Program allows math calculations to be performed on large integers(up to 50 digits) by using an integer array. 
This is due to the int data type being unable to hold that more than 9 or 10 because of memory allocation. 
The program takes in two positive numbers and subtracts the second number from the first number and prints the answer.


Date Created : 09 / 02 / 20
Last Modified 14/ 02 / 20
* ***************************************************************************************************
*/

#include "ArrayMath.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
    string inputNumber1 = "", inputNumber2 = "";

    int const asciiCharacter0 = 48, asciiCharacter9 = 57, maxLength = 50;   // Constants for input validation
    bool isNegative = false, exit = false; 
    string exitResponse;
    int arraySize = 0;

    int sizeDifference = 0; // Difference in length between the two input strings
    int* num1Array = NULL;  // input array 1
    int* num2Array = NULL;  // Input array 2
    int* resultArray = NULL;



    cout << "This program will calculate and display the difference between 2 positive integers (the first number entered minus the second) that are entered by the user." << endl;
    do {

        //Input and validation of 2 numbers as string
        cout << "Please enter the first integer (up to 50 digits)" << endl;
        inputNumber1 = getUserInputNumber(asciiCharacter0, asciiCharacter9, maxLength);
       
        cout << "Please enter the second integer (up to 50 digits)" << endl;
        inputNumber2 = getUserInputNumber(asciiCharacter0, asciiCharacter9, maxLength);

        // Check if validated strings are the same
        if (areEqual(inputNumber1, inputNumber2))
            cout << "The difference between the two integers is 0." << endl;
        else {
            // Calculate difference in input string lenths
            sizeDifference = findLengthDifference(inputNumber1, inputNumber2);

            // Determine arraysize from larger string length
            arraySize = findGreatestLength(inputNumber1, inputNumber2);

            // Dynamically allocating memory for number arrays
            num1Array = new int[arraySize];
            num2Array = new int[arraySize];
            resultArray = new int[arraySize];

            // Convert string to array
            intStringToArray(arraySize, inputNumber1, inputNumber2, sizeDifference, num1Array, num2Array);

            //Check if negative number
            isNegative = negativeNumber(arraySize, num1Array, num2Array);

            //subtraction calculation
            if (!isNegative)
            {
                // Subtract array 2 from array 1
                arraySubtraction(arraySize, num1Array, num2Array, resultArray);
            }
            else
            {
                // Subtract array 1 from array 2
                arraySubtraction(arraySize, num2Array, num1Array, resultArray);
            }

            //Print correct Number put in new array?
            printArray(arraySize, resultArray, isNegative);
        }

        //Allow the user to decide to exit or start again
        exitResponse = getExitOrContinueResponse();

        // Check for valid exit condition
        exit = validateExitResponse(exitResponse);

    } while (exit == false);

   return 0;

}

