// Manuel Perez
// 2/25/2016
// Homework 01 - My Poem
// This program outputs a poem.

#include <iostream>

using namespace std;

int main(void)
{
	// 1 Poem
	
	// 1.1 Title and Author
	cout << "\"Masks\"" << endl;
	cout << "by Shel Silverstein" << endl;
	
	// Spacing
	cout << endl;
	
	// 1.2 Body
	cout << "She had blue skin," << endl;
	cout << "And so did he." << endl;
	cout << "He kept it hid" << endl;
	cout << "And so did she." << endl;
	cout << "They searched for blue" << endl;
	cout << "Their whole life through, " << endl;
	cout << "Then passed right by--" << endl;
	cout << "And never knew. " << endl; 
	
	// Spacing
	cout << endl;

	// 2 Sign Off
	cout << "Programmed by Manuel Perez." << endl;

	// Spacing 
	cout << endl;

	// 3 Pause and Terminate
	cout << "Please press ENTER to terminate...";
	cin.ignore(999, '\n');

	return 0;
}