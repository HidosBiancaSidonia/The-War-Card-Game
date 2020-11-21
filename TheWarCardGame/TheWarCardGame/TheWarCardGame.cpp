#include <iostream>
#include <algorithm>
#include <assert.h> 

#include "TheWarCardGame.h"
#include "Deck.h"
#include "Player.h"

TheWarCardGame::TheWarCardGame()
{
	numberOfPlayers = 0;
	nameOfPlayers.clear();
	name.clear();
	win = 0;
}

/* 
This method starts the game and gives you the opportunity to add the number of players and their 
names. 
*/
void TheWarCardGame::Play()
{
	Message();
	Deck deck(Suit::Spades,FaceValue::Ace);
	deck.Shuffle();

	numberOfPlayers = NumberOfPlayers();
	std::vector<Player> players;
	Player player[11];

	int i = 0;

	for (std::string name : NameOfPlayers(numberOfPlayers))
	{
		player[i].SetName(name);	
		i++;
	}

	/*
	Distribution of playing cards to all players!
	*/

	while (deck.GetCardCount() != 0)
	{
		for (int index1 = 0; index1 < numberOfPlayers; index1++)
			if (deck.GetCardCount() != 0)
			{
				player[index1].AddCards(deck.PopLastCard());
			}
			else
			{
				break;
			}
	}

	system("cls");
	Message();
	std::cout << "THE PLAYERS' NAME ARE: \n" << std::endl;
	for (int index2 = 0; index2 < numberOfPlayers; index2++)
	{
		std::cout << "PLAYER " << index2 + 1 << ": ";
		std::cout << player[index2].GetName() << std::endl;
		players.push_back(player[i]);

		std::cout <<"PLAYER "<< player[index2].GetName() <<" HAS "<< player[index2].GetHand().size() << " PLAYING CARDS\n\n";
	}
	
	/*
	START THE GAME
	*/

	int decision;
	std::cout << "Are you starting the game?\n1-YES else-NO : ";
	std::cin >> decision;
	std::cout << std::endl;
	if (decision == 1)
	{
		system("cls");
		std::vector<FaceValue> cards;
		
		/*Logical implementation of the game.*/
		int nr = 0;
		while (win == false)
		{
			nr++;
			std::cout << "\nROUND " << nr << " !\n\n";
			cards.clear();
			PlayingCard noPlayingCard(Suit::Nothing, FaceValue::NoPlayingCard);
			
			std::cout <<"________________________________________________"<<std::endl;
			for (int index3 = 0; index3 < numberOfPlayers; index3++)
			{			
				if (player[index3].GetHand().size() == 0)
				{
					player[index3].AddCards(noPlayingCard);
				}
				/*
				Displaying players and the first playing card in each player's card.
				*/
				std::cout << player[index3].GetName() << " : ";
				PlayingCard card = player[index3].GetLastCard();
				card.Display();
								
				/*
				I add the first playing card from the deck to a vector ~ cards ~ to make it easier to 
				find the biggest card.
				*/
				cards.push_back(card.GetValue());
			}
			std::cout << "________________________________________________\n" << std::endl;
			/*
			Playing card with highest value.
			*/
			FaceValue cardWithHighestValue = *max_element(cards.begin(), cards.end());
			std::cout << "Playing card with highest value is : ";
			DisplayFaceValue(cardWithHighestValue);

			/*
			I check how many times this playing card appears. If it appears to more players then war 
			is declared, and if not the player with this playing card takes all the other cards in
			her/his deck.
			*/
			int  appearances = count(cards.begin(), cards.end(), cardWithHighestValue);
			std::cout <<"\nThis playing card appears: "<< appearances <<" times.\n";
			
			if (appearances > 1)
			{
				bool validator = false;
				int index;

				while (validator == false)
				{
					std::vector<FaceValue> cardsWAR,war,WAR;
					
					/*
					I saved the index of the players with the highest value playing card.
					*/
					std::vector<FaceValue>::iterator it;
					std::vector<int> vectorOfIndex;

					for (it = cards.begin(); it != cards.end(); ++it)
					{
						if (*it == cardWithHighestValue)
						{
							index = it - cards.begin();
							vectorOfIndex.push_back(index);
							std::cout << player[index].GetName() << " has the highest value of playing card!\n";
						}
					}

					std::cout << "\nWAR!!!\n";

					std::cout << "________________________________________________" << std::endl;

					for (int index4 = 0; index4 < numberOfPlayers; index4++)
					{
						for (int index5 = 0; index5 < static_cast<int>(cardWithHighestValue); index5++)
						{
							if (player[index4].GetNumberOfCards() != 0 && player[index4].GetLastCard().GetValue() != noPlayingCard.GetValue())
							{
								PlayingCard last = player[index4].PopLastCard();
								player[index4].GetDeck().AddCard(last);
								cardsWAR.push_back(player[index4].GetDeck().GetLastCard().GetValue());
							}
							if (player[index4].GetNumberOfCards() != 0  && player[index4].GetLastCard().GetValue() == noPlayingCard.GetValue())
							{
								break;
							}
							if (player[index4].GetNumberOfCards() == 0)
							{
								player[index4].AddCards(noPlayingCard);
							}
						}

						if (cardsWAR.size() != 0)
						{
							WAR.push_back(cardsWAR.back());
						}
						else
						{
							WAR.push_back(noPlayingCard.GetValue());
						}

						if (std::find(vectorOfIndex.begin(), vectorOfIndex.end(), index4) != vectorOfIndex.end())
						{
							war.push_back(WAR.back());
						}

						std::cout << player[index4].GetName() << " : ";
						if (player[index4].GetDeck().GetDeck().size() != 0)
						{
							player[index4].GetDeck().GetLastCard().Display();
						}
						else
						{
							noPlayingCard.Display();
						}

						cardsWAR.clear();
					}

					std::cout << "________________________________________________" << std::endl;

					FaceValue cardWithHighestValueWAR = *max_element(war.begin(), war.end());
					std::cout << "Playing card with highest value is : ";
					DisplayFaceValue(cardWithHighestValueWAR);

					int  appearances = count(war.begin(), war.end(), cardWithHighestValueWAR);
					std::cout << "\nThis playing card appears: " << appearances << " times.\n";

					if (appearances > 1)
					{
						validator = false;
					}
					else if (appearances == 1)
					{
						int value = 0;
						for (int index6 = 0; (unsigned)index6 < WAR.size(); index6++)
						{
							if (WAR[index6] == cardWithHighestValueWAR )
							{
								value = index6;
							}
						}

						std::cout << player[value].GetName() << " takes the playing cards because she/he has the highest value of playing card!\n";

						for (int index7 = 0; index7 < numberOfPlayers; index7++)
						{
							while (player[index7].GetDeck().GetDeck().size() != 0)
							{
								player[value].AddCardsInFront(player[index7].GetDeck().PopLastCard());
							}
						}

						if (player[value].GetLastCard().GetValue() == noPlayingCard.GetValue())
						{
							player[value].PopLastCard();
						}
						
						std::cout << "\nPlayer " << player[value].GetName() << " now has " << player[value].GetHand().size() << " cards.\n";
						std::cout << std::endl;

						validator = true;
					}

					war.clear(), WAR.clear();
				}
			}
			else if (appearances == 1)
			{
				std::cout << "\nNO WAR!\n";

				/*
				I display the name of the player who will take all the playing cards face up from the deck.
				*/
				std::vector<FaceValue>::iterator result;
				result = std::max_element(cards.begin(), cards.end());
				int index = std::distance(cards.begin(), result);
				std::cout << player[index].GetName() <<" takes the playing cards because she/he has the highest value of playing card!";
				
				/*
				The players with the highest card takes the cards played and puts them at the bottom 
				of his/her deck.
				*/
				for (int index2 = 0; index2 < numberOfPlayers; index2++)
				{
						if(player[index2].GetLastCard().GetValue() != noPlayingCard.GetValue())
							player[std::distance(cards.begin(), result)].AddCardsInFront(player[index2].PopLastCard());
				}

				std::cout <<"\nPlayer "<< player[index].GetName() <<" now has "<< player[index].GetHand().size() <<" cards.\n";
				std::cout << std::endl;
			}

			for (int index3 = 0; index3 < numberOfPlayers; index3++)
			{
				if (player[index3].GetHand().size() == 52)
				{
					winner = player[index3].GetName();
					win = true;
				}
			}
			
			if (win != true)
			{
				std::cout << "At the moment no one has won. Do you want to continue the game?\n";
				std::cout << "1-YES else-NO : ";
				std::cin >> decision;
				if (decision != 1)
				{
					std::cout << "\nTHE GAME IS OVER\n";
					return;
				}
			}
			else
			{
				std::cout << "!!!!!!!!!!!!!!!!!!!!!\n";
				std::cout << "THE WINNER IS : " << winner<<std::endl;
				std::cout << "!!!!!!!!!!!!!!!!!!!!!\n";
			}
		}
	}
	else
	{
		std::cout << "\nTHE GAME IS OVER\n";
	}
}

