#pragma once
#include <windows.h>
#include "Player.h"
#include "Deck.h"

class Dealer
{
public:
	int DealerTurn(int PlayerHandValue);
	Dealer();
	~Dealer();
	Player* GetPlayer();
	void SetDeck(Deck newDeck);

private:
	bool dealerDone = false;
	int dealerCardvalue = 0;
	Player* player;
	Deck deck;
};

