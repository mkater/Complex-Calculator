#include"Plus.h"
#include"Number.h"
#include <string>
Number Plus::operate(Number a, Number b)
{
	Number sum;	//Number sum ok due to default constructor
	sum.setValue(a.getValue() + b.getValue());	//sum of two numbers
	return sum;
}

string Plus::toString()
{
	string plusSign = "+";
	return plusSign; //returns string of +
}