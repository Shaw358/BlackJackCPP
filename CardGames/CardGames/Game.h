#pragma once
#include<fstream> 

#include <windows.h>
#include "Deck.h"
#include "IO.h"
#include "Dealer.h"
#include "EndGameScreen.h"

class Game
{
public:
	Game();
	~Game();

	void BlackJack();
	void PlayMusic();
private:
	Deck deck;
	IO io;
	Player* player;
	std::string choiceString;
	int choiceInt;
	bool choiceBool;
	Dealer dealer;
	EndGameScreen endGameScreen;

	std::vector<Player*> players;
};

