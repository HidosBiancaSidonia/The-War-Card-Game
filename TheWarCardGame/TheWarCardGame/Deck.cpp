#include <time.h>  
#include <stdlib.h>  
#include <algorithm>
#include <assert.h> 

#include "Deck.h"

Deck::Deck(Suit suit, FaceValue faceValue) //constructor
{
	/*
	This sets the 52 cards.Each value has the 4 symbols.
	For example : playing card 3 has the following symbols : clubs, diamonds, heartsand spade.
	*/
		
	for (int s = 1; s <= static_cast<int>(suit); ++s )
	{
		for (int f = 2; f <= static_cast<int>(faceValue); ++f)
		{
			Suit su = (Suit)s;
			FaceValue face = (FaceValue)f;

			PlayingCard card(su, face);
			cards.push_back(card);
		}
	}
}

Deck::Deck()
{
	cards.clear();
}

void Deck::Display()
{
	/*
	The method displays the playing cards.
	*/
	
	std::vector<PlayingCard>::iterator it;
	for (it = cards.begin(); it!=cards.end(); ++it)
	{
		(*it).Display();
	}
}

void Deck::Shuffle()
{
	/*
	The method shuffles the playing cards randomly.
	*/
	srand(unsigned(time(NULL)));
	std::random_shuffle(cards.begin(), cards.end());
}

PlayingCard Deck::PopLastCard()
{
	auto card = cards.back();
	cards.pop_back();
	return card;
}

PlayingCard Deck::GetLastCard()
{
	assert(cards.size() != 0);
	return cards[cards.size()-1];
}

int Deck::GetCardCount()
{
	return cards.size();
}

void Deck::AddCard(PlayingCard card)
{
	cards.push_back(card);
}

std::vector<PlayingCard>& Deck::GetDeck()
{
	return cards;
}
