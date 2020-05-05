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
void insert_pos(int x,int pos);
void delete_first();
void delete_last();
void delete_pos(int x);
void show();
void search(int x);
void sorting();


int main()
{
	int choise=1,x,y;
	while(choise!=10)
	{
		printf("\n\n ---------------------------------------------------------\n");
		printf("\n		Doubly Link List Operations");
		printf("\n	1) Insert at start");
		printf("\n	2) Insert at last");
		printf("\n	3) Insert at position (pos>0)");
		printf("\n	4) Delete first element");
		printf("\n	5) Delete last element");
		printf("\n	6) Delete element at specific position");
		printf("\n	7) Show");
		printf("\n	8) Search");
		printf("\n	9) Sorting");
		printf("\n	10) Exit");
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

			case 3: printf("\n	Enter data : ");
				scanf("%d",&x);
				printf("\n	Enter position : ");
				scanf("%d",&y);
				insert_pos(x,y);
				break;

			case 4: delete_first();
				break;

			case 5: delete_last();
				break;

			case 6: printf("\n	Enter position from which you want to delete : ");
				scanf("%d",&x);
				delete_pos(x);
				break;

			case 7: show();
				break;

			case 8: printf("\n	Enter the data to search : ");
				scanf("%d",&x);
				search(x);
				break;

			case 9: sorting();
				printf("\n	Sorted link list is : ");
				show();
				break;

			case 10: printf("\n\n	Thank you ! \n");
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

void insert_pos(int x,int y)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	p->prev=NULL;
	int i=1;
	
	if(head==NULL && y!=1)//if link list is empty
	{
		insert_first(x);
		printf("\n	Sorry link list is empty ! %d inserted at first position.",x);
		return;
	}
	else if(y==1)
	{
		insert_first(x);
	}
	else//if link list is not empty
	{
		struct node* q;
		q=head;
		while(q->next!=NULL && i!=y-1)
		{
			q=q->next;
			i++;
		}
		if(q->next!=NULL && i==y-1)
		{
			p->next=q->next;
			q->next->prev=p;
			q->next=p;
			p->prev=q;
		}
		else if(q->next==NULL && i==y-1)
		{
			insert_last(x);	
		}		
		else
		{
			insert_last(x);
			printf("\n	Sorry link list is not that long ! %d inserted at last position.",x);
			return;
		}
	}
}

void delete_first()//delete head 
{
	int x;
	if(head==NULL)//if link list is empty
	{
		printf("\n	Sorry link list is empty !....cannot delete");
		return;
	}
	else if(head->next==NULL)//if head is only one node in link list
	{
		struct node *p=head;
		x=p->data;
		head=NULL;
		free(p);
		printf("	%d is deleted from link list , now link list is empty...",x);	
	}
	else
	{
		struct node *p=head->next;
		struct node *r=head;
		x=head->data;
		p->prev=NULL;
		head->next=NULL;
		head=p;
		free(r);	
		printf("	%d is deleted from link list .",x);	
	}		
}
void delete_last()
{
	int x;
	if(head==NULL)//if link list is empty
	{
		printf("\n	Sorry link list is empty !....cannot delete");
		return;
	}
	else if(head->next==NULL)//if head is the only node in link list
	{
		struct node *p=head;
		head=NULL;
		free(p);
		printf("	%d is deleted from link list , now link list is empty...",x);	
	}
	else
	{
		struct node *p=head;
		struct node *r;
		while(p->next->next!=NULL)
		{
			p=p->next;
		}
		r=p->next;
		x=r->data;
		r->prev=NULL;
		p->next=NULL;
		free(r);	
		printf("	%d is deleted from link list .",x);	
	}			
}

void delete_pos(int loc)
{
	int flag=0;
	int x,i=1;
	if(head==NULL)//if link list is empty
	{
		printf("\n	Sorry link list is empty !....cannot delete");
		return;
	}
	else if(head->next==NULL && loc>1)//if head node to be deleted
	{
		printf("\n	Sorry link list is not that long...");
		return;		
	}
	else if(loc==1)//if head node to be deleted
	{
		delete_first();
		return;		
	}		
	else
	{
		struct node* q;
		struct node* p;
		q=head;
		while(q->next!=NULL && i!=loc-1)
		{
			q=q->next;
			i++;
		}
		if(q->next!=NULL && i==loc-1)
		{
			p=q->next;//p is node which is to be deleted
			q->next=p->next;
			x=p->data;
			if(p->next!=NULL)
			{
				p->next->prev=q;
			}
			p->next=NULL;
			free(p);
			printf("	%d is deleted from link list .",x);
		}
		else if(q->next==NULL && (i!=loc-1 || i==loc-1))
		{
			printf("	Sorry link list is not that long...cannot delete");
		}

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

(base) mansi@mansi-Vostro-15-3568:~$ gcc doubly_link_list.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 1

	Enter data : 10


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 1

	Enter data : 20


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 2

	Enter data : 30


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 7
  20 ->  10 ->  30 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 3

	Enter data : 40

	Enter position : 3


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 7
  20 ->  10 ->  40 ->  30 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 4
	20 is deleted from link list .

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 5
	30 is deleted from link list .

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 7
  10 ->  40 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 2

	Enter data : 22


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 2

	Enter data : 33


 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 7
  10 ->  40 ->  22 ->  33 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 6

	Enter position from which you want to delete : 3
	22 is deleted from link list .

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 7
  10 ->  40 ->  33 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 8

	Enter the data to search : 40

	Element is found at location : 2

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 8

	Enter the data to search : 99
	Sorry , 99 is not present in link list !

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 7
  10 ->  40 ->  33 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 9

	Sorted link list is :   10 ->  33 ->  40 ->

 ---------------------------------------------------------

		Doubly Link List Operations
	1) Insert at start
	2) Insert at last
	3) Insert at position (pos>0)
	4) Delete first element
	5) Delete last element
	6) Delete element at specific position
	7) Show
	8) Search
	9) Sorting
	10) Exit
     Enter your choise : 10


	Thank you ! 
(base) mansi@mansi-Vostro-15-3568:~$ 





*/

