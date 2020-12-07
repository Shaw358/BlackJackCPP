#include "Game.h"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::BlackJack()
{
	/*
	List of Functions:

	Fill > fills the entire deck with Card classes and assigns values to them.

	Shuffle > Randomizes the remainingCards vector from the Deck.

	ShowRemainingCards > Prints all the cards left in the remainingCards vector from the Deck.

	DrawCard > Gets the first Card class in the vector remainingCards in the Deck and puts in the [X player] hand.

	getHand > Gets the hand class from [X player].

	getbalance > Gets the balance from [X player].

	setBalance > Sets the [X player credits].

	askInt > Insert a question in the parameter and ask [X player] for a number.

	askBool > Insert a question in the parameter and ask [X player] for a bool.

	askString > Insert a question in the parameter and ask [X player] for a string. [Allows for commands!]
	*/

#pragma region

	deck.Fill();
	deck.Shuffle();
	//deck.ShowRemainingCards();

	choiceInt = io.AskInt("How many players will be participating?", 2);

	for (int i = 0; i < choiceInt; i++)
	{
		players.push_back(new Player());
	}
	
	dealer.SetDeck(deck);

	currentPlayer = 0;
	choiceInt = 0;

#pragma endregion setup phase

	while (true)
	{
		int highestAmount = 0;

		choiceInt = 0; 
		for (int i = 0; i < players.size(); i++, currentPlayer++)
		{
			deck.DrawCard(players.at(currentPlayer), 2);
		}
		currentPlayer = 0;

		for (int i = 0; i < players.size(); i++, currentPlayer++)
		{
			std::cout << "Player " << currentPlayer + 1 << " card value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;

			while (choiceInt != 1)
			{
				choiceInt = io.AskInt("Dealer: hit or stand?", 0);
				switch (choiceInt)
				{
				case 0:
					deck.DrawCard(players.at(currentPlayer), 1);
					if (players.at(currentPlayer)->getHand()->getBalance() > 21)
					{
						std::cout << "Dealer: player " << currentPlayer + 1 << " busted!" << std::endl;
						players.at(currentPlayer)->setBusted(true);
						choiceInt = 1;
					}
					std::cout << "Dealer: Player " << currentPlayer + 1 << " card value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;
					break;
				case 1:
					if (players.at(currentPlayer)->getHand()->getBalance() > highestAmount)
					{
						highestAmount = players.at(currentPlayer)->getHand()->getBalance();
					}
					break;
				}
			}
			Sleep(2000);
		}

		bool dealerCanPlay = false;
		for (int i = 0; i < players.size(); i++)
		{
			if (players.at(i)->getBusted() == false)
			{
				dealerCanPlay = true;
				break;
			}
		}
		if (dealerCanPlay)
		{
			dealer.DealerTurn(highestAmount);
			endGameScreen.ShowResults(dealer, players);
		}

		Sleep(1200);
		system("CLS");
		std::cout << "New Round" << std::endl;
		Sleep(2000);
		system("CLS");

		for (int i = 0; i < players.size(); i++)
		{
			players.at(i)->setBusted(false);
			players.at(i)->getHand()->ClearHand();
		}
		dealer.GetPlayer()->getHand()->ClearHand();
		currentPlayer = 0;
	}
}

void Game::PlayMusic()
{

}
