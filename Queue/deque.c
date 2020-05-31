/*
	Dequeue -double ended queue
		 implemented using link list
		1.elements can be inserted from front as well as rear
		2.elements can be deleted from front as well as rear



*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* front;
struct node* rear;


void enque_rear(int x);
void deque_front();
void enque_front(int x);
void deque_rear();
void show();


int main()
{
	front=NULL,rear=NULL;
	int choise=1,x;
	while(choise!=6)
	{
		printf("\n\n ---------------------------------------------------------\n");
		printf("\n		Dequeue Operations");
		printf("\n	1) Insert rear");
		printf("\n	2) Insert front");
		printf("\n	3) Delete rear");
		printf("\n	4) Delete front");
		printf("\n	5) Show");
		printf("\n	6) Exit");
		printf("\n     Enter your choise : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	Enter data to insert at rear: ");
				scanf("%d",&x);
				enque_rear(x);
				show();
				break;

			case 2: printf("\n	Enter data to insert at front: ");
				scanf("%d",&x);
				enque_front(x);
				show();
				break;

			case 3:	deque_rear();
				show();
				break;

			case 4:	deque_front();
				show();
				break;

			case 5: show();
				break;

			case 6: printf("\n\n	Thank you ! \n");
				break;
			default: printf("\n	Please enter vallide choise ..............");

		}
	}
}

void enque_rear(int x)
{
	struct node*p=(struct node*)malloc(sizeof(struct node));
	p->next=NULL;
	p->data=x;
	if(front==NULL && rear==NULL)
	{
		front=p;
		rear=p;
	}
	else
	{
		rear->next=p;
		rear=p;
	}
}
void enque_front(int x)
{
	struct node*p=(struct node*)malloc(sizeof(struct node));
	p->next=NULL;
	p->data=x;
	if(front==NULL && rear==NULL)
	{
		front=p;
		rear=p;
	}
	else
	{
		p->next=front;
		front=p;
	}
}

void deque_front()
{
	int x;
	if(front==NULL && rear==NULL)
	{
		printf("\n	Sorry cannot delete bcause queue is empty !");
		return;
	}
	else if(front==rear)
	{
		x=front->data;
		front=NULL;
		rear=NULL;
	}
	else
	{
		x=front->data;
		struct node*p=front;
		front=p->next;
		p->next=NULL;
		free(p);
	}
	printf("\n	%d is deleted from queue. ",x);

}
void deque_rear()
{
	int x;
	if(front==NULL && rear==NULL)
	{
		printf("\n	Sorry cannot delete bcause queue is empty !");
		return;
	}
	else if(front==rear)
	{
		x=rear->data;
		front=NULL;
		rear=NULL;
	}
	else
	{
		x=rear->data;
		struct node*p=front;
		struct node*q;
		while(p->next!=rear)
		{
			p=p->next;
		}
		q=p->next;
		p->next=NULL;
		rear=p;
		free(q);
	}
	printf("\n	%d is deleted from queue. ",x);
}
void show()
{
	struct node* p=front;
	if(p==NULL)
	{
		printf("\n	Sorry , queue is empty !!!");
		return;
	}
	while(p!=NULL)
	{
		printf("  %d ->",p->data);
		p=p->next;
	}
}

/* Output

(base) mansi@mansi-Vostro-15-3568:~$ gcc deque.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out


 ---------------------------------------------------------

		Link List Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 1

	Enter data to insert at rear: 10
  10 ->

 ---------------------------------------------------------

		Dequeue Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 2

	Enter data to insert at front: 30
  30 ->  10 ->

 ---------------------------------------------------------

		Dequeue Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 1

	Enter data to insert at rear: 40
  30 ->  10 ->  40 ->

 ---------------------------------------------------------

		Dequeue Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 2

	Enter data to insert at front: 90
  90 ->  30 ->  10 ->  40 ->

 ---------------------------------------------------------

		Dequeue Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 1

	Enter data to insert at rear: 50
  90 ->  30 ->  10 ->  40 ->  50 ->

 ---------------------------------------------------------

		Dequeue Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 3

	50 is deleted from queue.   90 ->  30 ->  10 ->  40 ->

 ---------------------------------------------------------

		Dequeue Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 4

	90 is deleted from queue.   30 ->  10 ->  40 ->

 ---------------------------------------------------------

		Dequeue Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 5
  30 ->  10 ->  40 ->

 ---------------------------------------------------------

		Dequeue`	u1 Operations
	1) Insert rear
	2) Insert front
	3) Delete rear
	4) Delete front
	5) Show
	6) Exit
     Enter your choise : 6


	Thank you ! 
(base) mansi@mansi-Vostro-15-3568:~$ 


*/
 
