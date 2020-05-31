/*
	Queue -
		1.first in first out stucture
		2.elements inserted from front and deleted from rear
		3.here implemented using array

		added from rear and deleted from front

*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int front=-1,rear=-1;
void enque(int[],int);
void deque(int[]);
void peek(int[]);
void show(int[]);
int isEmpty(int[]);
int isFull(int[]);


void main()
{

	int queue[MAX];
	int choise=1;

	while(choise!=5)
	{
		printf("\n-------------------------------------------------");
		printf("\n		Queue Operations");
		printf("\n   Select operation you want to perform ");
		printf("\n  1. Enqueue ");
		printf("\n  2. Dequeue ");
		printf("\n  3. Peek element");
		printf("\n  4. Show queue ");
		printf("\n  5. Exit ");
		printf("\n   Enter your choise :");

		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	 Enter element to insert : ");
				int x;
				scanf("%d",&x);
				enque(queue,x);
				break;
			case 2: deque(queue);
				break;
			case 3: peek(queue);
				break;
			case 4: show(queue);
			case 5: break;
			default: printf("	Please enter vallide choise.....");
		}
	}

}

int isEmpty(int queue[])
{
	if(front==-1 && rear==-1)
		return 1;
	else
		return 0;

}

int isFull(int queue[])
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;

}

void enque(int queue[],int x)
{
	if(isFull(queue))
	{
		printf("\n	Sorry queue is full, Cannot insert !");
		return;
	}
	else if(isEmpty(queue))
	{
		front++;
		rear++;
		queue[rear]=x;
	}
	else
	{
		queue[++rear]=x;
	}
	printf("\n	%d is inserted ",x);

}
void deque(int queue[])
{
	int x;
	if(isEmpty(queue))
	{
		printf("\n	Sorry queue is empty, Cannot delete !");
		return;
	}
	else if(front==rear)
	{
		x=queue[front];
		front=-1;
		rear=-1;
	}
	else
	{
		x=queue[front++];
	}
	printf("\n	%d is deleted ",x);

}
void peek(int queue[])//gives element at the front of queue without removing it
{
	int x;
	if(isEmpty(queue))
	{
		printf("\n	Sorry queue is empty !");
	}
	else
	{
		x=queue[front];
		printf("\n	%d  is peek element of the queue ",x);
	}

}
void show(int queue[])
{
	printf("\n	 ");
	for(int i=front;i<=rear;i++)
	{
		printf("| %d |",queue[i]);
	}
}


/*   Output


(base) mansi@mansi-Vostro-15-3568:~$ gcc queue.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out

-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 11

	11 is inserted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 22

	22 is inserted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 33

	33 is inserted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :1

	 Enter element to insert : 44

	44 is inserted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :4

	 | 11 || 22 || 33 || 44 |
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :3

	11  is peek element of the queue 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :2

	11 is deleted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :4

	 | 22 || 33 || 44 |
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :3

	22  is peek element of the queue 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :2

	22 is deleted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :2

	33 is deleted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :4

	 | 44 |
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :2

	44 is deleted 
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :2

	Sorry queue is empty, Cannot delete !
-------------------------------------------------
		Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Peek element
  4. Show queue 
  5. Exit 
   Enter your choise :5
(base) mansi@mansi-Vostro-15-3568:~$ 
*/
