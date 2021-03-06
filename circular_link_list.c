#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* head;

void insert_first(int x);
void insert_last(int x);
void delete_first();
void delete_last();
void show();
void search(int x);

int main()
{
	int choise=1,x;
	while(choise!=7)
	{
		printf("\n\n ---------------------------------------------------------\n");
		printf("\n		Circular Link List Operations");
		printf("\n	1) Insert at first");
		printf("\n	2) Insert at last");
		printf("\n	3) Delete from first");
		printf("\n	4) Delete from last");
		printf("\n	5) Show");
		printf("\n	6) Search");
		printf("\n	7) Exit");
		printf("\n     Enter your choise : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	Enter data to insert at first : ");
				scanf("%d",&x);
				insert_first(x);
				break;

			case 2: printf("\n	Enter data to insert at last: ");
				scanf("%d",&x);
				insert_last(x);
				break;

			case 3: delete_first();
				break;

			case 4: delete_last();
				break;

			case 5: show();
				break;

			case 6: printf("\n	Enter the data to search : ");
				scanf("%d",&x);
				search(x);
				break;

			case 7: printf("\n\n	Thank you ! \n");
				break;
			default: printf("\n	Please enter vallide choise ..............");

		}
	}
}


void insert_first(int x)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;

	if(head==NULL)//if link list is empty
	{
		head=p;
		head->next=head;
	}
	else//if link list is not empty
	{
		struct node* q;
		q=head;
		while(q->next!=head)
		{
			q=q->next;
		}
		q->next=p;
		p->next=head;
		head=p;
	}
	printf("\n	%d is inserted at first",x);
}

void insert_last(int x)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;

	if(head==NULL)//if link list is empty
	{
		head=p;
		head->next=head;
	}
	else//if link list is not empty
	{
		struct node* q;
		q=head;
		while(q->next!=head)
		{
			q=q->next;
		}
		q->next=p;
		p->next=head;
	}
	printf("\n	%d is inserted at last",x);
}

void delete_first()
{
	int flag=0,x;

	if(head==NULL)//if link list is empty
	{
		printf("\n	Sorry link list is empty !");
		return;
	}
	else if(head->next==head)//if head node to be deleted
	{
		struct node* p;
		p=head;
		x=p->data;
		head=NULL;
		free(p);
	}		
	else
	{
		struct node* q;
		struct node* p;
		q=head;
		while(q->next!=head)
		{
			q=q->next;
		}
		q->next=head->next;
		p=head;
		x=p->data;
		head=p->next;
		p->next=NULL;
		free(p);
		
	}

	printf("	%d is deleted from link list .",x);

}

void delete_last()
{
	int flag=0;
	int x;

	if(head==NULL)//if link list is empty
	{
		printf("\n	Sorry link list is empty !");
		return;
	}
	else if(head->next==head)//if head node to be deleted
	{
		struct node* p;
		p=head;
		x=p->data;
		head=NULL;
		free(p);
	}		
	else
	{
		struct node* q;
		struct node* p;
		p=head;
		while(p->next->next!=head)
		{
			p=p->next;
		}
		q=p->next;
		p->next=head;
		x=q->data;
		q->next=NULL;
		free(q);
		
	}

	printf("	%d is deleted from link list .",x);

}

void show()
{
	struct node* p=head;
	if(head==NULL)
	{
		printf("\n	Sorry , link list is empty !!!");
		return;
	}
	while(p->next!=head)
	{
		printf("  %d ->",p->data);
		p=p->next;
	}
	printf("  %d ->",p->data);
}

void search(int x)
{
	struct node* p=head;
	int i=0,flag=0;
	if(head==NULL)
	{
		printf("\n	Sorry , link list is empty !!!");
		return;
	}
	while(p->next!=head)
	{
		i++;
		if(p->data==x)
		{
			printf("\n	Element is found at location : %d",i);
			flag=1;
			break;
		}
		p=p->next;
	}
	if(p->data==x && flag==0)
	{
		i++;
		printf("\n	Element is found at location : %d",i);
		flag=1;
	}
	if(flag==0)
	{
		printf("	Sorry , %d is not present in link list !",x);
	}
}

/*   OUTPUT 
	
(base) mansi@mansi-Vostro-15-3568:~$ gcc circular_link_list.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out


 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 1

	Enter data to insert at first : 10

	10 is inserted at first

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 1

	Enter data to insert at first : 20

	20 is inserted at first

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 2

	Enter data to insert at last: 30

	30 is inserted at last

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 2

	Enter data to insert at last: 40

	40 is inserted at last

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 5
  20 ->  10 ->  30 ->  40 ->

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 3
	20 is deleted from link list .

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 4
	40 is deleted from link list .

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 5
  10 ->  30 ->

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 6

	Enter the data to search : 10

	Element is found at location : 1

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 6

	Enter the data to search : 30

	Element is found at location : 2

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 6

	Enter the data to search : 99
	Sorry , 99 is not present in link list !

 ---------------------------------------------------------

		Circular Link List Operations
	1) Insert at first
	2) Insert at last
	3) Delete from first
	4) Delete from last
	5) Show
	6) Search
	7) Exit
     Enter your choise : 7


	Thank you ! 
(base) mansi@mansi-Vostro-15-3568:~$ 






*/

