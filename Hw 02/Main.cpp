 //
 // Manuel Perez
 // 9/9/2015
 // Homework 02 - Mad Libs
 //
 //  This program takes input
 //  from the user and create a
 //  mad lib.
 //

#include <iostream>
#include <string>

using namespace std;

int main(void){
	// 1 Input
	// 1.1 Intro to program
	cout << "Welcome user. Let's make a mad lib!" << endl;
	cout << endl;

	// 1.2 Mad lib parts
	// 1.2.1 Obtain a friends name
	cout << "Input a friends full name: ";
	string friendName;
	cin >> friendName;
	cin.ignore(999, '\n');

	// 1.2.2 Obtain two -ing verbs
	cout << "Input two verbs ending with -ing: ";
	string ingVerb1 , ingVerb2;
	cin >> ingVerb1 >> ingVerb2;
	cin.ignore(999, '\n');

	// 1.2.3 Obtain a number
	cout << "Input a number: ";
	int number;
	cin >> number;
	cin.ignore(999, '\n');

	// 1.2.4 Obtain an adverb
	cout << "Input an adverb: ";
	string adverb;
	cin >> adverb;
	cin.ignore(999, '\n');

	// 1.2.5 Obtain an adjective
	cout << "Input an adjective: ";
	string adjective;
	cin >> adjective;
	cin.ignore(999, '\n');

	// 1.2.6 Obtain a full name
	cout << "Input another random full name: ";
	string staffMember;
	getline(cin, staffMember);

	// 1.2.7 Obtain a song name
	cout << "Input a song name: ";
	string songTitle;
	cin >> songTitle;
	cin.ignore(999, '\n');

	// 1.2.8 Obtain an instrument name
	cout << "Input an instrument: ";
	string instrument;
	cin >> instrument;
	cin.ignore(999, '\n');

	// 1.2.9 Obtain a relatives full name
	cout << "Input a relative: ";
	string relative;
	getline(cin, relative);

	// 1.2.10 Obtain users full name
	cout << "Input your name: ";
	string yourName;
	getline(cin, yourName);

	cout << endl;

	// 2 Output
	////////////////////////////////////////////////////////////////////////////////////
	cout << "Dear " << friendName << "," << endl;
	cout << endl;
	cout << "How are you? I miss you so much! Can you believe that its already been" << endl;
	cout << number << " months since we were together at camp?! It seems like just " << endl;
	cout << "yesterday we were " << ingVerb1 << ", and " << ingVerb2 << " in the hot Bruceville" << endl;
	cout << "sun. Those were the days! Sometimes when I miss camp, I like " << endl;
	cout << "to sit " << adverb << " in my room and think about all the " << endl;
	cout << adjective << " activities that we did together in the " << endl;
	cout << "bunk. Do you remember " << staffMember << "? They were my " << endl;
	cout << "favorite counselor, I hope they're coming back for " << endl;
	cout << "Summer 2016! Remember how much we loved dancing " << endl;
	cout << "and singing along to " << songTitle << " during the song session? Well " << endl;
	cout << "it's always in my head so I decided to learn how to " << endl;
	cout << "play it on the " << instrument << ". It sounds pretty good and " << endl;
	cout << "I'm thinking it will make a great talent show act for " << endl;
	cout << "next summer. Well my " << relative << "is calling me so I better " << endl;
	cout << "get going. Hope everything is great and I cannot wait " << endl;
	cout << "to see you soon! Only 7 months till next summer! " << endl;
	cout << endl;
	cout << "TTYL," << endl;
	cout << yourName << endl;

	/////////////////////////////////////////////////////////////////////////////////////

	// 3 End process
	// 3.1 pause
	// 3.1.1 prompt
	cout << endl;
	cout << "Press ENTER to finish..." << endl;
	// 3.1.2 wait for enter key
	cin.ignore(999, '\n');
	// 3.2 terminate
	return 0;
}
