#pragma once

enum class Suit
{
	Nothing = 0,
	Hearts = 1,
	Clubs,
	Diamonds,
	Spades = 4
};

enum class FaceValue
{
	NoPlayingCard = 0,
	Two = 2,
	Three,
	Four,
	Five,
	Six,
	Seven = 7,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace = 14

};

class PlayingCard
{
public:

	PlayingCard(Suit newSuit, FaceValue newFaceValue);//constructor
	PlayingCard() {}

	void Display();

	FaceValue GetValue();

private:

	Suit suit;
	FaceValue faceValue;
};

