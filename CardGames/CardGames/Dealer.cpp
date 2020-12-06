#pragma once
#include "Dealer.h"
#include "iostream"
#include "InputEnum.h"
#include <synchapi.h>

Dealer::Dealer()
{
	player = new Player();
}

Dealer::~Dealer()
{
}

Player* Dealer::GetPlayer()
{
	return player;
}

void Dealer::SetDeck(Deck newDeck)
{
	deck = newDeck;
}

int Dealer::DealerTurn(int PlayerCardValue)
{
	std::cout << player;
	system("CLS");
	bool dealerBusted = false;
	for (int i = 0; i < 2; i++)
	{
		deck.DrawCard(player, 1);
	}

	std::cout << "Dealer hand: " << dealerCardvalue << std::endl;

	Sleep(2000);

	while (true)
	{
		system("CLS");

		if (dealerCardvalue == 17)
		{
			std::cout << "Dealer hand: " << dealerCardvalue << std::endl;
			std::cout << "Dealer stands!" << std::endl;
			Sleep(2000);
			return dealerCardvalue;
		}
		else if (dealerCardvalue > 21)
		{
			std::cout << "Dealer hand: " << dealerCardvalue << std::endl;
			std::cout << "Dealer busted!" << std::endl;
			Sleep(2000);
			return dealerCardvalue;
		}
		else if (dealerCardvalue > 17)
		{
			std::cout << "Dealer hand: " << dealerCardvalue << std::endl;
			std::cout << "Dealer Stands!" << std::endl;
			Sleep(2000);
			return dealerCardvalue;
		}
		else if (dealerCardvalue < PlayerCardValue)
		{
			if (dealerCardvalue < 17 && PlayerCardValue > dealerCardvalue)
			{
				deck.DrawCard(player, 1);
				std::cout << "dealer hits" << std::endl;
				Sleep(2000);
				std::cout << "Dealer hand: " << dealerCardvalue << std::endl;
				Sleep(2000);
			}
			else
			{
				std::cout << "Dealer Stands!" << std::endl;
				Sleep(2000);
				std::cout << "Dealer hand: " << dealerCardvalue << std::endl;
				Sleep(2000);
				return dealerCardvalue;
			}
		}
		else
		{
			std::cout << "Dealer Stands!" << std::endl;
			Sleep(2000);
			std::cout << "Dealer hand: " << dealerCardvalue << std::endl;
			Sleep(2000);
			return dealerCardvalue;
		}

		system("CLS");
		std::cout << "Dealer hand: " << dealerCardvalue << std::endl;
		Sleep(2000);
	}
}
