#include"Number.h"
#include<string>

Number::Number()		//default constructor
{

}
Number::Number(char input)	//takes in a char and gets the value in int
{
	value = input - '0';
}

int Number::getValue()
{
	return value;	//getter to return value
}


void Number::setValue(int v)		//setter to set value
{
	value = v;
}

string Number::toString()	//returns the to string value of the int
{
	return to_string(value);
}

const Number & Number:: operator=(const Number & rhs) //equals operator necessary for resultofExpression function to compare
{
	if (this != &rhs)
	{
		value = rhs.value;	//setting value of Number to be value of passed in Number
	}
	return *this;
}