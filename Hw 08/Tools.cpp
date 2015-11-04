// Tools.cpp

#include"Tools.h"
#include<iostream>
#include<string>
using namespace std;

int larger( int A, int B )
{
	return (A > B) ? A : B;
}

int smaller( int A, int B )
{
	return (A < B) ? A : B;
}

int getBoundedInt( string prompt, int lowBound, int highBound )
{
	while (true)
	{
		int userInput = getInt( prompt );
		if ( userInput >= lowBound && userInput <= highBound )
			return userInput;
		cout << "Value must be in the range ["
			<< lowBound << ".." << highBound << "]. Try again." << endl;
	}
}

bool getBool( string prompt )
{
	while (true)
	{
		char userInput = getChar( prompt );
		switch (userInput)
		{
		case 'y': case 'Y': return true;
		case 'n': case 'N': return false;
		default:
			cout << "please enter Y or N" << endl;
		}
	}
}

int getInt( string prompt )
{
	while (true)
	{
		int userInput;
		cout << prompt;
		cin >> userInput;
		flush();
		if ( !cin.fail() ) return userInput;
		cin.clear();
		flush();
		cout << "non-integer format - try again" << endl;
	}
}

char getChar( string prompt )
{
	while (true)
	{
		char userInput;
		cout << prompt;
		cin >> userInput;
		flush();
		if ( !cin.fail() ) return userInput;
		cin.clear();
		flush();
		cout << "input failure - try again" << endl;
	}
}

float getFloat( string prompt )
{
	while (true)
	{
		float userInput;
		cout << prompt;
		cin >> userInput;
		flush();
		if ( !cin.fail() ) return userInput;
		cin.clear();
		flush();
		cout << "non-float format - try again" << endl;
	}
}

int numberWidth( int number )
{
	int countSpaces = 1; // for the first digit
	int digits = number;
	if ( digits < 0 )
	{
		++countSpaces; // for the sign
		digits = -digits;
	}
	for ( 
			; digits > 9
			; digits /= 10 )
		++countSpaces;
	return countSpaces;
}

//int getNonnegativeInt( string prompt )
//{
//	return getBoundedInt( prompt, 0, INT_MAX );
//}
//
//int getPositiveInt( string prompt )
//{
//	return getBoundedInt( prompt, 1, INT_MAX );
//}

void flush(void)
{
	cin.ignore(999,'\n');
}

void pause(void)
{
	cout << "Press ENTER to finish...";
	cin.ignore(999,'\n');
}

