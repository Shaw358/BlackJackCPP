#include "Hand.h"

Hand::Hand()
{
}

Hand::~Hand()
{
}

std::vector<Card*>* Hand::getCards()
{
	return &cards;
}

void Hand::setCard(Card* aCard)
{

}

int Hand::getBalance()
{
	int totalBalance = 0;
	for (int i = 0; i < cards.size(); i++)
	{
		totalBalance += cards.at(i)->GetValue();
	}
	return totalBalance;
}

void Hand::setBalance(int aValue)
{
	int totalBalance = 0;
	for (int i = 0; i < cards.size(); i++)
	{
		totalBalance += cards.at(i)->GetValue();
	}
	totalBalance = balance;
}

void Hand::ClearHand()
{
	cards.clear();
	balance = 0;
}
