#include "stdafx.h"
#include <iostream>
using namespace std;
namespace C_Plus_Plus_Basic
{
	char space1 = ' ';
	void showLengthUseArrayReference(char (&arA)[20])
	{
		cout<<space1<<sizeof(arA)<<endl;
	}

	void showLength(char arA[20])
	{
		cout<<space1<<sizeof(arA)<<endl;
	}
}