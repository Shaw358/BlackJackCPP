#include <iostream>
#include <string>
#include "vector"
#include <cctype>
using namespace std;

std::vector<int> cards;
std::vector<int> playerCards;
std::string playerName;
int randomized = 0;

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

void GetCard()
{
	for (int i = 0; i < 2; i++)
	{
		randomized = rand() % cards.size();

		std::move(cards.begin() + randomized, cards.begin() + randomized, playerCards.end());


		//playerCards.push_back(std::move(cards[randomized]));
	}
	for (auto i : cards)
		std::cout << "All cards: " << i << endl;

	for (auto j : playerCards)
		std::cout << "All player cards: " << j << endl;
}

int main()
{
	FillCardVector();
	GetCard();

	//std::cout << cards.capacity();

	/*while (playerName.empty())
	{
		std::cout << "Please enter your name";
		std::cin >> playerName;
	}*/

	unsigned short int PlayerCardValue = 0;

	//while (true)
	//{

	//}
}

#pragma region Later Use
//system("CLS");
#pragma endregion
