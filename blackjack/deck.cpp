#include <array>
#include <random>
#include <iostream>
#include "card.h"
#include "deck.h"

Deck createDeck()
{
	Deck deck{};
	int cardNumber{ 0 };
	for (auto cardSuit{ 0 }; cardSuit < deckValues::g_DeckSuits; cardSuit++)
	{
		for (auto cardRank{ 0 }; cardRank < deckValues::g_DeckRanks; cardRank++, cardNumber++)
		{
			deck.at(cardNumber) = Card{static_cast<CardRanks>(cardRank), static_cast<CardSuits>(cardSuit)};
		}
	}
	return deck;
}

void printDeck(const Deck& deck)
{
	for (const auto& c : deck)
	{
		printCard(c);
		std::cout << " ";
	}
}

void shuffleDeck(Deck& deck)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::shuffle(deck.begin(), deck.end(), mt);
}
