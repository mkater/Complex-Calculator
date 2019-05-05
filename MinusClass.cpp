#include"Minus.h"

Number Minus::operate(Number a, Number b)
{
	Number sum;
	sum.setValue(a.getValue() - b.getValue());	//to get minus total of Numbers a and b
	return sum;
}

string Minus::toString()
{
	string minusSign = "-";
	return minusSign;		//returns a minus sign
}