#include <iostream>
#include <string>
#include "vector"
#include <cctype>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#pragma region Variables

std::vector<int> cards;
std::vector<int> playerCards;
std::vector<int> dealerCards;
std::string playerName;
int randomized = 0;

int credits = 2000;
int bettedCredits;

std::string playerInput;
int choice;

int PlayerCardValue = 0;
int DealerCardvalue = 0;

bool dealerDone;
bool dealerBusted;

#pragma endregion

void FillCardVector()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 12; j++)
		{
			cards.push_back(j);
		}
	}
}

void Instructions()
{
	std::cout << "Hello " << playerName << endl;
	Sleep(1000);
	std::cout << "I am here to quickly explaint to you how blackjack works" << endl;
	Sleep(1000);
	std::cout << "You are playing to get a total card value of 21" << endl;
	Sleep(1000);
	std::cout << "If you exceed this number, you lose" << endl;
	Sleep(1000);
	std::cout << "Likewise the dealer also isn't allowed to go over 21" << endl;
	Sleep(1000);
	std::cout << "If someone hits a 21 on their first draw he automatically wins, if both parties have 21 on their first draw the dealer wins" << endl;
	Sleep(1000);
	std::cout << "If no parties reach 21 before standing the party with the highest total score wins" << endl;
	Sleep(1000);
	std::cout << "Good luck!" << endl;
	std::cout << "Type anything to proceed" << endl;
	std::cin >> playerInput;
	system("CLS");
}

void GetCard(unsigned short int player)
{
	srand(time(0));

	randomized = rand() % cards.size();

	switch (player)
	{
	case 0:
		std::move(cards.begin() + randomized - 1, cards.begin() + randomized, std::back_inserter(playerCards));
		PlayerCardValue = 0;
		for (auto& i : playerCards)
			PlayerCardValue += i;
		break;
	case 1:
		std::move(cards.begin() + randomized - 1, cards.begin() + randomized, std::back_inserter(dealerCards));
		DealerCardvalue = 0;
		for (auto& i : dealerCards)
			DealerCardvalue += i;
		break;
	}
}

void DealerTurn()
{
	dealerBusted = false;
	for (int i = 0; i < 2; i++)
	{
		GetCard(1);
	}

	while (true)
	{
		system("CLS");

		if (DealerCardvalue == 17)
		{
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			std::cout << "Dealer stands!" << endl;
			dealerDone = true;
			Sleep(2000);
			break;
		}
		else if (DealerCardvalue > 21)
		{
			dealerBusted = true;
			dealerDone = true;
			std::cout << "Your hand: " << PlayerCardValue << endl;
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			std::cout << "Dealer busted!" << endl;
			Sleep(2000);
		}
		else if (DealerCardvalue > 17)
		{
			std::cout << "Your hand: " << PlayerCardValue << endl;
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			std::cout << "Dealer Stands!" << endl;
			Sleep(2000);
			dealerDone = true;
		}
		else if (DealerCardvalue < PlayerCardValue)
		{
			if (DealerCardvalue < 17 && PlayerCardValue > 16)
			{
				GetCard(1);
				std::cout << "dealer hits" << endl;
				Sleep(2000);
				std::cout << "Your hand: " << PlayerCardValue << endl;
				std::cout << "Dealer hand: " << DealerCardvalue << endl;
				Sleep(2000);
			}
			else
			{
				std::cout << "Dealer Stands!" << endl;
				Sleep(2000);
				std::cout << "Your hand: " << PlayerCardValue << endl;
				std::cout << "Dealer hand: " << DealerCardvalue << endl;
				Sleep(2000);
				dealerDone = true;
			}
		}
		else
		{
			std::cout << "Dealer Stands!" << endl;
			Sleep(2000);
			std::cout << "Your hand: " << PlayerCardValue << endl;
			std::cout << "Dealer hand: " << DealerCardvalue << endl;
			Sleep(2000);
			dealerDone = true;
		}

		system("CLS");
		std::cout << "Your hand: " << PlayerCardValue << endl;
		std::cout << "Dealer hand: " << DealerCardvalue << endl;
		Sleep(2000);
		if (dealerDone == true)
		{
			break;
		}
	}
	
	if (PlayerCardValue > DealerCardvalue || dealerBusted == true)
	{
		bettedCredits *= 2;
		std::cout << "Player wins!\nCredits earned: " << bettedCredits << endl;
		credits += bettedCredits;
		Sleep(2000);
	}
	else if (PlayerCardValue < DealerCardvalue && dealerBusted == false)
	{
		std::cout << "You lost!" << endl;
		credits -= bettedCredits;
		Sleep(2000);
	}
	else if (PlayerCardValue == DealerCardvalue) 
	{
		std::cout << "Push!";
		Sleep(2000);
		credits += bettedCredits;
	}
}

int main()
{
	FillCardVector();
	//Instructions();

	while (playerName.empty())
	{
		std::cout << "Please enter your name" << endl;
		std::cin >> playerName;
	}

	while (true)
	{
		dealerDone = false;
		std::cout << "New Round!";

		PlayerCardValue = 0;
		DealerCardvalue = 0;

		playerCards.clear();
		dealerCards.clear();

		Sleep(2000);

		while (true)
		{
			system("CLS");
			std::cout << "Credits in account: " << credits << endl;
			std::cout << "How much credits do wish to bet?" << endl;
			std::cin >> playerInput;
			bettedCredits = std::stoi(playerInput);
			if (bettedCredits <= credits)
			{
				std::cout << bettedCredits << " in the game" << endl;
				Sleep(2000);
				break;
			}
			else
			{
				std::cout << "Not enough credits!" << endl;
				Sleep(2000);
			}
		}

		for (int i = 0; i < 2; i++)
		{
			GetCard(0);
		}

		if (PlayerCardValue == 21)
		{
			std::cout << "BlackJack!";
			Sleep(2000);
			system("CLS");
			bettedCredits *= 2.5f;
			credits += bettedCredits;
		}
		else
		{
			while (true)
			{
				system("CLS");
				std::cout << "Your hand: " << PlayerCardValue << endl;
				std::cout << "1: Draw an extra card \n2: Hold" << endl;

				std::cin >> playerInput;
				choice = stoi(playerInput);

				if (choice == 1)
				{
					GetCard(0);
					if (PlayerCardValue > 21)
					{
						std::cout << "Your hand: " << PlayerCardValue << endl;
						std::cout << "Busted!" << endl;
						Sleep(2000);
						break;
					}
				}
				else if (choice == 2)
				{
					std::cout << "Stand!" << endl;
					Sleep(200);
					std::cout << "Dealer turn" << endl;
					Sleep(2000);
					DealerTurn();
					break;
				}
			}
		}
	}
}

#pragma region Later Use
//system("CLS");
#pragma endregion
