#pragma once
#include <windows.h>
#include <vector>
#include "Card.h"
#include "Hand.h"
#include "Player.h"

class Deck
{
public:
	Deck();
	~Deck();

	void DrawCard(Player* aPlayer, int anAmount);

	void Fill();

	void Shuffle();

	void ShowRemainingCards();

private:
	std::vector<Card*> remainingCards;
	int randomInt;

};