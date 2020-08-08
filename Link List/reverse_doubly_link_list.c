#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* head;

void insert_first(int x);
void insert_last(int x);
void show();
void reverse();

int main()
{
	int choise=1,x,y;
	while(choise!=5)
	{
		printf("\n\n ---------------------------------------------------------\n");
		printf("\n		Doubly Link List Operations");
		printf("\n	1) Insert at start");
		printf("\n	2) Insert at last");
		printf("\n	3) Reverse");
		printf("\n	4) Show");
		printf("\n	5) Exit");
		printf("\n     Enter your choise : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	Enter data : ");
				scanf("%d",&x);
				insert_first(x);
				break;

			case 2: printf("\n	Enter data : ");
				scanf("%d",&x);
				insert_last(x);
				break;

			case 3: reverse();
				printf("\n Reverse link list is :");
				show();
				break;

			case 4: show();
				break;

			case 5: printf("\n\n	Thank you ! \n");
				break;

			default: printf("\n	Please enter vallide choise ..............");

		}
	}




}
void reverse()
{
	struct node * p = head;
	struct node * temp = NULL;
	while(p!=NULL)
	{
		temp = p->prev;
		p->prev = p->next;
		p->next = temp;

		p=p->prev;
	}

	if(temp != NULL) 
	{
            head = temp->prev;
	} 

}

void insert_first(int x)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	p->prev=NULL;

	if(head==NULL)//if link list is empty
	{
		head=p;
	}
	else//if link list is not empty
	{
		p->next=head;
		head->prev=p;
		head=p;
	}
}

void insert_last(int x)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	p->prev=NULL;

	if(head==NULL)//if link list is empty
	{
		head=p;
	}
	else//if link list is not empty
	{
		struct node* q;
		q=head;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->prev=q;
	}
}



void show()
{
	struct node* p=head;
	if(head==NULL)
	{
		printf("\n	Sorry , link list is empty !!!");
		return;
	}
	while(p!=NULL)
	{
		printf("  %d ->",p->data);
		p=p->next;
	}
}

/*
	Output-

(base) mansi@mansi-Vostro-15-3568:~$ gcc reverse_doubly_link_list.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 1

	Enter data : 11


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 1

	Enter data : 22


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 1

	Enter data : 33


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 2

	Enter data : 44


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 2

	Enter data : 55


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 4
  33 ->  22 ->  11 ->  44 ->  55 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 3

 Reverse link list is :  55 ->  44 ->  11 ->  22 ->  33 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Reverse
	4) Show
	5) Exit
     Enter your choise : 5


	Thank you ! 
(base) mansi@mansi-Vostro-15-3568:~$ 

*/
