#pragma once
#include "stdafx.h"
#include <vector>
#include "MyInt.h"
using namespace std;
#define f(a) (a + a) // 简单的字符替换。

typedef int(*pFunc) (int i); // 为一个类型起新名字。：代码简化，：平台开发
typedef int (func)(int i);
#include "shapeHeader.h"
using namespace shape::shape1;
namespace C_Plus_Plus_Basic
{
	int methodA(int i)
	{
		return i;
	}

	char space = ' ';

	void testVoidPointer()
	{
		char ch = '@';
		void *p = &ch;
		cout << "char ch = '@';" << endl << "void *p = &ch;" << endl;
		cout << space << "p=" << p << endl;
		//cout<<"*p="<<*p<<endl; /* illegal indirection. */
		cout << space << "*((char*)p)=" << *((char*)p) << endl;
		void *q;
		cout << "void *q;" << endl;
		q = malloc(4);
		cout << "q = malloc(4);" << endl;
		cout << space << "q=" << q << endl;
		cout << space << "&q=" << &q << endl;
		cout << space << "*((int*)q)=" << *((int*)q) << endl;
		cout << space << "*(char*)q=" << *(char*)q << endl;
		*((int*)q) = 1;
		int r = *(int*)q;
		cout << "*((int*)q) = 1;" << endl << "int r = *(int*)q;" << endl;
		cout << space << "r=" << r << endl;
		cout << endl;
	}

	void testPointerToPointer_ArrayOfPointers()
	{
		// Array of pointer.
		char *arA[] = { "C++", "C#", "OpenGL", "WindowsAPI", "3D" };
		// Pointer pointer.
		char **p = arA;
		int i = -1;
		while (++i < 5)
			cout << space << "i=" << i << space << "**(arA+i)=" << **(arA + i) << endl;
		i = -1;
		while (++i < 5)
			cout << space << "i=" << i << space << "**(p+i)=" << **(p + i) << endl;
		cout << endl;
	}

	void testPointerToArray_ArrayOfPointers()
	{
		int i, j;
		int m[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		cout << "int m[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};";
		int(*p)[4];
		int *q[3];

		p = m;
		cout << "int (*p)[1] = m" << endl;
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 4; ++j)
			{
				cout << space << "i=" << i << space << "j=" << j << space << "*(*(p+i)+j)=" << (*(*(p + i) + j)) << endl;
			}
		}

		cout << "for(i=0;i<3;++i,++p)" << endl << "{cout<<**p<<*(*p+1)<<*(*p+1)<<*(*p+2)<<*(*p+3)}" << endl;
		cout << space << "**p" << space << "*(*p+1)" << space << "*(*p+2)" << space << "*(*p+3)" << endl;
		for (i = 0; i < 3; ++i, ++p)
		{
			cout << space << **p << space << *(*p + 1) << space << *(*p + 2) << space << *(*p + 3) << endl;
		}

