#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int top=-1;
void push(int[],int);
void pop(int[]);
void topElement(int[]);
void show(int[]);
int isEmpty(int[]);
int isFull(int[]);


void main()
{

	int stack[MAX];
	int choise=1;

	while(choise!=5)
	{
		printf("\n-------------------------------------------------");
		printf("\n		Stack Operations");
		printf("\n   Select operation you want to perform ");
		printf("\n  1. Push ");
		printf("\n  2. Pop ");
		printf("\n  3. Top ");
		printf("\n  4. Show ");
		printf("\n  5. Exit ");
		printf("\n   Enter your choise :");

		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	 Enter element to insert : ");
				int x;
				scanf("%d",&x);
				push(stack,x);
				break;
			case 2: pop(stack);
				break;
			case 3: topElement(stack);
				break;
			case 4: show(stack);
			case 5: break;
			default: printf("	Please enter vallide choise.....");
		}
	}

}

int isEmpty(int stk[])
{
	if(top==-1)
		return 1;
	else
		return 0;

}

int isFull(int stk[])
{
	if(top==MAX-1)
		return 1;
	else
		return 0;

}

void push(int stk[],int x)
{
	if(isFull(stk))
	{
		printf("\n	Sorry stack is full, Cannot insert !");
	}
	else
	{
		stk[++top]=x;
		printf("\n	%d id inserted ",x);
	}

}
void pop(int stk[])
{
	int x;
	if(isEmpty(stk))
	{
		printf("\n	Sorry stack is empty, Cannot pop !");
	}
	else
	{
		x=stk[top--];
		printf("\n	%d is deleted ",x);
	}

}
void topElement(int stk[])
{
	int x;
	if(isEmpty(stk))
	{
		printf("\n	Sorry stack is empty !");
	}
	else
	{
		x=stk[top];
		printf("\n	%d is top element of the stack",x);
	}

}
void show(int stk[])
{
	int x=top;
	printf("\n");
	while(x>=0)
	{
		printf("\n	| %d |",stk[x--]);
	}
		printf("\n	|____|");
	printf("\n");

}

/* OUTPUT


(base) mansi@mansi-Vostro-15-3568:~$ gcc stack.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out

-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 22

	22 id inserted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 55

	55 id inserted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 99

	99 id inserted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 29

	29 id inserted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 90

	90 id inserted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :4


	| 90 |
	| 29 |
	| 99 |
	| 55 |
	| 22 |
	|____|
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :3

	90 is top element of the stack 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :2

	90 is deleted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :4


	| 29 |
	| 99 |
	| 55 |
	| 22 |
	|____|
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :2

	29 is deleted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :4


	| 99 |
	| 55 |
	| 22 |
	|____|
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :2

	99 is deleted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :2

	55 is deleted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :4


	| 22 |
	|____|
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :2

	22 is deleted 
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :2

	Sorry stack is empty, Cannot pop !
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :4


	|____|
-------------------------------------------------
		Stack Operations
   Select operation you want to perform 
  1. Push 
  2. Pop 
  3. Top 
  4. Show 
  5. Exit 
   Enter your choise :5
(base) mansi@mansi-Vostro-15-3568:~$ 
*/
