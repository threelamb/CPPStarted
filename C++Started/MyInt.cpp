#include "StdAfx.h"
#include "MyInt.h"

MyInt::MyInt(void)
{
		cA = 'cB';
		intB = 1;
		dC = 1.1;
		value = 100;
}

MyInt::MyInt(int i)
{
		cA = 'cB';
		intB = 1;
		dC = 1.1;
		value = i;
}

int MyInt::statI = 1;

MyInt MyInt::operator  +(int i)
{
	value+=i;
	return *this;
}

MyInt MyInt::operator  +(MyInt myI)
{
	value+=myI.value;
	return *this;
}

MyInt MyInt::operator  ++()
{
	value++;
	return *this;
}

MyInt MyInt::operator ++(int)
{
	value++;
	return *this;
}

MyInt::~MyInt(void)
{

}
