// 11/4/2015
// Manuel Perez
// Homework 08 - Poker 2.0
//
// This program is designed to compare two
// poker hands and see who is the winner
//

#include "Tools.h"
#include <iostream>

using namespace std;

// method prototypes
void run(void);
void playGame(void);
void sort(int &lowestCard, int &medianCard, int &largestCard,
			int card1, int card2, int card3);
void input(int &handOneCard1, int &handOneCard2, int &handOneCard3,
			int &handTwoCard1, int &handTwoCard2, int &handTwoCard3,
			int hand);
string playerHand(int card1, int card2, int card3, int &handValue);
string cardName(int card);
void whoWon(int playerOneValue, int playerTwoValue,
			int handOneCard3, int handTwoCard3,
			string playerOneHand, string playerTwoHand);


int main(void)
{
	run();
	return 0;
}

// Take the hand and sort from lowest to largest
void sort(int &lowestCard, int &medianCard, int &largestCard,
			int card1, int card2, int card3)
{
		// method: start with a guess for the answer:
		lowestCard = card1;
		medianCard = card2;
		largestCard = card3;

		// improve this guess
		if (lowestCard > medianCard)
		{
			// fix it: swap/exchange
			int exchangeValue = lowestCard;
			lowestCard = medianCard;
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
		// check it AGAIN!
		if (lowestCard > medianCard)
		{
			// fix it: swap/exchange
			int exchangeValue = lowestCard;
			lowestCard = medianCard;
			medianCard = exchangeValue;
		}

}

// Run and replay
void run(void)
{
	do
	{
		playGame();
	}while (getBool("Do you want to play again? "));
}

void playGame(void)
{
	// Player hand variables
	int hand;
	int handOneCard1;
	int handOneCard2;
	int handOneCard3;
	int handTwoCard1;
	int handTwoCard2;
	int handTwoCard3;

	// Sorting variables
	int lowestCard = 0;
	int medianCard = 0;
	int largestCard = 0;

	// Determine player hand variables
	string playerOneHand;
	string playerTwoHand;

	// Determine the winner variables
	int handValue;
	int playerOneValue;
	int playerTwoValue;

	// Determine hand one and sort
	hand = 1;
	input (handOneCard1, handOneCard2, handOneCard3,
			handTwoCard1, handTwoCard2, handTwoCard3,
			hand);
	sort(lowestCard, medianCard, largestCard,
				handOneCard1, handOneCard2, handOneCard3);
	handOneCard1 = lowestCard;
	handOneCard2 = medianCard;
	handOneCard3 = largestCard;
	playerOneHand = playerHand(handOneCard1, handOneCard2,
								handOneCard3, handValue);
	playerOneValue = handValue;

	cout << endl;

	// Determine hand two and sort
	hand = 2;
	input (handOneCard1, handOneCard2, handOneCard3,
			handTwoCard1, handTwoCard2, handTwoCard3,
			hand);
	sort(lowestCard, medianCard, largestCard,
			handTwoCard1, handTwoCard2, handTwoCard3);
	handTwoCard1 = lowestCard;
	handTwoCard2 = medianCard;
	handTwoCard3 = largestCard;
	playerTwoHand = playerHand(handTwoCard1, handTwoCard2,
								handTwoCard3, handValue);
	playerTwoValue = handValue;


	// Find out who won
	whoWon(playerOneValue, playerTwoValue,
				handOneCard3, handTwoCard3,
				playerOneHand, playerTwoHand);


}

// Takes the input from the user to establish the two hands
void input(int &handOneCard1, int &handOneCard2, int &handOneCard3,
			int &handTwoCard1, int &handTwoCard2, int &handTwoCard3,
			int hand)
{
	if (hand == 1)
	{
		cout << "Player One" << endl;
		handOneCard1 = getBoundedInt("Enter first card: ",
											1, 13);
		handOneCard2 = getBoundedInt("Enter second card: ",
													1, 13);
		handOneCard3 = getBoundedInt("Enter third card: ",
													1, 13);
	}else
	{

		cout << "Player Two" << endl;
		handTwoCard1 = getBoundedInt("Enter first card: ",
													1, 13);
		handTwoCard2 = getBoundedInt("Enter second card: ",
													1, 13);
		handTwoCard3 = getBoundedInt("Enter third card: ",
													1, 13);
	}

}

string cardName(int card)
{
	string name;
	switch(card)
	{
	case 1: name = "Ace";
		break;
	case 2: name = "Two";
		break;
	case 3: name = "Three";
		break;
	case 4: name = "Four";
		break;
	case 5: name = "Five";
		break;
	case 6: name = "Six";
		break;
	case 7: name = "Seven";
		break;
	case 8: name = "Eight";
		break;
	case 9: name = "Nine";
		break;
	case 10: name = "Ten";
		break;
	case 11: name = "Jack";
		break;
	case 12: name = "Queen";
		break;
	case 13: name = "King";
		break;
	}
	return name;
}

// Determines the hand
string playerHand(int card1, int card2, int card3, int &handValue)
{
	string yourHand;
	if (card1 == card2 && card2 == card3)
	{
		if (card1 == 1)
		{
			handValue = 7;
		}else
			handValue = 6;

		yourHand = "Trip " + cardName(card1) + "'s";
	}else if (card1 == card2 || card2 == card3)
	{
		if (card1 == card2)
		yourHand = "A pair of " + cardName(card1) + "'s";
		else
			yourHand = "A pair of " + cardName(card3) + "'s";

		if (card1 == 1)
			handValue = 5;
		else
			handValue = 4;

	}else if (card1 == 1 && card2 == 12 && card3 == 13)
	{
		yourHand = "An " + cardName(card1) + "-high straight";
		handValue = 3;
	}else if (card1 + 1 == card2 && card2 == card3 - 1)
	{
		if (card3 == 8)
			yourHand = "An " + cardName(card3) + "-high straight";
		else
			yourHand = "A " + cardName(card3) + "-high straight";

		handValue = 2;
	}else if (card1 == 1)
	{
		yourHand = cardName(card1) + "-high";
		handValue = 1;
	}else
	{
		yourHand = cardName(card3) + "-high";
		handValue = 0;
	}

	return yourHand;
}

// Find out who wins
void whoWon(int playerOneValue, int playerTwoValue,
			int handOneCard3, int handTwoCard3,
			string playerOneHand, string playerTwoHand)
{
	cout << endl;

	if (playerOneValue == playerTwoValue)
	{
		if (handOneCard3 == handTwoCard3)
		{
			cout << playerOneHand << " ties "
					<< playerTwoHand << endl;
			cout << "No one wins..." << endl;

		}else if (handOneCard3 > handTwoCard3)
		{
			cout << playerOneHand << " beats "
					<< playerTwoHand << endl;
			cout << "Player one wins!!" << endl;
		}else
		{
			cout << playerTwoHand << " beats "
					<< playerOneHand << endl;
			cout << "Player Two wins!!" << endl;
		}
	}else if (playerOneValue > playerTwoValue)
	{
		cout << playerOneHand << " beats "
				<< playerTwoHand << endl;
		cout << "Player one wins!!" << endl;
	}
	else
	{
		cout << playerTwoHand << " beats "
				<< playerOneHand << endl;
		cout << "Player Two wins!!" << endl;
	}
	cout << endl;
}


