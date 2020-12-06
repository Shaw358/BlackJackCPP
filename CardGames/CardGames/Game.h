#pragma once
#include <windows.h>
#include "Deck.h"
#include "IO.h"
#include "Dealer.h"

class Game
{
public:
	Game();
	~Game();

	void BlackJack();
private:
	int currentPlayer = 0;
	Deck deck;
	IO io;
	Player* player;
	std::string choiceString;
	int choiceInt;
	bool choiceBool;
	Dealer dealer;

	std::vector<Player*> players;
};

