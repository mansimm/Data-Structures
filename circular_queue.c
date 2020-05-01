/*
	Circular  Queue -
			Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) 				principle and the last position is connected back to the first position to make a circle. It is also called ‘Ring 				Buffer’.
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 7
int front=-1,rear=-1;
void enque(int[],int);
void deque(int[]);
void front_element(int[]);
void rear_element(int[]);
void show(int[]);
int isEmpty(int[]);
int isFull(int[]);


void main()
{

	int queue[MAX];
	int choise=1;

	while(choise!=6)
	{
		printf("\n-------------------------------------------------");
		printf("\n		Circular Queue Operations");
		printf("\n   Select operation you want to perform ");
		printf("\n  1. Enqueue ");
		printf("\n  2. Dequeue ");
		printf("\n  3. Front element");
		printf("\n  4. Rear element");
		printf("\n  5. Show queue ");
		printf("\n  6. Exit ");
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
			case 3: front_element(queue);
				break;
			case 4: rear_element(queue);
				break;
			case 5: show(queue);
			case 6: break;
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
	if((rear+1)%MAX==front)//wraparound effect
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
		rear=(rear+1)%MAX;
		queue[rear]=x;
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
		x=queue[front];
		front=(front+1)%MAX;
	}
	printf("\n	%d is deleted ",x);

}
void front_element(int queue[])//gives element at the front of queue without removing it
{
	int x;
	if(isEmpty(queue))
	{
		printf("\n	Sorry queue is empty !");
	}
	else
	{
		x=queue[front];
		printf("\n	%d  is front element of the queue ",x);
	}

}
void rear_element(int queue[])//gives element at the front of queue without removing it
{
	int x;
	if(isEmpty(queue))
	{
		printf("\n	Sorry queue is empty !");
	}
	else
	{
		x=queue[rear];
		printf("\n	%d  is rear element of the queue ",x);
	}

}
void show(int queue[])
{
	printf("\n	 ");
	if(!isEmpty(queue))
	{
		int i=front;
		do
		{
			printf("| %d |",queue[i]);
			i=(i+1)%MAX;
		}while(i!=(rear+1)%MAX);
	}
	else
		printf("\n	Sorry , queue is empty........");
}


/*   Output

(base) mansi@mansi-Vostro-15-3568:~$ gcc circular_queue.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out

-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 11

	11 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 12

	12 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 13

	13 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 14

	14 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 15

	15 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 16

	16 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 17

	17 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 18

	Sorry queue is full, Cannot insert !
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :5

	 | 11 || 12 || 13 || 14 || 15 || 16 || 17 |
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :3

	11  is front element of the queue 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :4

	17  is rear element of the queue 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :2

	11 is deleted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :2

	12 is deleted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :5

	 | 13 || 14 || 15 || 16 || 17 |
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 91

	91 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :5

	 | 13 || 14 || 15 || 16 || 17 || 91 |
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :1

	 Enter element to insert : 92

	92 is inserted 
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :5

	 | 13 || 14 || 15 || 16 || 17 || 91 || 92 |
-------------------------------------------------
		Circular Queue Operations
   Select operation you want to perform 
  1. Enqueue 
  2. Dequeue 
  3. Front element
  4. Rear element
  5. Show queue 
  6. Exit 
   Enter your choise :6
(base) mansi@mansi-Vostro-15-3568:~$ 

*/
