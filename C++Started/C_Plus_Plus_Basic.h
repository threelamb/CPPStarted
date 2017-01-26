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
		/*
		将无类型指针转化成具体的类型指针，就可以从内存中取值了；
		你可以将无类型指针转化成任意类型，只是取出来的值不可控而已;
		"*"操作符只能对指针操作
		*/
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

	/*指向指针的指针，指针的数组*/
	void testPointerToPointer_ArrayOfPointers()
	{
		// Array of pointer.
		char* arA[] = { "C++", "C#", "OpenGL", "WindowsAPI", "3D" };
		// Pointer pointer.
		char** p = arA;
		int i = -1;
		while (++i < 5)
			cout << space << "i=" << i << space << "**(arA+i)=" << **(arA + i) << endl;
		i = -1;
		while (++i < 5)
			cout << space << "i=" << i << space << "**(p+i)=" << **(p + i) << endl;
		cout << endl;
	}

	/*指向数组的指针，指针的数组*/
	void testPointerToArray_ArrayOfPointers()
	{
		int i, j;
		int m[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		cout << "int m[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};";
		int(*p)[4]; //指向数组的指针
		int* q[3]; //指针的数组

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

	int* max(int* ary, int num)
	{
		int* max = ary;
		int i = -1;
		while (++i < num)
		{
			if (*max < *(ary + i))
			{
				max = ary + i;
			}
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
			char *c = new char[2]; //每次循环C地址不变，C指向的地址会变。
			char *temp = new char[2];
			sprintf(temp, "%d", i);
			cout << space << "&temp=" << &temp << space << "temp=" << temp << endl;
			sprintf(c, "%d", i);
			cout << space << "*c=" << *c << endl;
			delete[] c; //如果删除C,每次循环C地址不变，C指向的地址也不会变，猜测是内容管理器重复利用空间。
		}
		cout << endl;
	}

	void testPointerPlusPlus()
	{
		int a[4][5]; //C/C++中只有二维数组，没有交叉数组。
		int(*b)[5];  //可以用数组指针来操作二维数组。
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
	{//指针和数组是等价的，指针的移动操作和数组的下标操作是等价的。
		char p[] = "happy life!"; //数组名是数组的首地址指针。
		char *pP = p; //pP指向数组名的指针，也就是指针的指针。
		return pP;
	}

	char* getStr2(void)
	{
		char *p = "happy life!";
		return p;
	}

	void testStackArea_StaticDataAreaInLifeCycleOfFunctions()
	{
		char *p1 = getStr1();//指针的指针作为返回值，来到外层作用域时，其指向的内容就会被释放。
		char *p2 = getStr2();//指针作为返回值，来到外层作用域时，其指向的内容会保持。
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
			for (int j = 0; j < m; ++j)
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

	enum day { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

	//枚举是值类型，默认为值传递；所以此处形参定义为引用以达到操作原变量的目的。
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

	//C/C++方法参数是值传递
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

	/*以前的C语言中函数参数传递是值传递，
	如果有大块数据作为参数传递的时候，采用的方案往往是指针，
	因为 这样可以避免将整块数据全部压栈，可以提高程序的效率
	（C++中）又增加了一种同样有效率的选择（在某些特殊情况下又是必须的选择），就是引 用。
	*/
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
					*(arA + i) = *(arB + i); //通过指针赋值：1.取内容，2.赋值
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
		student s1, s2; //结构/类 的 声明式：只会分配内存，不会初始化字段值。
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
		s1 = s2; //结构 的 赋值：结构地址，字段地址都不变，内容改变。
		cout << space << "s1.id=" << s1.id << endl;
		cout << space << "s1.name=" << s1.name << endl;
		cout << space << "s1.age=" << s1.age << endl;
		cout << space << "s1.department=" << s1.department << endl;

		cout << endl;
	}

	//引用传递，传递的是整个数组
	void showLengthUseArrayReference(char(&arA)[20])
	{
		cout << space << sizeof(arA) << endl;
	}

	//值传递，传递的是数组的首字符
	void showLength(char arA[20])
	{
		cout << space << sizeof(arA) << endl;
	}

	void testArrayLength()
	{
		char arA[20] = { 0, 1, 2, 3, 4, 5 };
		cout << space << sizeof(arA) << endl;
		showLengthUseArrayReference(arA); //引用传递，传递的是整个数组
		showLength(arA);//值传递，传递的是数组的首字符

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
		student s1 = { 1, "eric", 18, "ComputerScience" }; //初始化 结构/类 的一种方式
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
		node temp; //这种方式，只分配内容
		node *pHead = new node(); //这种方式，分配内存+初始化字段值，指针为0
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

	void showLinkList(node pHead)
	{

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
				p = NULL;
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

	class MyClass
	{
		int data;
		node node;
		MyClass *next;
	};

	//结构/类 按照值传递：首地址会变，值类型字段地址会变，指针类型字段地址也会变，但是指针类型指向的对象不会变。
	void showMyClass(MyClass para)
	{

	}

	void testClass()
	{
		MyClass* my = new MyClass();
		showMyClass(*my);
	}

	void testLinkList()
	{
		MyClass my;
		cout << "node pHead = createLinkList(20);" << endl;
		node *pHead = createLinkList(20);
		node tempNode;
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
		int n = 10;
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
			cout << space << "Base::void func(char c)=" << c << endl;
		}
	protected:
		int n_Protected = 11;
		void func(bool b)
		{
			cout << space << "Base::void func(bool b)=" << b << endl;
		}
	private:
		int n_Private = 12;
		void func_Private(int n)
		{
			cout << space << "Base::void func(int n)=" << n << endl;
		}
	};

	class Derive :Base
	{
	public:
		/*
		成员函数func 和 字段n 在 Base 中为 public，但在 Derived 中为 private。
		为了使func和字段n在 Derived 中成为 public，可以在 Derived 的 public部分增加一个 using 声明。
		*/
		using Base::n;
		/*一个 using 声明只能指定一个名字，不能指定形参表，
		使用using声明将名字加入作用域之后，派生类只需要重定义本类型确实必须定义的那些函数，
		对其他版本可以使用继承的定义。
		对于Derive来说，public的方法包括:base中的func(char c),
		Derive中的func()和func(int m)*/
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

	/*
	继承时，指定基类的修饰符：可以为public,protected,private.
	公共继承：子类只能访问基类中的Public和Protected字段/方法，不能访问Private字段/方法。
	*/
	class Devive2 : public Base
	{
	public:
		void func2()
		{
			n_Protected = 30;
			//n_Private = 40; //不可访问
			//func_Private(1)//不可访问
		}
	};

	/*继承体系：基类中的字段和方法在子类中是private的。
	如果想改变访问限制可以在子类的修饰符后面使用Using 基类名::字段/方法名。*/
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
		cout << "b.func('char')" << endl;
		b.func('c');
		cout << "d.func();" << endl;
		d.func();
		cout << "d.func(2);" << endl;
		d.func(2);
		cout << "d.func('char')" << endl;
		d.func('c');
		cout << "d.n" << d.n << endl;
		Devive2 d2;
		cout << "d2.func" << endl;
		//d2.func(true);//不可访问
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
	为static，其在编译时刻被放入静态数据区。栈空间的对象是通过对象的显式声明分配的。堆中的对象则是通过new分配的。
	堆中的对象必须通过delete释放*/

	/* Allocated heap memory */
		{
			/*初始化对象，触发构造函数：先执行父类构造函数，再执行子类构造函数。*/
			myStudent *s1 = new myStudent(2);
			Undergraduate *s2 = new Undergraduate(1);
			Pupil *s3 = new Pupil(3);
			myStudent *pS = s2;
			pS->study();
			pS = s1;
			pS->study(1);
			pS = s3;
			pS->study();

			s1->study();
			s1->study(1);
			s2->study();
			s3->study();

			/*堆中的对象必须通过delete释放。
			删除指针，会触发析构函数；先析构子类，再析构父类。*/
			delete s1;
			delete s2;
			delete s3;
		}

		/*Allocated on the stack.*/
		{
			myStudent s1(1);
			Undergraduate s2(2);
			Pupil s3(3);
			int i = -1;
			{
				cout << "enter into brackets." << endl;
				cout << "create new obj." << endl;
				s1 = myStudent(4); //重新赋值，会触发析构函数：先析构子类，再析构父类。
				s2 = Undergraduate(5);
				s3 = Pupil(6);
				cout << "call virtual function." << endl;
				myStudent *pS = &s2;
				pS->study();
				pS = &s1;
				pS->study();
				pS = &s3;
				pS->study();
			}
			cout << "get out from brackets." << endl;
			cout << endl;
		}//右大括号会触发栈内对象的析构函数；先析构子类，再析构父类。
	}

	void testAnd()
	{
		int x = 55;
		cout << "int x = " << x << endl;
		int count = 0;
		/*
		x=0时跳出循环，x为负为正都会执行循环
		*/
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

	void Operator()
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
		//对象的指针可以移动，移动之后，运行时会尝试用类型来读取内存，虽然内存值已经不可控了。
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
		//++myInt4->value会先取value的值，再对value的值++
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "++myInt4->value=" << ++myInt4->value << " : myInt4=" << myInt4 << endl;
		cout << space << "myInt4=" << myInt4 << endl;
		//myInt4++->value会先对myInt4指针++，再取value的值，value会取到不可控的值
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

		/*funD是方法的指针：方法指针的值就是目标的地址；
		methodA是方法名称：方法名称是一个变量，它的值是自己的地址与“&方法名称”得到的值相同；*/
		func *funcD = methodA;
		cout << space << "funcD(4)=" << funcD(4) << endl;

		func *funcE = funcC;
		cout << space << "funcE(5)=" << funcE(5) << endl;

		/*funcD,funcE,funcF的值都是目标地址。说明指针和引用内存分配策略是一样的。*/
		func &funcF = funcC;
		cout << space << "fundF(6)=" << funcF(6) << endl;

		/*方法名称是一个特殊的变量，无论对他*或者&，之后付给指针或者别名，都能正确指向方法。*/
		func* funcG = &methodA;
		cout << space << "funcG(7)=" << funcG(7) << endl;

		func* funcH = *methodA;
		cout << space << "funcH(8)=" << funcH(8) << endl;
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

		printf("16.Test And &\n");
		testAnd();

		printf("17.last.Test cin \n");
		cin >> b;
		cout << "b=" << b << endl;
		cout << endl;

		system("pause");

	}

	void Type()
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

		printf("7.Test class \n");
		testClass();

		printf("8.Test link list \n");
		testLinkList();

		printf("9.Test header file and using\n");
		testHeaderFile_Using();

		printf("10.Test derive\n");
		testDestructor();

		printf("11.Test derive and using\n");
		testDerive_Using();

		printf("12.Test vector\n");
		testVector();

		system("pause");
	}

	/*类和方法*/
	void Class_Funtion()
	{
		printf("1.Test polymorphic and virtual function and assignment\n");
		testPolymorphic_VirtualFunction_Assignment();

		printf("2.Test sizeof\n");
		testReferenceAndPointer();

		printf("3.Test Reference Parameter and Pointer Parameter");
		testRefParaAndPointerPara();

		system("pause");
	}

	//new在堆上分配内存。非new在栈上分配内存。析构函数在大大括号结束时自动被调用。
	void NewAndPoint()
	{
		class Node
		{
			int val;
			Node* next;
		};

		class aaa
		{
			Node* a;
			Node b;
		public:
			aaa()
			{
				a = new Node();
				p = new char();
			}
			~aaa()
			{
				cout << "deconstructor" << endl;
				//用完指针之后，一定要将其删掉。
				delete a;
				//删除指针之后，一定要加上下面这句话，免得成为野指针
				a = NULL;

				delete a;//正常
				delete a;//正常

				delete p;//正常
				p = NULL;
			} //析构函数
			void disp()
			{
				cout << "disp" << endl;
			}
		private:
			char *p;
		};

		aaa a;
		a.~aaa();//显示调用析构函数（危险）
		a.disp();
	}//方法结束时，自动调用a的析构函数
}

