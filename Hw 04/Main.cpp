// 9/30/2015
// Manuel Perez
// Homework 04 - Pass or No Pass
//
// This program is designed to figure out if a
// student passed off their test scores
//

#include <iostream>

using namespace std;

int LOWEST_POSSIBLE_PASS = 40;
int AVERAGE_TO_PASS = 50;

int main(void) {
	// 1 Input process
	// 1.1 Obtain the test scores
	cout << "Enter three test scores in range the range of (0-100)," << endl;
	cout << "separated by spaces: ";

	int test1, test2, test3;
	cin >> test1 >> test2 >> test3;
	cin.ignore(999, '\n');
	if (cin.fail()) {
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Input failure." << endl;
		cout << "Press ENTER to terminate program...";
		cin.ignore(999, '\n');
		return 1;
	}

	// 2 Arrange tests from lowest to largest
	int smallest, median, largest;

	// 2.1 method: start with a guess for the answer:
	smallest = test1;
	median = test2;
	largest = test3;

	// 2.2 improve this guess
	if (smallest > median) {
		// fix it: swap/exchange
		int exchangeValue = smallest;
		smallest = median;
		median = exchangeValue;
	}

	// at this point, I KNOW that smallest <= median
	if (median > largest) {
		// fix it: swap/exchange
		int exchangeValue = median;
		median = largest;
		largest = exchangeValue;
	}

	// at this point, I KNOW that smallest <= median, median <= largest
	// at this point, I do NOT know that smallest <= median
	// 2.3 so, check it AGAIN!
	if (smallest > median) {
		// fix it: swap/exchange
		int exchangeValue = smallest;
		smallest = median;
		median = exchangeValue;
	}

	// 3 Calculate test average
	int testTotal = test1 + test2 + test3;
	int numberOfTests = 3;
	int testTotalAverage = testTotal / numberOfTests;

	// 4 Pass or No Pass
	string passOrFail;
	if (smallest >= AVERAGE_TO_PASS && median >= AVERAGE_TO_PASS
			&& largest >= AVERAGE_TO_PASS) {
		passOrFail = "You pass!!";
	} else if (smallest >= LOWEST_POSSIBLE_PASS && median >= AVERAGE_TO_PASS
			&& largest >= AVERAGE_TO_PASS && testTotalAverage >= AVERAGE_TO_PASS) {
		passOrFail = "Pass by compensation";
	} else
		passOrFail = "Fail";

	// 5 Output
	/////////////////////////////////////////////////////////////////
	cout << "Grade: " << passOrFail << endl;
	/////////////////////////////////////////////////////////////////

	// 6 End Process
	cout << endl;
	cout << "Press enter to exit program: " << endl;
	cin.ignore(999, '\n');
	return 0;
}
