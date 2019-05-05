#pragma once
#include"Operator.h"
#include"Number.h"
class Plus : public Operator
{
public:
	Number operate(Number a, Number b);	//takes in two Numbers returns a Number
	string toString();
};