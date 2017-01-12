#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;
class MyInt
{
public:
	char cA;
	int intB;
	double dC;
	int value;
    static int statI;
	const static int conI = 1;
	MyInt(void);
	MyInt(int i);
	virtual ~MyInt(void);
	MyInt operator +(int);
	MyInt operator +(MyInt);
	MyInt operator ++(void);
	MyInt operator ++(int);
};




