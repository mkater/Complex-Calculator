#include <iostream>
#include"Minus.h"
#include"Number.h"
#include"Operator.h"
#include"Plus.h"
#include"Token.h"
#include<vector>
#include<string>
using namespace std;

bool checkIfValid(vector <Token *> myVectorPointer)		//checks if the vector is valid for the project
{
	bool validity = true;

	if (myVectorPointer.size() % 2 == 0)  //vector should be odd length as its always even # Num and one operand
	{
		validity = false;
	}

	for (unsigned int i = 0; i < myVectorPointer.size(); i++)	//loop through vector
	{
		if (i % 2 == 0)		//checking if even index it should be a number value
		{
			if (myVectorPointer[i] != dynamic_cast<Number*>(myVectorPointer[i]))	//if its not a Number
			{
				validity = false;
					break;
			}
		}

		else       //if i is at an odd index it should be an operator
		{
			if (myVectorPointer[i] != dynamic_cast<Operator*>(myVectorPointer[i])) //checks if operator
			{
				validity = false;
				break;
			}
		}
		
		
	}

	return validity;
}//end of checkifValid


ostream & operator <<(ostream & out, const vector <Token *> myVectorPointer) //override the '<<' operator
{
	
	for (unsigned int i = 0; i < myVectorPointer.size(); i++)	//loop through vector
	{
		out << myVectorPointer[i]->toString() << " ";		//outing each of the classes toString function
	}
	
	return out;
}//end of operator << override

Number resultOfExpression(vector <Token *> myVectorPointer)	//gets result of expression
{
	Number result = *(dynamic_cast<Number*>(myVectorPointer[0]));	//result is number, set to vector. we know first value is #.

	for (unsigned int i = 1; i < myVectorPointer.size(); i+=2)	//loop through vector to get operands specifically
	{
		Operator * currentOperator;		//create an operator pointer
		currentOperator = dynamic_cast<Operator*>(myVectorPointer[i]);	//point it to operand of vector
		Number * currentNumber;		//creating a pointer of number
		currentNumber = dynamic_cast<Number*>(myVectorPointer[i + 1]);		//setting it to the next value after operand
	

		result = currentOperator->operate(result, *currentNumber);	//stores result as operand of result and current #.  uses overriding op = sign to set equality.
	}
	return result;
}	//end of resultofExpression

void mathFunctions()
{

	char userInput;
	vector <Token *> s;	//creating vector of Token pointers
	cout << "Enter a list of tokens, terminate by entering ;" << endl;
	
	

	while(1)	//keeps repeating until break in loop.
	{
		cin >> userInput;

		if (userInput >= '0' && userInput <= '9')	//if user puts in a number
		{
			s.push_back(new Number(userInput));	//pushes a new Number of that value onto vector
		}
		else if (userInput == '+')
		{
			s.push_back(new Plus);	//puts in '+' if thats the choice.
		}
		else if (userInput == '-')
		{
			s.push_back(new Minus);	//same thing with '-'.
		}
		else if (userInput == ';')	//if user puts in ;
		{
			break;					//the loop stops.
		}
	} 
	
	cout << s << endl;		//our overriding << operator is used here to print the pointer vector

	if (checkIfValid(s) == true)		//checks if the vector is a valid vector
	{
		cout << "Answer is: " << resultOfExpression(s).getValue() << endl;
	}
	else
	{
		cout << "Not a valid expression" << endl;
		
	}
	
}	//end of mathFunction.

int main()
{
	
	while (1)
	{
		mathFunctions();	//main just loops for easier testing.
	}
	
}	//end of main