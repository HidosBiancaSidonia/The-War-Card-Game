#include <iostream>

#include "PlayingCard.h"

PlayingCard::PlayingCard(Suit newSuit, FaceValue newFaceValue) : suit(newSuit), faceValue(newFaceValue){}

void PlayingCard::Display()
{
	/*
	Displays the playing card.
	*/
	switch (faceValue)
	{
	case FaceValue::NoPlayingCard :
		std::cout << "No Playing Card";
		break;
	case FaceValue::Two:
		std::cout << "Two";
		break;
	case FaceValue::Three:
		std::cout << "Three";
		break;
	case FaceValue::Four:
		std::cout << "Four";
		break;
	case FaceValue::Five:
		std::cout << "Five";
		break;
	case FaceValue::Six:
		std::cout << "Six";
		break;
	case FaceValue::Seven:
		std::cout << "Seven";
		break;
	case FaceValue::Eight:
		std::cout << "Eight";
		break;
	case FaceValue::Nine:
		std::cout << "Nine";
		break;
	case FaceValue::Ten:
		std::cout << "Ten";
		break;
	case FaceValue::Jack:
		std::cout << "Jack";
		break;
	case FaceValue::Queen:
		std::cout << "Queen";
		break;
	case FaceValue::King:
		std::cout << "King";
		break;
	case FaceValue::Ace:
		std::cout << "Ace";
		break;
	}


	switch (suit)
	{
	case Suit::Nothing:
		std::cout << " ";
		break;
	case Suit::Clubs:
		std::cout << " of Clubs";
		break;
	case Suit::Hearts:
		std::cout << " of Hearts";
		break;
	case Suit::Diamonds:
		std::cout << " of Diamonds";
		break;
	case Suit::Spades:
		std::cout << " of Spades";
		break;
	}
	std::cout << std::endl;
}

FaceValue PlayingCard::GetValue()
{
	return faceValue;
}

