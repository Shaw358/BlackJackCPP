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
	deck.ShowRemainingCards();

	choiceInt = io.AskInt("How many players will be participating?", 2);

	for (int i = 0; i < choiceInt + 1; i++)
	{
		players.push_back(new Player());
	}

	//start cards
	for (int i = 0; i < players.size(); i++, currentPlayer++)
	{
		deck.DrawCard(players.at(currentPlayer), 2);
	}

	currentPlayer = 0;
	choiceInt = 0;

#pragma endregion setup phase end

	while (true)
	{
		int highestAmount = 0;
		for (int i = 0; i < players.size(); i++, currentPlayer++)
		{
			std::cout << "Dealer: Player " << currentPlayer + 1 << " card value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;

			while (choiceInt != 1)
			{
				choiceInt = io.AskInt("Dealer: hit or stand?", 0);
				switch (choiceInt)
				{
				case 0:
					deck.DrawCard(players.at(currentPlayer), 1);
					if (players.at(currentPlayer)->getHand()->getBalance() > 21)
					{
						std::cout << "Dealer: player " << currentPlayer << " busted!" << std::endl;
						choiceInt = 1;
					}
					std::cout << "Dealer: Player " << currentPlayer + 1 << " card value: " << players.at(currentPlayer)->getHand()->getBalance() << std::endl;
					break;
				case 1:
					if (players.at(currentPlayer)->getHand()->getBalance() > highestAmount)
					{
						highestAmount = players.at(currentPlayer)->getHand()->getBalance();
					}
					std::cout << "stand" << std::endl;
					break;
				}
			}
		}
		dealer.DealerTurn(highestAmount);
		for (int i = 0; i < players.size(); i++)
		{
			players.at(i)->getHand()->ClearHand();
		}
		dealer.GetPlayer()->getHand()->ClearHand();
		std::cout << "Cock";
		currentPlayer = 0;
		system("CLS");
	}
}
