/**
 * CS 100: lab 1: buggy program 1
 * 
 * This program reads in a list of grades, calculates the average, and prints 
 * it to the terminal.
 * 
 * Create your own inputs to test the program and make sure it runs correctly.
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std; // correction

int main()
{
    int grade;
    // correction both numberOfGrades and totalGrades set to 0
    int numberOfGrades = 0;
    int totalGrades = 0;
    float averageGrade;
    ifstream inputFile;

    const int SENTINEL = -999;

    // Open the input file
    inputFile.open("gradesen.dat");

    // Read in the grades, total them, and count how many grades there are
    // Stop the loop when the sentinel is read
    inputFile >> grade;
    while (grade != SENTINEL)
    {
        cout << "Grade is:  " << grade << endl;
        totalGrades = totalGrades + grade;
        numberOfGrades = numberOfGrades + 1;
        inputFile >> grade;
    }

    // Calculate and print the average
    averageGrade = totalGrades / static_cast<float>(numberOfGrades);//float
    cout << setiosflags(ios::fixed);
    cout << setiosflags(ios::showpoint);
    cout << setprecision(1);
    cout << "The average grade for the exam is :  " << averageGrade << endl;
}
