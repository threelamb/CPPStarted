#pragma once
#include <iostream>
using namespace std;
class LanguageFeatures
{
	int x(const int x) {return x + 1;}

	struct x
	{
		int x1;
	};

	#define x(x) x

public:
	void test()
	{
		void *x = calloc(1, sizeof x);
		x:(((struct x *)x)->x1) = x(5);
		printf("%p\n", ((struct x *)x)->x1);
		free(x);
		printf("%p\n", x);
		printf("%p\n", ((struct x *)x)->x1);
		system("pause");
	}
};

class Person
{
	int age;
	int gender;
public:
	Person()
	{
		age = 10;
		gender = 1;
	}
	virtual void eat()
	{
		cout<<"eat sometiong"<<endl;
	}
};

class Father : public Person
{
public:
	Person* child;
	void eat()
	{
		cout<<"smoking"<<endl;
	}
};

class Child : public Person
{
public:
	Person* father;
	void eat()
	{
		cout<<"eat Ice cream"<<endl;
	}
};

void testPerson()
{
	Father* fa = new Father();
	Child* ch = new Child();
	fa->child = ch;
	ch->father = fa;
	fa->eat();
	fa->child->eat();
	ch->eat();
	ch->father->eat();

	system("pause");
}

