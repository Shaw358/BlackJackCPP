#include "Deck.h"
#include "string"
#include <iostream>
#include <vector>
#include <ctime>       
#include <cstdlib>    
#include <algorithm> 

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::DrawCard(Player* aPlayer, int anAmount = 1)
{
	if (remainingCards.size() > 0)
	{
		std::move(remainingCards.begin(), remainingCards.begin() + anAmount, std::back_inserter(*aPlayer->getHand()->getCards()));
		for (int i = 0; i< anAmount; i++)
		{
			remainingCards.erase(remainingCards.begin());
		}
	}
}

void Deck::Fill()
{
	for (short unsigned int j = 0; j < 4; j++)
	{
		for (int i = 1; i < 11; i++)
		{
			Card* card = new Card(i);
			card->setCardType(j);
			remainingCards.push_back(card);
			remainingCards.back()->setCardType(1);
		}
	}
}

void Deck::Shuffle()
{
	srand(time(0));
	//randomInt = rand() % remainingCards.size();
	std::random_shuffle(remainingCards.begin(), remainingCards.end());
}

void Deck::ShowRemainingCards()
{
	for (auto v : remainingCards)
	{
		std::cout << v->GetValue() << "\n";
	}
}