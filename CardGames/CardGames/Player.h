#pragma once
#include <windows.h>
#include "Hand.h"

class Player
{
public:
	Player();
	~Player();
	Hand* getHand();
	int getBalance();
	void setBalance(int anAmount);

private:
	int balance;
	Hand* hand;
};