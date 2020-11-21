#pragma once
#include <string>
#include <vector>

#include "PlayingCard.h"
#include"Deck.h"

class Player
{
public:

	Player(); //constructor

	void SetName(const std::string& name);
	std::string GetName();
	
	//Hand
	std::vector<PlayingCard>& GetHand();

	void AddCards(PlayingCard card);
	void AddCardsInFront(PlayingCard card);
	int GetNumberOfCards();
	PlayingCard PopLastCard();
	PlayingCard GetLastCard();

	//Deck
	Deck& GetDeck();

private:

	std::string playerName;
	std::vector<PlayingCard> hand;
	Deck deck;
	
};

