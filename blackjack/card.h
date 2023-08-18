#pragma once
enum class CardRanks
{
	rank_2,
	rank_3,
	rank_4,
	rank_5,
	rank_6,
	rank_7,
	rank_8,
	rank_9,
	rank_10,
	jack,
	queen,
	king,
	ace,

	max_ranks,
};

enum class CardSuits
{
	clubs,
	diamonds,
	hearts,
	spades,
	max_suits,
};

struct Card
{
	CardRanks rank{};
	CardSuits suit{};
};

void printCard(const Card& card);

int getCardValue(const Card& card);
