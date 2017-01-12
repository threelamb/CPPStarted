#pragma once;

#include "stdafx.h";
using namespace std;
class MyAlgorithm
{
	char space;

	class LinkList
	{
		char space;

		struct Node
		{
			int val;
			Node* next;
		};

		Node* createLinkList(int firstValue,int count)
		{
			Node *pFirstNode = NULL, *pLastNode = NULL, *pNode;
			int i = -1;
			while(++i < count)
			{		
				pNode = new Node();
				pNode->val = firstValue++;
				pNode->next = NULL;
				if(pFirstNode == NULL)
					pFirstNode = pNode;
				if(pLastNode == NULL)
					pLastNode = pNode;
				else
				{
					pLastNode->next = pNode;
					pLastNode = pNode;
				}
			}
			return pFirstNode;
		}

		Node* getNodePointer(Node* node, int index)
		{
			int i = -1;
			while(++i < index)
			{
				if(node->next == NULL)
					break;
				node = node->next;
			}
			return node;
		}

		void showLinkList(Node* node)
		{
			int i = -1;
			while(node != NULL)
			{
				cout<<space<<node->val;
				node = node->next;
			}
			cout<<endl;
		}

		void deleteLinkList(Node *node)
		{
			cout<<"Begin deleting linklist:"<<endl;
			while(node != NULL)
			{
				cout<<space<<node->val;
				Node *p = node;
				node = node->next;
				delete p;
			}
			cout<<endl<<"End deleting."<<endl;
		}

		Node* reverse(Node *pHead)
		{
			Node *pre = pHead, *cur = pHead->next;
			while(cur)
			{
				Node *temp = cur->next;
				cur->next = pre;
				pre = cur;
				cur = temp;
			}
			pHead->next = NULL;
			return pre;
		}

		Node* sort(Node *head)
		{
			Node *cur = head, *curPre = NULL, *newHead = NULL;
			Node *min = NULL, *minPre = NULL, *cur2 = NULL, *cur2Pre = NULL;
			while(cur)
			{
				min =cur;
				cur2 = cur->next;
				int getLess = 0;
				while(cur2)
				{
					if(cur2->val < min->val)
					{
						minPre=cur2Pre;
						min=cur2;
						getLess = 1;
					}
					cur2Pre = cur2;
					cur2 = cur2->next;
				}
				if(getLess)
				{
					Node *temp = cur->next;
					cur->next = min->next;
					if(minPre && minPre != cur) minPre->next = cur;
					if(min == temp) min->next = cur;
					else min->next = temp;
					if(curPre) curPre->next = min;
				}
				curPre = min;
				cur = min->next;
				cur2Pre = min;
				if(!newHead) newHead = min;
			}
			return newHead;
		}

		Node* createLinkListDescending(int index, int count)
		{
			Node *cur = NULL, *head = NULL, *last = NULL;
			while(count-- > 0)
			{
				Node *cur = new Node();
				cur->val = index--;
				cur->next = NULL;
				if(!head) head = cur;
				if(!last) last = cur;
				else
				{
					last->next = cur;
					last = cur;
				}
			}
			return head;
		}

		Node* mergeLinkList(Node *head1, Node *head2)
		{
			Node *head = NULL;
			Node *cur1 = head1;
			Node *cur2 = head2;
			Node *pre = NULL;
			while(cur1)
			{
				Node *temp1 = cur1->next;
				int merged = 0;
				while(cur2)
				{
					if(cur1->val < cur2->val)
					{
						Node *temp2 = cur1->next;
						if(pre) pre->next = cur1;
						else pre = cur1;
						cur1->next = cur2;
						cur1 = temp2;
						merged = 1;
						break;
					}
					else
					{
						pre = cur2;
						cur2 = cur2->next;
					}
				}
				if(!merged)
				{
					pre->next = cur1;
					break;
				}
				else
					cur1 = temp1;
			}
			head = head1->val < head2->val? head1 : head2;
			return head;
		}

		public: 
			LinkList()
			{
				space = ' ';
			}
		/* Given a single linked list L:(L0,L1,L2,...,Ln-1,Ln).Write a program to reorder it so that it becomes(L0,Ln,L1,Ln-1,L2,Ln-2,...)
		struct Node
		{
			int val_;
			Node* next;
		}
		Notes:
		1.Space Complexity should be O(1)
		2.Only the ".next" field of a node is modifiable.
		*/
		void testSorting_Head_Tail_Staggered()
		{
			int count = 10;
			Node* firstNode = createLinkList(1, count);
			cout<<"Before order:"<<endl;
			showLinkList(firstNode);

			Node *pFront=NULL, *pBack=NULL, *temp=NULL;
			pFront = getNodePointer(firstNode, 0);
			int i = -1;
			int top = -1;
			if(count%2)
				top = count/2+1;
			else
				top = count/2;
			while(++i < top)
			{
				if(pFront==pBack)
				{
					pBack->next = NULL;
					break;
				}
				pBack = getNodePointer(firstNode, count - 1);
				if(pFront==pBack)
				{
					pBack->next = NULL;
					break;
				}
				temp = pFront->next;
				if(temp == pBack)
				{
					pBack->next = NULL;
					break;
				}
				pFront->next = pBack;
				pBack->next = temp;

				pFront = temp;
			}

			cout<<"After order:"<<endl;
			showLinkList(firstNode);
			deleteLinkList(firstNode);

			cout<<endl;
		}

