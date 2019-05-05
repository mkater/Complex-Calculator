#pragma once
#include"Token.h"
#include"Number.h"
class Operator : public Token
{
public:
	virtual Number operate(Number a, Number b) = 0;	//abstract operate function used in plus and minus
};