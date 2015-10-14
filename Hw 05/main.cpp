// 10/14/2015
// Manuel Perez
// Homework 05 - Lets play poker
//
// This program is designed to take three cards
// from the user and output what hand they have
//

#include <iostream>

using namespace std;

// Consts
int CARD_MIN = 1;
int CARD_MAX = 13;

int main(void)
{
	// 1. Input
	cout << "Lets play poker!!" << endl;
	bool weHaveCards = false;
	int card1, card2, card3;
	while (!weHaveCards)
	{
		cout << "Input three numbers between 1 - 13: ";
		cin >> card1 >> card2 >> card3;
		cin.ignore(999, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(999, '\n');
			cout << "Bad integer format, try again." << endl;
			cout << endl;
		} else if (card1 < CARD_MIN || card1 > CARD_MAX || card2 < CARD_MIN
				|| card2 > CARD_MAX || card3 < CARD_MIN || card3 > CARD_MAX)
		{
			cin.clear();
			cout << "Card out of range, try again." << endl;
			cout << endl;
		} else
			weHaveCards = true;
	}

	// 2. Process

	// 2.1 Put cards in order
	int smallestCard, medianCard, largestCard;

	// 2.1.1 method: start with a guess for the answer:
	smallestCard = card1;
	medianCard = card2;
	largestCard = card3;

	// 2.1.2 improve this guess
	if (smallestCard > medianCard)
	{
		// fix it: swap/exchange
		int exchangeValue = smallestCard;
		smallestCard = medianCard;
		medianCard = exchangeValue;
	}

	// at this point, I KNOW that smallest <= median
	if (medianCard > largestCard)
	{
		// fix it: swap/exchange
		int exchangeValue = medianCard;
		medianCard = largestCard;
		largestCard = exchangeValue;
	}

	// at this point, I KNOW that smallest <= median, median <= largest
	// at this point, I do NOT know that smallest <= median
	// 2.1.3 so, check it AGAIN!
	if (smallestCard > medianCard)
	{
		// fix it: swap/exchange
		int exchangeValue = smallestCard;
		smallestCard = medianCard;
		medianCard = exchangeValue;
	}

	// 2.2 Establish card name
	string firstCardName;
	string lastCardName;

	// 2.2.1 Ace
	if (smallestCard == 1)
		firstCardName = "Ace";
	if (largestCard == 1)
		lastCardName = "Ace";

	// 2.2.2 Two
	if (smallestCard == 2)
		firstCardName = "Two";
	if (largestCard == 2)
		lastCardName = "Two";

	// 2.2.3 Three
	if (smallestCard == 3)
		firstCardName = "Three";
	if (largestCard == 3)
		lastCardName = "Three";

	// 2.2.4 Four
	if (smallestCard == 4)
		firstCardName = "Four";
	if (largestCard == 4)
		lastCardName = "Four";

	// 2.2.5 Five
	if (smallestCard == 5)
		firstCardName = "Five";
	if (largestCard == 5)
		lastCardName = "Five";

	// 2.2.6 Six
	if (smallestCard == 6)
		firstCardName = "Six";
	if (largestCard == 6)
		lastCardName = "Six";

	// 2.2.7 Seven
	if (smallestCard == 7)
		firstCardName = "Seven";
	if (largestCard == 7)
		lastCardName = "Seven";

	// 2.2.8 Eight
	if (smallestCard == 8)
		firstCardName = "Eight";
	if (largestCard == 8)
		lastCardName = "Eight";

	// 2.2.9 Nine
	if (smallestCard == 9)
		firstCardName = "Nine";
	if (largestCard == 9)
		lastCardName = "Nine";

	// 2.2.10 Ten
	if (smallestCard == 10)
		firstCardName = "Ten";
	if (largestCard == 10)
		lastCardName = "Ten";

	// 2.2.11 Jack
	if (smallestCard == 11)
		firstCardName = "Jack";
	if (largestCard == 11)
		lastCardName = "Jack";

	// 2.2.12 Queen
	if (smallestCard == 12)
		firstCardName = "Queen";
	if (largestCard == 12)
		lastCardName = "Queen";

	// 2.2.12 King
	if (smallestCard == 13)
		firstCardName = "King";
	if (largestCard == 13)
		lastCardName = "King";


	// 2.3 Establish a hand
	string userHand = "";

	// 2.3.1 Check for high card
	if (userHand == "")
	{
		if (largestCard % 2 == 0)
			userHand = "You have an " + lastCardName + ".";
		else if (smallestCard == 1)
			userHand = "You have an " + firstCardName + ".";
		else
			userHand = "You have a " + lastCardName + ".";
	}

	// 2.3.2 Check for pair
	if (smallestCard == medianCard)
		userHand = "You have a pair of " + firstCardName + "s.";
	if (medianCard == largestCard)
		userHand = "You have a pair of " + lastCardName + "s.";
	if (smallestCard == largestCard)
		userHand = "You have a pair of " + firstCardName + "s.";

	// 2.3.3 Check for three of a kind
	if (smallestCard == medianCard && medianCard == largestCard)
		userHand = "You have three " + firstCardName + "s.";

	// 2.3.4 Check for straight
	if (smallestCard == 1 && medianCard == 12 && largestCard == 13)
		userHand = "You have an " + firstCardName + "-high straight.";

	if (++smallestCard == medianCard && medianCard == --largestCard)
	{
		if (largestCard % 2 == 0)
			userHand = "You have an " + lastCardName + "-high straight.";
		else
			userHand = "You have a " + lastCardName + "-high straight.";
	}

	// 3. Output
	////////////////////////////////////////////////////
	cout << userHand << endl;
	////////////////////////////////////////////////////

	// 4. End Process
	cout << endl;
	cout << "Please press enter to exit the program.";
	cin.ignore(999, '\n');
}
