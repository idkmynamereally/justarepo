#pragma once
#include <array>
namespace deckValues
{
	constexpr int g_DeckSize = 52;
	constexpr int g_DeckRanks = 13;
	constexpr int g_DeckSuits = 4;
}

using Deck = std::array<Card, deckValues::g_DeckSize>;

void printDeck(const Deck& deck);

Deck createDeck();

void shuffleDeck(Deck& deck);
