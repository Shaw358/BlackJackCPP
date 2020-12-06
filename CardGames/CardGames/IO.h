#pragma once
#include <windows.h>
#include "string"
#include "InputEnum.h"

class IO
{
public:
	IO();
	~IO();

	std::string AskString(std::string aString, int aNumber);
	bool AskBool(std::string aString);
	int AskInt(std::string aString, int aNumber);
};