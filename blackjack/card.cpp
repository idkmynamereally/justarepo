#include "card.h"
#include <iostream>

void printCard(const Card& card)
{
	switch (card.rank)
	{
	case CardRanks::rank_2: std::cout << "2";
		break;
	case CardRanks::rank_3: std::cout << "3";
		break;
	case CardRanks::rank_4: std::cout << "4";
		break;
	case CardRanks::rank_5: std::cout << "5";
		break;
	case CardRanks::rank_6: std::cout << "6";
		break;
	case CardRanks::rank_7: std::cout << "7";
		break;
	case CardRanks::rank_8: std::cout << "8";
		break;
	case CardRanks::rank_9: std::cout << "9";
		break;
	case CardRanks::rank_10: std::cout << "10";
		break;
	case CardRanks::jack: std::cout << "J";
		break;
	case CardRanks::queen: std::cout << "Q";
		break;
	case CardRanks::king: std::cout << "K";
		break;
	case CardRanks::ace: std::cout << "A";
		break;
	}

	switch (card.suit)
	{
	case CardSuits::clubs: std::cout << "C";
		break;
	case CardSuits::diamonds: std::cout << "D";
		break;
	case CardSuits::hearts: std::cout << "H";
		break;
	case CardSuits::spades: std::cout << "S";
		break;
	}
}

int getCardValue(const Card& card)
{
	int value{ 0 };
	switch (card.rank)
	{
	case CardRanks::ace: value += 11;
		break;
	case CardRanks::king: value += 10;
		break;
	case CardRanks::queen: value += 10;
		break;
	case CardRanks::jack: value += 10;
		break;
	case CardRanks::rank_10: value += 10;
		break;
	case CardRanks::rank_9: value += 9;
		break;
	case CardRanks::rank_8: value += 8;
		break;
	case CardRanks::rank_7: value += 7;
		break;
	case CardRanks::rank_6: value += 6;
		break;
	case CardRanks::rank_5: value += 5;
		break;
	case CardRanks::rank_4: value += 4;
		break;
	case CardRanks::rank_3: value += 3;
		break;
	case CardRanks::rank_2: value += 2;
		break;
	}
	return value;
}
