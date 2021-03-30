

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

//Initiate constants as global variables

double usaUnder50 = 6.00;
double canUnder50 = 8.00;
double ausUnder50 = 10.00;
double usa50to100 = 9.00;
double can50to100 = 12.00;
double aus50to100 = 14.00;
double usa100to150 = 12.00;
double can100to150 = 15.00;
double aus100to150 = 17.00;
double marsUnder50 = 50.00;
double mars50to100 = 120.00;
double mars100to150 = 180.00;

int main()
{
    //Declare filestream variable and open file
    ofstream outData;
    outData.open("Order.txt");
    
    //Initiate local variables for user input
    
    string itemName;
    char fragile;
    double fragileFrgt;
    double orderTotal;
    string destination;
    string destinationOut;
    double freight;
    double grandTotal;

    //Begin console output

    cout << ".................................................." << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << ".................................................." << endl;
    cout << endl << endl;

    //Prompt user for input and assign to local variables

    cout << left << "Please enter the item name (no spaces)" << setw(12) << right << setfill('.') << ":";
    cin >> itemName;
    transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper); //Take any user input and make it all-caps.
    cout << left << "Is the item fragile? (y=yes/n=no)" << setw(17) << right << setfill('.') << ":";
    cin >> fragile;

    //Verify user input
    if (fragile == 'y' || fragile == 'Y')
    {
        fragileFrgt = 2.00; //If user input is "yes", add $2.00 fragile freight.
    }
    else if (fragile == 'n' || fragile == 'N')
    {
        fragileFrgt = 0.00; //If user input is "no", do not add fragile freight.
    }
    else 
    {
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 0; //If user does not enter proper input, return an int to the main function to end program.
    }

    //Continue user input
    cout << left << "Please enter your order total" << setw(21) << right << setfill('.') << ":";
    cin >> orderTotal;
    cout << left << "Please enter destination. (usa/can/aus/mars)" << setw(11) << right << setfill('.') << ":";
    cin >> destination;
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
    
    //Verify destination input
    if (destination != "AUS" && destination != "USA" && destination != "CAN" && destination != "MARS")
    {
        cout << endl;
        cout << "Invalid entry, exiting" << endl;
        system("pause");
        return 0; //Exit program if input is invalid.
    }
    else
    {
        destinationOut = destination; //Assign outbound variable to the user input.
    }

    //Calculate needed freight
    if (destination == "USA") //Freight to assign for USA
    {
        if (orderTotal <= 50.00)
        {freight = usaUnder50 + fragileFrgt;}
        else if (orderTotal >= 50.01 && orderTotal <= 100.00)
        {freight = usa50to100 + fragileFrgt;}
        else if (orderTotal >= 100.01 && orderTotal <= 150.00)
        {freight = usa100to150 + fragileFrgt;}
        else{freight = 0.00;}
    }
    else if (destination == "CAN") //Freight to assign for CAN
    {
        if (orderTotal <= 50.00)
        {freight = canUnder50 + fragileFrgt;}
        else if (orderTotal >= 50.01 && orderTotal <= 100.00)
        {freight = can50to100 + fragileFrgt;}
        else if (orderTotal >= 100.01 && orderTotal <= 150.00)
        {freight = can100to150 + fragileFrgt;}
        else
        {freight = 0.00;}
    }
    else if (destination == "AUS") //Freight to assign for AUS
    {
        if (orderTotal <= 50.00)
        {freight = ausUnder50 + fragileFrgt;}
        else if (orderTotal >= 50.01 && orderTotal <= 100.00)
        {freight = aus50to100 + fragileFrgt;}
        else if (orderTotal >= 100.01 && orderTotal <= 150.00)
        {freight = aus100to150 + fragileFrgt;}
        else
        {freight = 0.00;}
    }
    else if (destination == "MARS") //Freight to assign for MARS
    {
        if (orderTotal <= 50.00)
        {freight = marsUnder50 + fragileFrgt;}
        else if (orderTotal >= 50.01 && orderTotal <= 100.00)
        {freight = mars50to100 + fragileFrgt;}
        else if (orderTotal >= 100.01 && orderTotal <= 150.00)
        {freight = mars100to150 + fragileFrgt;}
        else
        {freight = 0.00;}
    }//(Tabs and extra Enters removed for consolidation)

    //Calculate total shipping costs
    grandTotal = orderTotal + freight;

    //Perform output to console
    cout << endl;
    cout << left << "Your item is" << setw(36) << right << setfill('.') << itemName << endl;
    cout << left << "Your shipping cost is" << setw(19) << right << setfill('.') << "$" << fixed << setprecision(2) << freight << endl;
    cout << left << "You are shipping to" << setw(23) << right << setfill('.') << destinationOut << endl;
    cout << left << "Your total shipping costs are" << setw(11) << right << setfill('.') << "$" << fixed << setprecision(2) << grandTotal << endl;
    cout << endl;
    cout << "----------------------------------------Thank you!" << endl;
    cout << endl;

    //Perform output to file.
    outData << left << "Your item is" << setw(36) << right << setfill('.') << itemName << endl;
    outData << left << "Your shipping cost is" << setw(19) << right << setfill('.') << "$" << fixed << setprecision(2) << freight << endl;
    outData << left << "You are shipping to" << setw(23) << right << setfill('.') << destinationOut << endl;
    outData << left << "Your total shipping costs are" << setw(11) << right << setfill('.') << "$" << fixed << setprecision(2) << grandTotal << endl;
    outData << endl;
    outData << "----------------------------------------Thank you!" << endl;
    system("pause");

    return 0;
}
