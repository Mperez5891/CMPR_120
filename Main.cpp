/*
 *  Manuel Perez
 *  9/9/2015
 *  Homework 01 - A Poem
 *
 *  Write a program that outputs your
 *  name, a poem, and its author
 */

#include <iostream>
using namespace std;

int main() {
	// 1 Main Output
	//////////////////////////////////
	cout << "Dreams by Lagnston Hughes" << endl;
	cout << endl;
	cout << "Hold fast to dreams \n"
			"For if dreams die   \n"
			"Life is a broken-winged bird \n"
			"That cannot fly" << endl;
	cout << endl;
	cout << "Hold fast to dreams \n"
			"For when dreams go  \n"
			"Life is a barren field \n"
			"Frozen with snow" << endl;
	cout << endl;
	cout << "Programmed by Manuel Perez" << endl;
	// 2 Finishing stuff
	//////////////////////////////////

	// 2.1 pause
	// 2.1.1 prompt
	cout << "\nPress ENTER to finish..." << endl;
	// 2.1.2 wait for enter key
	cin.ignore(999, '\n');
	// 2.2 terminate
	return 0;
}
