/******************************************************************************
Write a program that will continuously ask the user for positive integers 
(until the user enters a negative integer at which the program will be terminated). 
Every time the user inputs a positive integer the program will print out this 
integer in reverse. Your program must have a function that accepts an integer 
and returns an integer in reverse. To convert the integer to its reverse, your 
main function will call this function. Name your program file as reverse.cpp
*******************************************************************************/
#include <iostream>

using namespace std;

//function prototypes
int main(void);
int reverse(int number);

//function definitions
int main(void)
{
    int number, revnumber;
    
    do {
        cout << endl << endl << "Enter an integer: ";
        cin >> number;
        if (number >= 0) {
            revnumber = reverse(number);
            cout << "Reversed Number = " << revnumber;
        }
    } while (number >= 0);
    
    return 0;
}

int reverse(int number)
{
    int reversedNumber = 0;
    int rem;

    while(number != 0) {
        rem = number % 10;
        reversedNumber = reversedNumber * 10 + rem;
        number /= 10;
    }
    
    return reversedNumber;
}