		/* Reverse LinkList.*/
		void testReverseLinkList()
		{
			Node *pFirstNode = createLinkList(1, 10);
			showLinkList(pFirstNode);
			pFirstNode = reverse(pFirstNode);
			showLinkList(pFirstNode);
			deleteLinkList(pFirstNode);
		
			cout<<endl;
		}

		/*Sort two LinkList ascending, then merge them ascending. */
		void testMergeLinkList()
		{
			cout<<"create LinkList1:"<<endl;
			Node *head1 = createLinkListDescending(15, 10);
			showLinkList(head1);
			cout<<"create LinkList2:"<<endl;
			Node *head2 = createLinkList(0, 10);
			showLinkList(head2);
			cout<<"sort LinkList1:"<<endl;
			head1 = sort(head1);
			showLinkList(head1);
			cout<<"sort LinkList2:"<<endl;
			head2 = sort(head2);
			showLinkList(head2);
			cout<<"merge LinkList1 and LinkList2."<<endl;
			Node *head3 = mergeLinkList(head1,head2);
			showLinkList(head3);

			cout<<endl;
		}
	};

	class Array
	{
		char space;
		void showArray(int a[], int length)
		{
			int i = -1;
			while(++i < length)
			{
				cout<<space<<*(a+i);
			}
			cout<<endl;
		}

		void bubbleSort(int a[], int length)
		{
			for(int i=0; i<length-1; i++)
			{
				for(int j=length-1; j>i; j--)
				{
					if(*(a+j) < *(a+j-1))
					{
						int small = *(a+j);
						*(a+j) = *(a+j-1);
						*(a+j-1) = small;
					}
				}
				showArray(a, length);
			}
		}

		void insertSort(int a[], int length)
		{
			for(int i=1; i<length; i++)
			{
				for(int j=i; j>0 && *(a+j)<*(a+j-1); j--)
				{
					int small = *(a+j);
					*(a+j) = *(a+j-1);
					*(a+j-1) = small;
				}
				showArray(a, length);
			}
		}

		void selectionSort(int a[], int length)
		{
			for(int i=0; i<length; i++)
			{
				int minIndex = i;
				for(int j = i+1; j < length; j++)
				{
					if(*(a+minIndex) > *(a+j))
						minIndex = j;
				}
				int min = *(a+minIndex);
				*(a+minIndex) = *(a+i);
				*(a+i) = min;
				showArray(a, length);
			}
		}

		void quickSort(int a[], int low, int high)
		{  
			if(low < high)
			{
				int i = low, j = high, base = *(a+low);
				while(i < j)
				{
					while(i < j && *(a+j) > base)
						j--;
					if(i < j)
					{
						*(a+i) = *(a+j);
						i++;
					}
					while(i < j && *(a+i) < base)
						i++;
					if(i < j)
					{
						*(a+j) = *(a+i);
						j--;
					}
					showArray(a, 10);
				}
				*(a+i) = base;
				quickSort(a, low, i-1);
				quickSort(a, i+1, high);
			}
		} 

		void mergeSort(int a[], int low, int high)
		{
			if(low < high)
			{
				int middle = low + high/2;
				mergeSort(a, low, middle);
				mergeSort(a, middle + 1, high);

				int arrFront[10];
				int arrEnd[10];
				int i = -1, j = middle-1, k = -1;
				while(++i < middle + 1)
				{
					arrFront[i] = a[i];
				}
				arrFront[middle] = 99999;
				i = -1;
				while(++j <= high)
				{
					++i;
					arrEnd[i] = a[j];		
				}
				arrEnd[high - middle] = 99999;
				i = 0, j = 0;
				while(++k <= high)
				{
					if(arrFront[i] < arrEnd[j])
						a[k] = arrFront[i++];
					else
						a[k] = arrEnd[j++];
				}
				showArray(a, 10);
			}
		}
		
	public:
		Array()
		{
			space = ' ';
		}

		void testBubbleSort()
		{
			int a[] = {20,19,18,10,11,12,13,9,8,0};
			bubbleSort(a, 10);
		}

		void testInsertSort()
		{
			int a[] = {20,19,18,10,11,12,13,9,8,0};
			insertSort(a, 10);
		}

		void testSelectionSort()
		{
			int a[] = {20,19,18,10,11,12,13,9,8,0};
			selectionSort(a, 10);
		}

		void testQuickSort()
		{
			int a[] = {15,19,18,10,11,12,13,9,8,0};
			showArray(a, 10);
			quickSort(a, 0, 9);
		}

		void testMergeSort()
		{
			int a[] = {15,19,18,10,11,12,13,9,8,0};
			showArray(a, 10);
			mergeSort(a, 0, 9);
		}
	};

	public:
		MyAlgorithm()
		{
			space = ' ';			
		}
	void a()
	{
		LinkList list;
		printf("1.Test sorting LinkList.\n");
		list.testSorting_Head_Tail_Staggered();

		printf("2.Test reverse LinkList.\n");
		list.testReverseLinkList();

		printf("3.Test merge LinkList.\n");
		list.testMergeLinkList();

		Array arr;
		printf("4.Test bubble sorting of array.\n");
		arr.testBubbleSort();

		printf("5.Test insert sorting of array.\n");
		arr.testInsertSort();

		printf("6.Test quick sorting of array.\n");
		arr.testQuickSort();

		printf("7.Test selection sorting of array.\n");
		arr.testSelectionSort();

		printf("8.Test merge sorting of array.\n");
		arr.testMergeSort();

		system("pause");
	}
};

