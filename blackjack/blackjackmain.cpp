#include <iostream>
#include "card.h"
#include "deck.h"
#include <random>

namespace blacjackValues
{
	constexpr int g_bustvalue = 21;
	constexpr int g_dealermin = 17;
}

bool playerTurn(const Deck& deck, int& player, int& index)
{
	std::cout << "\t\tPlayer Turn\n";
	int choice{ 0 };
	while (true)
	{
		std::cout << "Player Has " << player << '\n';
		std::cout << "Hit = 1\nStand = 2\n\nChoice : ";
		std::cin >> choice;
		int nextCard{};
		if (choice == 1)
		{
			nextCard = getCardValue(deck.at(++index));
			std::cout << "Player got " << nextCard << '\n';
			player += nextCard;
			std::cout << "Player -> " << player << "\n\n";
			if (player > blacjackValues::g_bustvalue)
			{
				std::cout << "Player Has Busted!\n";
				return true;
			}
		}
		if (choice == 2)
		{
			return false;
		}
	}
}

bool dealerTurn(const Deck& deck, int& dealer, int& index)
{
	std::cout << "\t\tDealer Turn\n";
	int nextCard{};
	std::cout << "Dealer Has " << dealer << '\n';
	while (true)
	{
		nextCard = getCardValue(deck.at(++index));
		std::cout << "\nDealer got " << nextCard << '\n';
		dealer += nextCard;
		std::cout << "Dealer -> " << dealer << '\n';
		if (dealer >= blacjackValues::g_dealermin)
		{
			if (dealer > blacjackValues::g_bustvalue) {
				std::cout << "Dealer Busted\n";
				return true;
			}
			else
				return false;
		}
	}
}

bool playBlackJack(Deck& deck)
{
	int index{ 0 };
	shuffleDeck(deck);
	int dealer{ 0 };
	int player{ 0 };
	dealer += getCardValue(deck.at(++index));
	player += getCardValue(deck.at(++index));
	player += getCardValue(deck.at(++index));
	if (playerTurn(deck, player, index))
	{
		std::cout << "Player Busted, You Lose!\n";
		return false;
	}
	if (dealerTurn(deck, dealer, index))
	{
		std::cout << "Dealer Busted, You Win!\n";
		return true;
	}
	std::cout << "\nPlayer -> " << player << "\n" << "Dealer -> " << dealer << '\n';
	if (player > dealer)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Deck deck = createDeck();
	if (playBlackJack(deck))
	{
		std::cout << "Player Wins!\n";
	}
	else
	{
		std::cout << "House Always Wins!\n";
	}
}