void TheWarCardGame::Message()
{
	std::cout << "WELCOME TO THE WAR CARD GAME!" << "\n \n";
}

int TheWarCardGame::NumberOfPlayers()
{
	std::cout << "How many players participate in this game? " << '\n';

	/*
	The maximum number of players can be 10, and the minimum number of players can be 2.
	*/
	while (2 > numberOfPlayers || numberOfPlayers > 10)
	{
		int nr;
		std::cout << "The number of players must be between 2 and 10.\nEnter the number of players : ";
		std::cin >> nr;

		numberOfPlayers = nr;
	}

	std::cout << std::endl;
	return numberOfPlayers;
}

std::vector<std::string> TheWarCardGame::NameOfPlayers(int number)
{
	std::cout << "Enter the names of the " << numberOfPlayers << " players." << '\n';
	for (int index = 0; index < numberOfPlayers; index++)
	{
		std::cout << "Player " << index + 1 << ": ";
		std::cin >> name;

		/*
		The names of the players are not allowed to be repeated because at the end of the game
		when the winner is announced there is the possibility to confuse the players if their names
		are the same.
		*/
		while (std::find(nameOfPlayers.begin(), nameOfPlayers.end(), name) != nameOfPlayers.end())
		{
			std::cout << "This name already exist!\nEnter another name: ";
			std::cin >> name;
		}

		nameOfPlayers.push_back(name);
	}
	return nameOfPlayers;
}

void TheWarCardGame::DisplayFaceValue(FaceValue value)
{
		switch (value)
		{
		case FaceValue::NoPlayingCard:
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
}



