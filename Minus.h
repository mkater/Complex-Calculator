#pragma once
#include"Operator.h"
class Minus : public Operator
{
public:
	Number operate(Number a, Number b);		//takes in two numbers and returns a number
	string toString();
};