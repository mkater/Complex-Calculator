#pragma once
#include "Token.h"
class Number : public Token
{
private:
	int value;	//private int value

public:
	Number();	//default constructor
	Number(char digit);
	const Number & operator=(const Number & rhs);	//operator equals
	int getValue();
	void setValue(int v);
	string toString();
};