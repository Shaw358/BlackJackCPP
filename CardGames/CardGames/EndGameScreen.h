#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "Player.h"
#include "Dealer.h"

class EndGameScreen
{
public:
	EndGameScreen();
	~EndGameScreen();

	void ShowResults(Dealer* dealer, std::vector<Player*>* players);
private:

};