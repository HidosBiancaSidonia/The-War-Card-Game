#pragma once
#include "PlayingCard.h"
#include <vector>

class Deck
{
public:

	Deck(Suit suit,FaceValue faceValue); //constructor
	Deck();

	void Display();
	void Shuffle();

	PlayingCard PopLastCard();
	PlayingCard GetLastCard();
	int GetCardCount();
	void AddCard(PlayingCard card);
	std::vector<PlayingCard>& GetDeck();

private:

	std::vector<PlayingCard> cards;
};

