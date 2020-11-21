#include <assert.h>

#include "Player.h"

Player::Player() {}

void Player::SetName(const std::string& name)
{
	playerName = name;
}

std::string Player::GetName()
{
	return playerName;
}


std::vector<PlayingCard>& Player::GetHand()
{
	return hand;
}

void Player::AddCards(PlayingCard card)
{
	hand.push_back(card);
}

void Player::AddCardsInFront(PlayingCard card)
{
	hand.insert(hand.begin(),card);
}

int Player::GetNumberOfCards()
{
	return hand.size();
}

PlayingCard Player::PopLastCard()
{
	PlayingCard lastCard = hand.back();
	hand.pop_back();
	return lastCard;
}

PlayingCard Player::GetLastCard()
{
	return hand.back();
}

Deck& Player::GetDeck()
{
	return deck;
}


