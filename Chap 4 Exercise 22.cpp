/*  Program File Name: Chapter 4 Exercise 22
    Programmer: Christian Min
    Date: 10/18/26
    Requirements:
    Write a program that calculates a customer's monthy bill. It should input the customer name, which plan was purchased, and how many gigabytes were
    used. it should then create a bill that inclides thje input information and the total amount due. it should also display how much money plan A customers
    would save if they purchased plan b or c, and how much money plan b customers would save if they purchased plan c. If there would be no savings, no
    message should be printed. wherever possible, use named constants intead of numbers.

*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    const double planACost = 39.99;     //set the constants for the info regarding plan A
    const double planAProvided = 2.00;
    const double planAAdditional = 8.00;

    const double planBCost = 59.99;     //set the constants for the info regarding plan B
    const double planBProvided = 8.00;
    const double planBAdditional = 8.00;

    const double planCCost = 79.99;     //set the constant (flat rate) for the cost of plan C

    string customerName;        //sets the string to contain the entered name of the customer, sets the char (a, b, or c) for which plan was chosen, and the value for the variable of the amount of data used in gb
    char planPurchased;
    double dataUsed;

    cout << "Enter your name: ";
    getline(cin, customerName);

    cout << "Enter the plan you have purchased (A, B, or C, in UPPERCASE): ";
    cin >> planPurchased;

    cout << "Enter the amount of data used in gigabytes: ";
    cin >> dataUsed;

    if (dataUsed < 0) {     //*input validation, the amount of data used in any of the plans cannot be 0 or below
        cout << "\n" << "The amount of the data used in your plan cannot be below 0!" << "\n";
        return 1;
    }

    double planAActual = planACost;     //calculate the total for the bill assuming the user chose plan A
    if (dataUsed > planAProvided) {
        planAActual += (dataUsed - planAProvided) * planAAdditional;
    }

    double planBActual = planBCost;     //calculate the total for the bill assuming the user chose plan B
    if (dataUsed > planBProvided) {
        planBActual += (dataUsed - planBProvided) * planBAdditional;
    }

    double planCActual = planCCost;     //calculate the total for the bill assuming the uiser chose plan C

    double billTotal = 0;       //calculates the total for the bill for each plan, and place it into a new variable to use for comparison later
    if (planPurchased == 'A') {
        billTotal = planAActual;
    }
    else if (planPurchased == 'B') {
        billTotal = planBActual;
    }
    else if (planPurchased == 'C') {
        billTotal = planCActual;
    }
    else {
        cout << "The plan you entered does not fall into the given choices of A, B, or C!";
        return 1;
    }

    cout << fixed << setprecision(2) << endl;       //set the precision to 2 places, to format the output variables
    cout << "Customer name: " << customerName << endl;
    cout << "The plan you have purchased is plan " << planPurchased << endl;
    cout << "The amount of data you have used is: " << dataUsed << " gigabytes" << endl;
    cout << "The total on your bill comes out to $" << billTotal << endl;

    if (planPurchased == 'A') {     //calculate the potential savings for plans b and c if the user chose plan a
        if (planBActual < planAActual) {
            cout << "\n" << "If you switched to plan B, you could save $" << (planAActual - planBActual) << "!" << endl;
        }
        if (planCActual < planAActual) {
            cout << "If you switched to plan C, you could save $" << (planAActual - planCActual) << "!" << endl;
        }
    }
    else if (planPurchased == 'B') {        //calculate the potential savings for plan c if the user choise plan b
        if (planCActual < planBActual) {
            cout << "\n" << "If you switched to plan C, you could save $" << (planBActual - planCActual) << "!" << endl;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
