#include "Player.h"

Player::Player()
	:hand(new Hand()), balance(1000)
{
}

Player::~Player()
{
}

Hand* Player::getHand()
{
	return hand;
}

int Player::getBalance()
{
	return 0;
}

void Player::setBalance(int anAmount)
{

}

void Player::setBusted(bool newValue)
{
	isBusted = newValue;
}

bool Player::getBusted()
{
	return isBusted;
}
