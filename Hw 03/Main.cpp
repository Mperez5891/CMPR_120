
 // 9/23/2015
 // Manuel Perez
 // Homework 03 - Bill Generator
 //
 // This program will create a bill
 // for my flamenco class
 //

#include <iostream>
#include <iomanip>

using namespace std;

float SALES_TAX = 0.04;

int main(void)
{
	// 1 Input process
	// 1.1 Greeting
	cout << "Welcome to Manny's Flamenco class bill generator!!" << endl;
	cout << endl;
	cout << "Please input the following: " << endl;

	// 1.2 User inputs
	// 1.2.1 Input the hourly rate
	cout << setw(25) << left << "Instructor's Hourly rate" << "---> ";
	float hourlyRate;
	cin >> hourlyRate;
	cin.ignore(999, '\n');

	if ( cin.fail() )
	{
		cin.clear();
		cin.ignore(999,'\n');
		cout << "Input failure." << endl;
		cout << "Press ENTER to terminate program...";
		cin.ignore(999,'\n');
		return 1;
	}
	if ( hourlyRate < 0 )
	{
		cout << "Negative values not allowed. Terminating program." << endl;
		cout << "Press ENTER to finish...";
		cin.ignore(999,'\n'); // pause
		return 1;
	}

	// 1.2.2 Input the flat fee
	cout << setw(25) << left << "Costume fee" << "---> ";
	float  costumeFee;
	cin >>  costumeFee;
	cin.ignore(999, '\n');

	if ( cin.fail() )
	{
		cin.clear();
		cin.ignore(999,'\n');
		cout << "Input failure." << endl;
		cout << "Press ENTER to terminate program...";
		cin.ignore(999,'\n');
		return 1;
	}

	if ( costumeFee < 0 )
	{
		cout << "Negative values not allowed. Terminating program." << endl;
		cout << "Press ENTER to finish...";
		cin.ignore(999,'\n'); // pause
		return 1;
	}

	// 1.2.3 Input the minutes of service
	cout << setw(25) << left << "Total minutes instructed" << "---> ";
	int minutesOfService;
	cin >> minutesOfService;
	cin.ignore(999, '\n');

	if ( cin.fail() )
	{
		cin.clear();
		cin.ignore(999,'\n');
		cout << "Input failure." << endl;
		cout << "Press ENTER to terminate program...";
		cin.ignore(999,'\n');
		return 1;
	}

	if ( minutesOfService < 0 )
	{
		cout << "Negative values not allowed. Terminating program." << endl;
		cout << "Press ENTER to finish...";
		cin.ignore(999,'\n'); // pause
		return 1;
	}

	cout << endl;

	// 1.3 Calculating the total charges
	int hours = (minutesOfService + 59)/ 60;
	float instructionFee = hourlyRate * hours;
	float serviceTax = instructionFee * SALES_TAX;
	float totalCharges = costumeFee + instructionFee + serviceTax;

	cout << "Total charges: $"
			<< setprecision (2)
			<< setiosflags (ios::showpoint)
			<< setiosflags (ios::fixed)
			<< totalCharges << endl;

	// 1.4 Obtaining the tip
	float tip;
	cout << "Please enter your tip: ";
	cin >> tip;

	if ( cin.fail() )
	{
		cin.clear();
		cin.ignore(999,'\n');
		cout << "Input failure." << endl;
		cout << "Press ENTER to terminate program...";
		cin.ignore(999,'\n');
		return 1;
	}

	if ( tip < 0 )
	{
		cout << "Negative values not allowed. Terminating program." << endl;
		cout << "Press ENTER to finish...";
		cin.ignore(999,'\n'); // pause
		return 1;
	}

	// 1. 5 Calculate the total bill
	float totalBill = tip + totalCharges;

	// 2 Main Output
	//////////////////////////////////////////////////////////////////////
	cout << "===================================================" << endl;
	cout << setw (25) << left << "Costume Fee"
			<< "$"
			<< setw (10) << right
			<< setiosflags (ios::showpoint)
			<< setiosflags (ios::fixed)
			<< setprecision (2)
			<< costumeFee << endl;
	cout << setw (25) << left << "Instruction Fee"
			<< "$"
			<< setw (10) << right
			<< setiosflags (ios::showpoint)
			<< setiosflags (ios::fixed)
			<< setprecision (2)
			<< instructionFee << endl;
	cout << setw (25) << left << "Service Tax"
			<< "$"
			<< setw (10) << right
			<< setiosflags (ios::showpoint)
			<< setiosflags (ios::fixed)
			<< setprecision (2)
			<< serviceTax << endl;
	cout << setw (25) << left << "Tip"
			<< "$"
			<< setw (10) << right
			<< setprecision (2)
			<< setiosflags (ios::showpoint)
			<< setiosflags (ios::fixed)<< tip << endl;
	cout << setw(25) << left << " "
			<< setw (5) << right << "----------" << endl;
	cout << setw (25) << left << "Total Bill"
				<< "$"
				<< setw (10) << right
				<< setprecision (2)
				<< setiosflags (ios::showpoint)
				<< setiosflags (ios::fixed)
				<< totalBill << endl;
	cout << "===================================================" << endl;
	//////////////////////////////////////////////////////////////////////

	// 3 Departing message based on the tip
	if (tip < (totalCharges * .15))
			{
				cout << "Looks like Money Bags is in the building!!";
			}
	else if (tip >= (totalCharges * .15) && tip <= (totalCharges * .20))
			{
				cout << "Thank you and have a nice day.";
			}
	else if (tip > (totalCharges * .20))
			{
				cout << "Wow!! Thank you, please come back again.";
			}

	cout << endl;

	// 4 End process
	cout << endl;
	cout << "Press enter to exit program: " << endl;
	cin.ignore(999, '\n');
	return 0;
}
