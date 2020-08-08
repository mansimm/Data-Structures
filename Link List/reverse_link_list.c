#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* head;

void insert(int x);
void show();
void reverse();
int main()
{
	int choise=1,x;
	while(choise!=4)
	{
		printf("\n\n ---------------------------------------------------------\n");
		printf("\n		Link List Operations");
		printf("\n	1) Insert");
		printf("\n	2) Show");
		printf("\n	3) Reverse");
		printf("\n	4) Exit");
		printf("\n     Enter your choise : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	Enter data : ");
				scanf("%d",&x);
				insert(x);
				break;

			case 2: show();
				break;

			case 3:	reverse();
				printf("Reverse link list :");
				show();
				break;

			case 4: printf("\n\n	Thank you ! \n");
				break;
			default: printf("\n	Please enter vallide choise ..............");

		}
	}




}
void reverse()
{
	struct node* current_head;
	struct node* p = head;
	current_head = NULL;
	while(p!=NULL)
	{
		head = p->next;
		p->next = current_head;
		current_head = p;
		p=head;
	}
	head = current_head;
}

void insert(int x)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;

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
	Output -

(base) mansi@mansi-Vostro-15-3568:~$ gcc reverse_link_list.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 1

	Enter data : 10


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 1

	Enter data : 20


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 1

	Enter data : 30


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 1

	Enter data : 40


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 1

	Enter data : 50


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 2
  10 ->  20 ->  30 ->  40 ->  50 ->

 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 3
Reverse link list :  50 ->  40 ->  30 ->  20 ->  10 ->

 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Show
	3) Reverse
	4) Exit
     Enter your choise : 4


	Thank you ! 
(base) mansi@mansi-Vostro-15-3568:~$ 


*/
