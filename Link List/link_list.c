#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* head;

void insert(int x);
void delete(int x);
void show();
void search(int x);
void sorting();
int main()
{
	int choise=1,x;
	while(choise!=6)
	{
		printf("\n\n ---------------------------------------------------------\n");
		printf("\n		Link List Operations");
		printf("\n	1) Insert");
		printf("\n	2) Delete");
		printf("\n	3) Show");
		printf("\n	4) Search");
		printf("\n	5) Sorting");
		printf("\n	6) Exit");
		printf("\n     Enter your choise : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	Enter data : ");
				scanf("%d",&x);
				insert(x);
				break;

			case 2: printf("\n	Enter data which you want to delete : ");
				scanf("%d",&x);
				delete(x);
				break;

			case 3: show();
				break;

			case 4: printf("\n	Enter the data to search : ");
				scanf("%d",&x);
				search(x);
				break;

			case 5: sorting();
				printf("\n	Sorted link list is : ");
				show();
				break;

			case 6: printf("\n\n	Thank you ! \n");
				break;
			default: printf("\n	Please enter vallide choise ..............");

		}
	}




}
void sorting()
{
	struct node*p;
	struct node*q;

	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(q->data<p->data)
			{
				int temp;
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}

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

void delete(int x)
{
	int flag=0;

	if(head==NULL)//if link list is empty
	{
		printf("\n	Sorry link list is empty !");
		return;
	}
	else if(head->data==x)//if head node to be deleted
	{
		struct node* p;
		p=head;
		head=p->next;
		p->next=NULL;
		free(p);
		flag=1;
	}		
	else
	{
		struct node* q;
		struct node* p;
		q=head;
		while(q->next!=NULL && q->next->data!=x)
		{
			q=q->next;
		}
		if(q->next!=NULL)
		{
			p=q->next;//p is node which is to be deleted
			q->next=p->next;
			p->next=NULL;
			free(p);
			flag=1;
		}
	}

	if(flag==1)
	{
		printf("	%d is deleted from link list .",x);
	}
	else
	{
		printf("	Sorry %d is not present in link list !!!",x);
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

void search(int x)
{
	struct node* p=head;
	int i=0,flag=0;
	while(p!=NULL)
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
	if(flag==0)
	{
		printf("	Sorry , %d is not present in link list !",x);
	}
}

/*   OUTPUT of sorting operation
(base) mansi@mansi-Vostro-15-3568:~$ gcc link_list.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 1

	Enter data : 11


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 1

	Enter data : 99


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 1

	Enter data : 44


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 1

	Enter data : 88


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 1

	Enter data : 22


 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 3
  11 ->  99 ->  44 ->  88 ->  22 ->

 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 5

	Sorted link list is :   11 ->  22 ->  44 ->  88 ->  99 ->

 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 3
  11 ->  22 ->  44 ->  88 ->  99 ->

 ---------------------------------------------------------

		Link List Operations
	1) Insert
	2) Delete
	3) Show
	4) Search
	5) Sorting
	6) Exit
     Enter your choise : 6


	Thank you ! 
(base) mansi@mansi-Vostro-15-3568:~$ 





*/

