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
	void setBusted(bool newValue);
	bool getBusted();

private:
	int balance;
	Hand* hand;
	bool isBusted;
};