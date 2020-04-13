/***************************************************************************************************
File: ArrayMath.h
Author : <Jeni Robbie>
Description: function declarations for Advanced programming assignt 1 Q1
Date Created: 09/02/20
Last Modified: 14/02/20

/***************************************************************************************************/


#pragma once
#include <string>
#include<iostream>
using namespace std;

// Prints an arrayy of numbers with negative sign if necessary
void printArray(const int , int [], bool );

// Converts a string representation of an integer into an array of integers
void intStringToArray(const int, string, string, int, int[], int[]);

// Subtracts two arrays of integers as if they are whole numbers
void arraySubtraction(const int aSize, int [], int [], int []);

// Compares two integer arrays to check if the difference will be a negative number
bool negativeNumber(const int,  int[], int[]);

// Validates that inputs are characters between 0 and 9
bool asciiRangeValidation(string, int, int);

// Validates string length is up to 50 characters
bool inputSizeValidation(string, const int);

// Checks whether two strings are identical 
bool areEqual(string, string);

// Requests user input for exit condition
string getExitOrContinueResponse();

// Validates the exit condition
bool validateExitResponse(string);

// Gets user input
string getUserInputNumber(int, int, int);

// Finds different in number of characters between two strings
int findLengthDifference(string,string);

// Returns the length of the longer string
int findGreatestLength(string, string);