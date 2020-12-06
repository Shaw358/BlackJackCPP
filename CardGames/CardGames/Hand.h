#pragma once
#include <windows.h>
#include "Card.h"
#include <vector>
class Hand
{
public:
	Hand();
	~Hand();

	std::vector<Card*>* getCards();
	void setCard(Card* aCard);
	int getBalance();
	void setBalance(int aValue);
	void ClearHand();

private:
	std::vector<Card*> cards;
	int balance;
};

