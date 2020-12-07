#include "EndGameScreen.h"

EndGameScreen::EndGameScreen()
{
}

EndGameScreen::~EndGameScreen()
{
}

void EndGameScreen::ShowResults(Dealer dealer, std::vector<Player*> players)
{
	system("CLS");
	std::cout << "Dealer: " << dealer.GetPlayer()->getHand()->getBalance() << std::endl;
	if (dealer.GetPlayer()->getHand()->getBalance() > 21)
	{
		std::cout << "Busted" << std::endl;
	}

	for (int i = 0; i < players.size() - 1; i++)
	{
		std::cout << "Player " << i + 1 << ": " << players.at(i)->getHand()->getBalance() << std::endl;
		if (players.at(i)->getHand()->getBalance() > 21)
		{
			std::cout << "Busted" << std::endl;
		}
		else if (players.at(i)->getHand()->getBalance() > dealer.GetPlayer()->getHand()->getBalance() && players.at(i)->getHand()->getBalance() <= 21 || players.at(i)->getHand()->getBalance() <= 21 && dealer.GetPlayer()->getHand()->getBalance() > 21)
		{
			std::cout << "You won" << std::endl;
		}
		else if (players.at(i)->getHand()->getBalance() == dealer.GetPlayer()->getHand()->getBalance())
		{
			std::cout << "Push" << std::endl;
		}
		else
		{
			std::cout << "You lost" << std::endl;
		}
		std::cout << std::endl;
		Sleep(800);
	}
}
