#pragma once
#include <vector>
#include <string>

#include "PlayingCard.h"

class TheWarCardGame
{
public:

	TheWarCardGame(); 

	void Play();
	void Message();
	int NumberOfPlayers();
	std::vector<std::string> NameOfPlayers(int number);
	void DisplayFaceValue(FaceValue value);
	
private:

	int numberOfPlayers;
	std::vector<std::string> nameOfPlayers;
	std::string name;
	bool win;
	std::string winner;
};