		cout << "for(i=0;i<3;++i)" << endl;
		cout << "{ q[i] = m[i]; }" << endl;
		for (i = 0; i < 3; ++i)
		{
			q[i] = m[i];
		}

		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 4; ++j)
				cout << space << "i=" << i << space << "j=" << j << space << "q[i][j]=" << q[i][j] << space << "*(q[i]+j)=" << *(q[i] + j) << space << "*(q[0]+j+4*i)=" << *(q[0] + j + 4 * i) << endl;
		}

		char *name[] = { "BASIC", "FORTRAN", "C++", "Pascal", "COBOL" };
		int number[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		char *k;
		int *l;
		i = 0;
		j = 0;
		cout << "char *name[] = {\"BASIC\",\"FORTRAN\",\"C++\",\"Pascal\",\"COBOL\"};" << endl;
		cout << "int number[] = {0,1,2,3,4,5,6,7,8,9,10,11};" << endl;
		cout << space << "name=" << name << space << "&name=" << &name << space << "&name[0]=" << &name[0] << endl;
		cout << space << "number=" << number << space << "&number=" << &number << space << "&number[0]=" << &number[0] << endl;
		cout << "char *k;" << endl;
		cout << "int *l;" << endl;
		cout << "i=0;" << endl;
		cout << "j=0;" << endl;
		cout << "while(i<5)" << endl;
		cout << "{" << endl;
		cout << space << "k=*(name+i++);" << endl;
		cout << space << "l=(number+j++);" << endl;
		cout << space << "cout<<&k<<*k<<k<<&l<<l<<*l<<endl;" << endl;
		cout << "}" << endl;
		while (i < 5)
		{
			k = *(name + i++);
			l = (number + j++);
			cout << space << &k << space << *k << space << k << space << &l << space << l << space << *l << endl;
		}
		i = 0;
		cout << "while(i<5)" << endl;
		cout << "{" << endl;
		cout << space << "cout<<&*(name+i)<<**(name+i)<<*(name+i)<<endl;" << endl;
		cout << space << "i++;" << endl;
		cout << "}" << endl;
		while (i < 5)
		{
			cout << space << &*(name + i) << space << **(name + i) << space << *(name + i) << endl;
			i++;
		}
		cout << endl;
	}

	void arrayCopy(int *src, int *destination, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			*(destination + i) = *(src + i);
		}
	}

	void display(int *arA, int size)
	{
		for (int i = 0; i < size; ++i)
		{
			cout << space << "i=" << i << space << "arA+i=" << arA + i << space << "*(arA+i)=" << *(arA + i) << endl;
		}
	}

	int* max(int *p, int size)
	{
		int *max = p;
		for (int i = 0; i<size; ++i)
		{
			if (*(p + i)>*max)
				max = p + i;
		}
		return max;
	}

	void testPointerParameter_PointerFunction()
	{
		int arA[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int arB[10];
		cout << "int arA[] = {0,1,2,3,4,5,6,7,8,9};" << endl;
		cout << "int arB[10];" << endl;
		cout << "arrayCopy(arA, arB, sizeof(arA)/sizeof(int));" << endl;
		arrayCopy(arA, arB, sizeof(arA) / sizeof(int));
		cout << "The data of array arA is:" << endl;
		display(arA, sizeof(arA) / sizeof(int));
		cout << "The data of array arB is:" << endl;
		display(arB, sizeof(arB) / sizeof(int));

		int arC[] = { 9, 1, 0, 6, 11, 88, 100, 7, 66, 3 };
		cout << "int arC[] = {9,1,0,6,11,88,100,7,66,3};" << endl;
		cout << space << "The max number is:" << space << max(arC, sizeof(arC) / sizeof(int)) << endl;
		cout << space << "The max number is:" << space << *max(arC, sizeof(arC) / sizeof(int)) << endl;
		cout << endl;
	}

	void testNew_Delete()
	{
		int size = 10;
		int *heapA = new int[size];
		cout << "int size = 10;" << endl;
		cout << "int *heapA = new int[size];" << endl;
		for (int i = 0; i < size; ++i)
		{
			cout << space << "i=" << i << space << "heapA+i=" << heapA + i << space << "*(heapA+i)=" << *(heapA + i) << endl;
		}
		delete[] heapA;

		for (int i = 0; i < size; ++i)
		{
			char *c = new char[2];
			char *temp = new char[2];
			sprintf(temp, "%d", i);
			cout << space << "&temp=" << &temp << space << "temp=" << temp << endl;
			sprintf(c, "%d", i);
			cout << space << "*c=" << *c << endl;
			delete[] c;
		}
		cout << endl;
	}

	void testPointerPlusPlus()
	{
		int a[4][5];
		int(*b)[5];
		b = a;
		int i, j;
		int value = 0;
		cout << "*(*b+j) = value;" << endl;
		for (i = 0; i < 4; ++i)
		{
			int *temp = *b;
			cout << "int *temp = *b" << endl;
			for (j = 0; j < 5; ++j)
			{
				*(*b + j) = value;
				cout << space << "j=" << j << space << "b=" << b << space << "*b=" << *b << space << "*b+j=" << *b + j << space << "*(*b+j)=" << *(*b + j) << space << "*(temp++)=" << *(temp++) << endl;
				value++;
			}
			b++;
			cout << "b++" << endl;
		}

		b = a;
		cout << "Read array" << endl;
		cout << "*temp = *b" << endl;
		cout << "*temp1 = *b" << endl;
		cout << "*temp2 = *b" << endl;
		cout << "*temp3 = *b" << endl;
		cout << "*temp4 = *b" << endl;
		for (i = 0; i < 2; ++i)
		{
			int *temp = *b;
			int *temp1 = *b;
			int *temp2 = *b;
			int *temp3 = *b;
			int *temp4 = *b;
			for (j = 0; j < 3; ++j)
			{
				cout << space << "j=" << j << endl;
				cout << space << "temp+j=" << temp + j << space << "temp1=" << temp1 << space << "temp2=" << temp2 << space << "temp3=" << temp3 << space << "temp4=" << temp4 << endl;
				cout << space << "*(temp+j)=" << *(temp + j) << space << "*(temp1++)=" << *((temp1++)) << space << "*(++temp2)=" << *(++temp2) << space << "*temp3++=" << *temp3++ << space << "*++temp4=" << *++temp4 << endl;
				cout << space << "temp+j=" << temp + j << space << "temp1=" << temp1 << space << "temp2=" << temp2 << space << "temp3=" << temp3 << space << "temp4=" << temp4 << endl;
			}
			b++;
			cout << "b++" << endl;
		}

		cout << endl;
	}

	char* getStr1(void)
	{
		char p[] = "happy life!";
		char *pP = p;
		return pP;
	}

	char* getStr2(void)
	{
		char *p = "happy life!";
		return p;
	}

	void testStackArea_StaticDataAreaInLifeCycleOfFunctions()
	{
		char *p1 = getStr1();
		char *p2 = getStr2();
		cout << "printf(\"p1=%x, p2=%x\")" << endl;
		printf("%cp1=%x, p2=%x\n", space, p1, p2);
		cout << "printf(\"p1=%s, p2=%s\")" << endl;
		printf("%cp1=%s, p2=%s\n", space, p1, p2);
		cout << "cout<<p1<<&p1<<*p1" << endl;
		cout << space << "p1=" << p1 << space << "&p1=" << &p1 << space << "*p1=" << *p1 << endl;
		cout << "cout<<p2<<&p2<<*p2" << endl;
		cout << space << "p2=" << p2 << space << "&p2=" << &p2 << space << "*p2=" << *p2 << endl;

		cout << endl;
	}

	void testMultiDimensionalArray()
	{
		int const m = 3, n = 3; // must be const.
		int arA[m][n] = { 0, 1, 2, 10, 11, 12, 20, 21, 22 };
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int maxValue = 0;
			for (int j = 0; j<m; ++j)
			{
				if (arA[j][i] > maxValue)
					maxValue = arA[j][i];
				//// the same.
				//if(*(*(arA+j)+i) > maxValue)
				//	maxValue = *(*(arA+j)+i);
			}
			sum += maxValue;
		}
		int i = -1;
		cout << space << "i=" << i << endl;
		int lessThanAverage = 0, moreThanAverage = 0;
		while (++i < m*n)
		if (*(*arA + i) < sum / n)
			lessThanAverage++;
		else
			moreThanAverage++;
		cout << space << "lessThanAverage=" << lessThanAverage << space << "moreThanAverage=" << moreThanAverage << endl;

		cout << endl;
	}

	enum day{ sunday, monday, tuesday, wednesday, thursday, friday, saturday };

	void nextDay(day &D)
	{
		switch (D)
		{
		case sunday:
			D = monday;
			break;
		case monday:
			D = tuesday;
			break;
		case tuesday:
			D = wednesday;
			break;
		case wednesday:
			D = thursday;
			break;
		case thursday:
			D = friday;
			break;
		case friday:
			D = saturday;
			break;
		case saturday:
			D = sunday;
			break;
		}

	}

	void displayDay(day D)
	{
		switch (D)
		{
		case sunday:
			cout << space << "sunday" << endl;
			break;
		case monday:
			cout << space << "monday" << endl;
			break;
		case tuesday:
			cout << space << "tuesday" << endl;
			break;
		case wednesday:
			cout << space << "wednesday" << endl;
			break;
		case thursday:
			cout << space << "thursday" << endl;
			break;
		case friday:
			cout << space << "friday" << endl;
			break;
		case saturday:
			cout << space << "saturday" << endl;
			break;
		}
	}

	void testEnum()
	{

		day today = sunday;
		for (int i = 0; i < 7; ++i)
		{
			cout << space << "Data in today=" << today << endl;
			displayDay(today);
			nextDay(today);
		}

		cout << endl;
	}

	void change(int &i, int &j)
	{
		int temp = i;
		i = j;
		j = temp;
	}

	void sort(int &i, int &j, int &k)
	{
		void change(int &, int &);
		if (i > j)change(i, j);
		if (i > k)change(i, k);
		if (j > k)change(j, k);
	}

	void testArgument()
	{
		int a = 10, b = 9, c = 8;
		int a1 = a, b1 = b, c1 = c;
		cout << space << "a=" << a << space << "b=" << b << space << "c=" << c << endl;
		void sort(int &, int &, int &);
		sort(a1, b1, c1);
		cout << space << "sorted order is:" << a1 << space << b1 << space << c1 << endl;

		cout << endl;
	}

	void setValue(char arA[], int arALength, char arB[], int arBLength)
	{
		int i = -1;
		if (arALength < arBLength)
		while (++i < arALength)
		{
			*(arA + i) = *(arB + i);
		}
		else
		{
			int i = -1;
			while (++i < arALength)
			{
				if (i < arBLength)
					*(arA + i) = *(arB + i);
				else
					*(arA + i) = space;
			}
		}
	}

	void testStruct()
	{
		void setValue(char arA[], int arALength, char arB[], int arBLength);
		const int nameLength = 10;
		const int departmentLength = 10;
		struct student;
		struct student
		{
			int id;
			char name[nameLength];
			int age;
			char department[departmentLength];
		};
		student s1, s2;
		s1.id = 1;
		setValue(s1.name, nameLength, "eric", 5);
		s1.age = 18;
		setValue(s1.department, departmentLength, "english", 8);
		s2.id = 2;
		setValue(s2.name, nameLength, "lily", 5);
		s2.age = 17;
		setValue(s2.department, departmentLength, "nursing", 8);
		cout << space << "s1.id=" << s1.id << endl;
		cout << space << "s1.name=" << s1.name << endl;
		cout << space << "s1.age=" << s1.age << endl;
		cout << space << "s1.department=" << s1.department << endl;
		cout << space << "s2.id=" << s2.id << endl;
		cout << space << "s2.name=" << s2.name << endl;
		cout << space << "s2.age=" << s2.age << endl;
		cout << space << "s2.department=" << s2.department << endl;
		cout << "s1 = s2;" << endl;;
		s1 = s2;
		cout << space << "s1.id=" << s1.id << endl;
		cout << space << "s1.name=" << s1.name << endl;
		cout << space << "s1.age=" << s1.age << endl;
		cout << space << "s1.department=" << s1.department << endl;

		cout << endl;
	}

	void showLengthUseArrayReference(char(&arA)[20])
	{
		cout << space << sizeof(arA) << endl;
	}

	void showLength(char arA[20])
	{
		cout << space << sizeof(arA) << endl;
	}

	void testArrayLength()
	{
		char arA[20] = { 0, 1, 2, 3, 4, 5 };
		cout << space << sizeof(arA) << endl;
		showLengthUseArrayReference(arA);
		showLength(arA);

		cout << endl;
	}

	struct student
	{
		int id;
		char name[20];
		int age;
		char department[20];
	};

	void display(student s)
	{
		cout << space << "&s.name=" << &s.name << endl;
		cout << space << "s.name=" << s.name << endl;
	}

	student initialStruct()
	{
		student s = { 1, "lily", 17, "Nursing" };
		return s;
	}

	void testStructAndFunction()
	{
		student initialStruct();
		student s1 = { 1, "eric", 18, "ComputerScience" };
		cout << "student s1 = {1,\"eric\",18,\"ComputerScience\"};" << endl;
		cout << space << "&s1.name=" << &s1.name << endl;
		cout << "display(s1);" << endl;
		display(s1);
		cout << "display(s1);" << endl;
		display(s1);
		student s2 = initialStruct();
		cout << "student s2 = initialStruct();" << endl;
		cout << space << "&s2.name=" << &s2.name << endl;
		cout << "display(s2);" << endl;
		display(s2);
		cout << "display(s2);" << endl;
		display(s2);
		cout << endl;
	}

	void display(student *s)
	{
		cout << space << "&s->name=" << &s->name << endl;
		cout << space << "s->name=" << s->name << endl;
	}

	void testStructPointer()
	{
		student s1 = initialStruct();
		cout << "student s1 = initialStruct();" << endl;
		cout << space << "&s1.name=" << &s1.name << endl;
		cout << "display(&s1);" << endl;
		display(&s1);
		cout << "display(&s1);" << endl;
		display(&s1);
	}

	struct node
	{
		int data;
		node *next;
	};

	node* createLinkList(int count)
	{
		node *pHead = new node();
		node *pEnd;
		node *pNow;
		int j = -1;
		while (++j < count)
		{
			pNow = new node();
			pNow->data = j + 1;
			if (pHead->next == NULL)
			{
				pHead->next = pNow;
			}
			else
			{
				pEnd->next = pNow;
			}
			pEnd = pNow;
		}
		cout << "pHead in createLinkList function(int count)." << endl;
		cout << space << "&pHead=" << &pHead << space << "pHead=" << pHead << endl;
		cout << "return pHead;";
		return pHead;
	}

	void showLinkList(node *pHead)
	{
		cout << "parameter head in function showLinkList(node *pHead)" << endl;
		cout << space << "&pHead=" << &pHead << space << "pHead=" << pHead << endl;
		node *pNext = pHead;
		cout << "another variable pNext receive parameter pHead." << endl;
		cout << space << "&pNext=" << &pNext << space << "pNext=" << pNext << endl;
		do
		{
			cout << space << "data=" << pNext->data << space << "next=" << pNext->next << endl;
			pNext = pNext->next;
		} while (pNext != NULL);
	}

	node* searchNode(node *pHead, int keyWord)
	{
		do
		{
			if (pHead->data == keyWord)
				return pHead;
			pHead = pHead->next;
		} while (pHead != NULL);
		return NULL;
	}

	node* insertNode(node *pHead, int keyWord, int newData)
	{
		do
		{
			if (pHead->data == keyWord)
			{
				node *pNew = new node();
				pNew->next = pHead->next;
				pHead->next = pNew;
				return pNew;
			}
			pHead = pHead->next;
		} while (pHead != NULL);
		return NULL;
	}

	int deleteNode(node *pHead, int keyWord)
	{
		node *p;
		if (pHead == NULL)
			return false;
		else if (pHead->data == keyWord)
		{
			delete pHead;
			return true;
		}
		else if (pHead->next == NULL)
			return false;

		do
		{
			if (pHead->next->data == keyWord)
			{
				p = pHead->next;
				pHead->next = p->next;
				delete p;
				return true;
			}
			pHead = pHead->next;
		} while (pHead != NULL&&pHead->next != NULL);
		return false;
	}

	int destroyLinkList(node *pHead)
	{
		node *p;
		while (pHead != NULL)
		{
			p = pHead;
			pHead = pHead->next;
			delete p;
		}
		return 1;
	}

	void testLinkList()
	{
		cout << "node pHead = createLinkList(20);" << endl;
		node *pHead = createLinkList(20);
		cout << "pHead that receive return value" << endl;
		cout << space << "&pHead=" << &pHead << space << "pHead=" << pHead << endl;
		void showLinkList(node*);
		cout << "showLinkList(pHead);" << endl;
		showLinkList(pHead);
		node* searchNode(node*, int);
		cout << space << "searchNode(pHead,10)=" << searchNode(pHead, 10) << endl;
		node* insertNode(node*, int, int);
		cout << space << "insertNode(pHead,10,9)=" << insertNode(pHead, 10, 9) << endl;
		int deleteNode(node*, int);
		cout << space << "deleteNode(pHead,8)=" << deleteNode(pHead, 8) << endl;
		int destroyLinkList(node*);
		cout << space << "destroyLinkList(pHead)=" << destroyLinkList(pHead) << endl;
		cout << endl;
	}


	void testHeaderFile_Using()
	{
		circle c = { 2 };
		cout << space << "Perimeter of circle c=" << perimeter_of_circle(c.r) << endl;

		cout << endl;
	}

	class Base
	{
	public:
		void func()
		{
			cout << space << "Base::void func()" << endl;
		}
		void func(int n)
		{
			cout << space << "Base::void func(int n)=" << n << endl;
		}
		void func(char c)
		{
			cout << space << "Base::int func(char c)=" << c << endl;
		}
	};

	class Derive :Base
	{
	public:
		using Base::func;
		void func()
		{
			cout << space << "Derive::void func()" << endl;
		}
		void func(int m)
		{
			cout << space << "Derive::void func(int m)" << endl;
		}
	};

	void testDerive_Using()
	{
		cout << "Base b;" << endl;
		Base b;
		cout << "Derive d;" << endl;
		Derive d;
		cout << "b.func();" << endl;
		b.func();
		cout << "b.func(1);" << endl;
		b.func(1);
		cout << "d.func();" << endl;
		d.func();
		cout << "d.func(2);" << endl;
		d.func(2);

		cout << endl;
	}

	class StudentBase
	{
	public:
		int id;
		char name[20];
		StudentBase(void)
		{
			cout << space << "call StudentBase(void)" << space << "id=" << id << endl;
		}
		~StudentBase(void)
		{
			cout << space << "call ~StudentBase(void)" << space << "id=" << id << endl;
		}
	};

	class StudentDerive : public StudentBase
	{
	public:
		int age;
		char department[20];
		StudentDerive(void)
		{
			cout << space << "call StudentDerive(void)" << space << "id=" << id << endl;
		}
		~StudentDerive(void)
		{
			cout << space << "call ~StudentDerive(void)" << space << "id=" << id << endl;
		}
	};

	void setValue(int a, int b)
	{
		a = b;
	}

	StudentDerive* getStudentDerivePoint()
	{
		cout << "StudentBase b;" << endl;
		StudentBase b;
		cout << "b.id = 1;" << endl;
		b.id = 1;
		setValue(b.name, 20, "eric", 5);
		cout << "StudentDerive d;" << endl;
		StudentDerive d;
		cout << "d.id = 2;" << endl;
		d.id = 2;
		cout << space << "d.age=" << d.age << endl;
		cout << "setValue(d.age,17);" << endl;
		setValue(d.age, 17);
		cout << "setValue(d.name,20,\"lily\",5);" << endl;
		setValue(d.name, 20, "lily", 5);
		cout << "setValue(d.department,20,\"Nursing\",8);" << endl;
		setValue(d.department, 20, "Nursing", 8);
		cout << space << "d.age=" << d.age << endl;
		cout << space << "d.name=" << d.name << endl;
		cout << space << "d.department=" << d.department << endl;
		cout << "d.age = 17;" << endl;
		d.age = 17;
		cout << space << "d.age=" << d.age << endl;
		cout << space << "getStudentDerivePoint:" << space << "&d=" << &d << endl;
		cout << "StudentDerive* pD = &d;" << endl;
		StudentDerive* pD = &d;
		cout << space << "&pD=" << &pD << endl;
		cout << "return pD;" << endl;
		return pD;
	}

	StudentDerive getStudentDerive()
	{
		cout << "StudentBase b;" << endl;
		StudentBase b;
		cout << "b.id = 1;" << endl;
		b.id = 1;
		setValue(b.name, 20, "eric", 5);
		cout << "StudentDerive d;" << endl;
		StudentDerive d;
		cout << "d.id = 2;" << endl;
		d.id = 2;
		cout << space << "d.age=" << d.age << endl;
		cout << "setValue(d.age,17);" << endl;
		setValue(d.age, 17);
		cout << "setValue(d.name,20,\"lily\",5);" << endl;
		setValue(d.name, 20, "lily", 5);
		cout << "setValue(d.department,20,\"Nursing\",8);" << endl;
		setValue(d.department, 20, "Nursing", 8);
		cout << space << "d.age=" << d.age << endl;
		cout << space << "d.name=" << d.name << endl;
		cout << space << "d.department=" << d.department << endl;
		cout << "d.age = 17;" << endl;
		d.age = 17;
		cout << space << "d.age=" << d.age << endl;
		cout << space << "getStudentDerive:" << space << "&d=" << &d << endl;
		cout << "return d;" << endl;
		return d;
	}

	void testDestructor()
	{
		cout << "StudentDerive *pD = getStudentDerivePoint();" << endl;
		StudentDerive *pD = getStudentDerivePoint();
		cout << "StudentDerive *pD recieve the return value" << endl;
		cout << space << "pD=" << pD << endl;
		cout << space << "&pD=" << &pD << endl;
		cout << space << "pD->name=" << pD->name << endl;
		cout << endl;
		cout << "StudentDerive d = getStudentDerive();" << endl;
		StudentDerive getStudentDerive();
		StudentDerive d = getStudentDerive();
		cout << "StudentDerive d recieve return value" << endl;
		cout << space << "&d=" << &d << endl;
		cout << space << "d.name=" << d.name << endl;

		cout << "end" << endl;
	}

	void testVector()
	{
		vector<char> stack(0);
		char input;
		cout << "Input char:" << endl;
		do
		{
			cin >> input;
			if (input != '#')
			{
				if (input != '$')
				{
					stack.push_back(input);
				}
				else
				{
					stack.pop_back();
				}
			}
		} while (input != '#');
		for (unsigned i = 0; i < stack.size(); ++i)
		{
			cout << space << stack[i];
		}
		cout << endl;
	}

	class myStudent
	{
	public:
		int id;
		myStudent()
		{
			cout << space << "Constructing a myStudent." << space << "id=" << id << endl;
		}
		~myStudent(void)
		{
			cout << space << "~myStudent" << space << "id=" << id << endl;
		}

		myStudent::myStudent(int id)
		{
			this->id = id;
			cout << space << "Constructing a myStudent." << space << "id=" << id << endl;
		}

		virtual void myStudent::study()
		{
			cout << space << "study somthing." << space << "id=" << id << endl;
		}

		void myStudent::study(int i)
		{
			cout << space << "overload study" << endl;
		}
	};



	class Undergraduate :public myStudent
	{
	public:
		Undergraduate::Undergraduate(int para)
		{
			id = para;
			cout << space << "Constructing a Undergraduate." << space << "id=" << id << endl;
		}

		~Undergraduate(void)
		{
			cout << space << "~Undergraduate" << space << "id=" << id << endl;
		}
		int getId()
		{
			return id;
		}

		virtual void Undergraduate::study()
		{
			cout << space << "Study Higher Mathematics and College English." << space << "id=" << id << endl;
		}


	};

	class Pupil :public myStudent
	{
	public:
		virtual void Pupil::study()
		{
			cout << space << "Study Language Mathematics and Foreign language." << space << "id=" << id << endl;
		}

		Pupil::Pupil(int para) :myStudent(para)
		{
			id = para;
			cout << space << "Constructing a Pupil." << space << "id=" << id << endl;
		}

		~Pupil(void)
		{
			cout << space << "~Pupil" << space << "id=" << id << endl;
		}
	};

	void testPolymorphic_VirtualFunction_Assignment()
	{
		/*在C++中，对象可以被分配在静态数据区、栈空间或堆空间。被分配在静态数据区的对象在其定义时声明
	为static，其在编译时刻被放入静态数据区。栈空间的对象是通过对象的显式声明分配的。堆中的对象则是通过new分配的。*/

		/* Allocated heap memory */
		{
			Undergraduate *s1 = new Undergraduate(1);
			myStudent *s2 = new myStudent(2);
			Pupil *s3 = new Pupil(3);
			myStudent *pS = s1;
			pS->study();
			pS = s2;
			pS->study(1);
			pS = s3;
			pS->study();

			delete s1;
			delete s2;
			delete s3;
		}

		/*Allocated on the stack.*/
		{
		Undergraduate s1(1);
		myStudent s2(2);
		Pupil s3(3);
		int i = -1;
		{
			cout << "enter into brackets." << endl;
			cout << "create new obj." << endl;
			s1 = Undergraduate(4);
			s2 = myStudent(5);
			s3 = Pupil(6);
			cout << "call virtual function." << endl;
			myStudent *pS = &s1;
			pS->study();
			pS = &s2;
			pS->study();
			pS = &s3;
			pS->study();
		}
		cout << "get out from brackets." << endl;
		cout << endl;
	}
	}

	void testAnd()
	{
		int x = 55;
		cout << "int x = " << x << endl;
		int count = 0;
		while (x)
		{
			x = x&(x - 1);
			count++;
			cout << space << "x&(x-1)=" << x << endl;
		}
		cout << space << "count=" << count << endl;
	}

	void testReferenceAndPointer()
	{
		string str = "123456";
		string& ref = str;
		string* pointer = &str;
		cout << "sizeof(ref): " << sizeof(ref) << space << "sizeof(pointer): " << sizeof(pointer) << endl;

		int i = 1;
		int& ref1 = i;
		int x = ref1;
		cout << "x=" << x << endl;

		ref1 = 2;
		int* p = &i;
		cout << "ref1=" << ref1 << space << "i=" << i << endl;

		int I = 1;
		int J = 10;
		const int& REF = I;
		const int* POINTER = &REF;
		I = 2;
		//REF = 3; //REF cant't be modified;
		POINTER = &J;
		J++;
		//(*POINTER)++; // *POINTER cant't be modified;
	}

	/*************************/
	void testRefPara(int& i)
	{
		i++;
	}

	void testPointerPara(int* i)
	{
		(*i)++;
	}

	void testRefParaAndPointerPara()
	{
		int i = 0;
		cout << "i=" << i << endl;
		testRefPara(i);
		cout << "testRefPara(i):" << "i=" << i << endl;
		testPointerPara(&i);
		cout << "testPointerPara(&i):" << "i=" << i << endl;
	}
	/************************/

	void b()
	{
		printf("1.Test malloc \n");
		void *test_malloc;
		cout << "*test_malloc;" << endl;
		test_malloc = malloc(4);
		cout << space << "test_malloc=" << test_malloc << endl;
		cout << endl;

		printf("2.Test operator\n");
		MyInt myInt1;
		cout << space << "myInt1.value=" << myInt1.value << endl;
		cout << space << "myInt1++=" << myInt1++.value << endl;
		cout << space << "++myInt1=" << ++myInt1.value << endl;
		cout << space << "myInt1+33=" << (myInt1 + 33).value << endl;
		cout << space << "myInt1.cA=" << myInt1.cA << endl;

		MyInt *myInt2 = new MyInt();
		cout << space << "myInt2->value=" << myInt2->value << endl;
		cout << space << "myInt1+*myInt2=" << (myInt1 + *myInt2).value << endl;
		cout << space << "myInt2->cA=" << myInt2->cA << endl;
		cout << space << "myInt2.statI=" << MyInt::statI << endl;
		cout << space << "myInt2.conI=" << MyInt::conI << endl;

		printf("3.Test constructor and ()\n");
		MyInt *myInt3 = new MyInt;
		cout << space << "myInt3.value=" << myInt3->value << endl;
		cout << space << "myInt3=" << myInt3 << endl;
		cout << space << "(++myInt3)=" << (++(*myInt3)).value << endl;
		cout << space << "++(myInt3->value)=" << ++(myInt3->value) << endl;
		cout << space << "myInt3.value=" << myInt3->value << endl;
		cout << space << "myInt3+=33=" << (myInt3 += 33)->value << endl;
		cout << space << "myInt3=" << myInt3 << endl;
		cout << space << "myInt3.cA=" << myInt3->cA << endl;

		MyInt *myInt4 = new MyInt();
		/*cout<<space<<"myInt4.value="<<myInt4->value<<endl;
		cout<<space<<"myInt4="<<myInt4<<endl;
		cout<<space<<"myInt4++="<<myInt4++->value<<endl;
		cout<<space<<"myInt4="<<myInt4<<endl;
		int value = ++myInt4->value;
		cout<<space<<"++myInt4="<<value<<endl;
		cout<<space<<"myInt4="<<myInt4<<endl;
		cout<<space<<"myInt4+33="<<(myInt4+33)->value<<endl;
		cout<<space<<"myInt4.cA="<<myInt4->cA<<endl;
		cout<<endl;*/

		printf("4.Test cout<< and ++\n");
		cout << space << "sizeof(myInt4->cA)" << sizeof(myInt4->cA) << endl;
		cout << space << "sizeof(myInt4->intB)" << sizeof(myInt4->intB) << endl;
		cout << space << "sizeof(myInt4->dC)" << sizeof(myInt4->dC) << endl;
		cout << space << "sizeof(myInt4->value)" << sizeof(myInt4->value) << endl;
		cout << space << "myInt4=" << myInt4 << " : ++myInt4->value=" << ++myInt4->value << endl;
		cout << space << "myInt4=" << myInt4 << " : ++myInt4->value=" << ++myInt4->value << endl;
		cout << space << "myInt4=" << myInt4 << " : ++myInt4->value=" << ++myInt4->value << endl;
		cout << space << "myInt4=" << myInt4 << " : ++myInt4->value=" << ++myInt4->value << endl;
		cout << space << "myInt4=" << myInt4 << endl;
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "myInt4=" << myInt4 << endl;
		cout << space << "myInt4=" << myInt4 << " : myInt4++->value=" << myInt4++->value << endl;
		cout << space << "myInt4=" << myInt4 << " : myInt4++->value=" << myInt4++->value << endl;
		cout << space << "myInt4=" << myInt4 << " : myInt4++->value=" << myInt4++->value << endl;
		cout << space << "myInt4=" << myInt4 << " : myInt4++->value=" << myInt4++->value << endl;
		cout << space << "myInt4=" << myInt4 << endl;
		cout << space << "myInt4++->value=" << myInt4++->value << " : myInt4=" << myInt4 << endl;
		cout << space << "myInt4++->value=" << myInt4++->value << " : myInt4=" << myInt4 << endl;
		cout << space << "myInt4++->value=" << myInt4++->value << " : myInt4=" << myInt4 << endl;
		cout << space << "myInt4++->value=" << myInt4++->value << " : myInt4=" << myInt4 << endl;
		cout << space << "myInt4=" << myInt4 << endl;
		int i = 0;
		cout << space << "i=" << i << endl;
		cout << space << "i=" << i << " : i++=" << (i++) << endl;
		cout << space << "i=" << i << " : i++=" << i++ << endl;
		cout << space << "i=" << i << " : i++=" << i++ << endl;
		cout << space << "i=" << i << " : i++=" << i++ << endl;
		cout << space << "i=" << i << endl;
		cout << space << "i=" << i << " : (i++)=" << (i++) << endl;
		cout << space << "i=" << i << " : (i++)=" << (i++) << endl;
		cout << space << "i=" << i << " : (i++)=" << (i++) << endl;
		cout << space << "i=" << i << " : (i++)=" << (i++) << endl;
		cout << space << "i=" << i << endl;
		cout << space << "i++=" << i++ << " : i=" << i << endl;
		cout << space << "i++=" << i++ << " : i=" << i << endl;
		cout << space << "i++=" << i++ << " : i=" << i << endl;
		cout << space << "i++=" << i++ << " : i=" << i << endl;
		cout << space << "i=" << i << endl;
		cout << space << "(i++)=" << (i++) << " : i=" << i << endl;
		cout << space << "(i++)=" << (i++) << " : i=" << i << endl;
		cout << space << "(i++)=" << (i++) << " : i=" << i << endl;
		cout << space << "(i++)=" << (i++) << " : i=" << i << endl;
		cout << space << "i=" << i << endl;
		cout << space << "i=" << i << " : ++i=" << ++i << endl;
		cout << space << "i=" << i << " : ++i=" << ++i << endl;
		cout << space << "i=" << i << " : ++i=" << ++i << endl;
		cout << space << "i=" << i << " : ++i=" << ++i << endl;
		cout << space << "i=" << i << endl;
		cout << space << "++i=" << ++i << " : i=" << i << endl;
		cout << space << "++i=" << ++i << " : i=" << i << endl;
		cout << space << "++i=" << ++i << " : i=" << i << endl;
		cout << space << "++i=" << ++i << " : i=" << i << endl;
		cout << space << "i=" << i << endl;

		printf("5.Test sizeof\n");
		int b = 123L;
		cout << space << "sizeof(int) :" << sizeof(int) << endl;
		cout << "int b = 123L;" << endl;
		cout << space << "sizeof(b) : " << sizeof(b) << endl;
		cout << endl;

		printf("6.Test typedef \n");
		pFunc pFuncA = &methodA;
		cout << space << "pFuncA(1)=" << pFuncA(1) << endl;
		func &funcB = *pFuncA;
		cout << space << "funcB(2)=" << funcB(2) << endl;
		func &funcC = methodA;
		cout << space << "funcC(3)=" << funcC(3) << endl;
		cout << endl;

		printf("7.Test define\n");
		cout << "#define f(a) (a + a)" << endl;
		cout << space << "f(b)=" << f(b) << endl;
		cout << endl;

		printf("8.Test void* \n");
		testVoidPointer();

		printf("9.Test ** and *[m] \n");
		testPointerToPointer_ArrayOfPointers();

		printf("10.Test int (*p)[m] and int *q[3] \n");
		testPointerToArray_ArrayOfPointers();

		printf("11.Test int pointer fucntion and pointer parameter \n");
		testPointerParameter_PointerFunction();

		printf("12.Test new and delete \n");
		testNew_Delete();

		printf("13.Test pointer plus plus \n");
		testPointerPlusPlus();

		printf("14.Test stack area and static data area in life cycle of functions \n");
		testStackArea_StaticDataAreaInLifeCycleOfFunctions();

		printf("15.Test multidimensional array \n");
		testMultiDimensionalArray();

		printf("last.Test cin \n");
		cin >> b;
		cout << "b=" << b << endl;
		cout << endl;

		system("pause");

	}

	void a()
	{
		printf("1.Test enum\n");
		testEnum();

		printf("2.Test reference parameters\n");
		testArgument();

		printf("3.Test struct\n");
		testStruct();

		printf("4.Test array length\n");
		testArrayLength();

		printf("5.Test struct and function\n");
		testStructAndFunction();

		printf("6.Test struct pointer\n");
		testStructPointer();

		printf("7.Test link list \n");
		testLinkList();

		printf("8.Test header file and using\n");
		testHeaderFile_Using();

		printf("9.Test derive and using\n");
		testDerive_Using();

		printf("10.Test destructor\n");
		testDestructor();

		printf("10.Test vector\n");
		testVector();

		system("pause");
	}

	void c()
	{
		printf("1.Test polymorphic and virtual function and assignment\n");
		testPolymorphic_VirtualFunction_Assignment();

		printf("2.Test &\n");
		testAnd();

		printf("3.Test sizeof\n");
		testReferenceAndPointer();

		printf("4.Test Reference Parameter and Pointer Parameter");
		testRefParaAndPointerPara();

		system("pause");
	}
}

