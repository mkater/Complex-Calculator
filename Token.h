#pragma once
using namespace std;
#include <iostream>

class Token
{
public:

	virtual string toString() = 0;	//abstract virtual function. will be used in all other classes.

};