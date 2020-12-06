#include "Card.h"
#include <iostream>

Card::Card(int aValue) :value(aValue)
{
}

Card::~Card()
{
}

int Card::GetValue()
{

	return value;

}

void Card::setValue(int aValue)
{

	value = aValue;

}

void Card::setCardType(int aValue = 0)
{

	typeOfCard = (CardType)aValue;

}

CardType Card::getCardType()
{
	return typeOfCard;
}


