#pragma once
#include "Dealer.h"
#include "iostream"
#include "InputEnum.h"
#include <synchapi.h>

Dealer::Dealer() :player(new Player())
{
}

Dealer::~Dealer()
{
}

Player* Dealer::GetPlayer()
{
	return player;
}

void Dealer::SetDeck(Deck* newDeck)
{
	deck = newDeck;
}

int Dealer::DealerTurn(int PlayerCardValue)
{
	std::cout << "Dealer's turn...";
	Sleep(2000);
	system("CLS");

	deck->DrawCard(player, 2);

	std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
	Sleep(2000);

	while (true)
	{
		system("CLS");

		if (GetPlayer()->getHand()->getBalance() == 17)
		{
			std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
			std::cout << "Dealer stands!" << std::endl;
			Sleep(2000);
			return GetPlayer()->getHand()->getBalance();
		}
		else if (GetPlayer()->getHand()->getBalance() > 21)
		{
			std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
			std::cout << "Dealer busted!" << std::endl;
			Sleep(2000);
			return GetPlayer()->getHand()->getBalance();
		}
		else if (GetPlayer()->getHand()->getBalance() > 17)
		{
			std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
			std::cout << "Dealer Stands!" << std::endl;
			Sleep(2000);
			return GetPlayer()->getHand()->getBalance();
		}
		else if (GetPlayer()->getHand()->getBalance() < PlayerCardValue)
		{
			if (GetPlayer()->getHand()->getBalance() < 17 && PlayerCardValue > GetPlayer()->getHand()->getBalance())
			{
				deck->DrawCard(player, 1);
				std::cout << "dealer hits" << std::endl;
				std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
				Sleep(2000);
			}
			else
			{
				std::cout << "Dealer Stands!" << std::endl;
				std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
				Sleep(2000);
				return GetPlayer()->getHand()->getBalance();
			}
		}
		else
		{
			std::cout << "Dealer Stands!" << std::endl;
			std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
			Sleep(2000);
			return GetPlayer()->getHand()->getBalance();
		}
		system("CLS");
		std::cout << "Dealer hand: " << GetPlayer()->getHand()->getBalance() << std::endl;
		Sleep(2000);
	}
}
