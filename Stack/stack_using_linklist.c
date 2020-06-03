#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* top;

void push(int x)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=x;
	p->next=NULL;

	if(top==NULL)
	{
		top=p;
	}
	else
	{
		p->next=top;
		top=p;
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("\n Sorry stack empty !");
	}
	else
	{
		int x=top->data;
		struct Node* p=top;
		top=p->next;
		free(p);
		printf("\n Poped item : %d",x);
	}
}

void show()
{
	if(top==NULL)
	{
		printf("\n Sorry stack empty !");
	}
	else
	{
		struct Node*p=top;
		while(p!=NULL)
		{
			printf("\n	| %d |",p->data);
			p=p->next;
		}
		printf("\n	|----|");
	}
}
void top_element()
{
	if(top==NULL)
	{
		printf("\n Sorry stack empty !");
	}
	else
	{
		int x=top->data;
		printf("\n Top of stack is : %d",x);
	}
}

int main()
{
	top=NULL;
	int choise,x;
	while(choise!=5)
	{
		printf("\n---------------------------------------------------------------");
		printf("\n 		Stack implementation using link list");
		printf("\n 	1) Push");
		printf("\n 	2) Pop");
		printf("\n 	3) Traverse");
		printf("\n 	4) Top");
		printf("\n 	5) Exit");
		printf("\n 	Enter your choise : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1:printf("\n Enter data : ");
			       scanf("%d",&x);
			       push(x);
			       break;

			case 2:pop();
			       break;

			case 3:show();
			       break;

			case 4:top_element();
			       break;

			case 5:printf("\n 	Thank you !\n");
			       break;

			default:printf("\n Please enter vallide choise !");
			       
		}
	}		
	return 0;
}
/*
	output-

(base) mansi@mansi-Vostro-15-3568:~$ gcc stack_using_linklist.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out

---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 1

 Enter data : 10

---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 1

 Enter data : 20

---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 1

 Enter data : 30

---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 1

 Enter data : 40

---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 3

	| 40 |
	| 30 |
	| 20 |
	| 10 |
	|----|
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 2

 Poped item : 40
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 3

	| 30 |
	| 20 |
	| 10 |
	|----|
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 4

 Top of stack is : 30
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 3

	| 30 |
	| 20 |
	| 10 |
	|----|
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 2

 Poped item : 30
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 2

 Poped item : 20
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 2

 Poped item : 10
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 2

 Sorry stack empty !
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 3

 Sorry stack empty !
---------------------------------------------------------------
 		Stack implementation using link list
 	1) Push
 	2) Pop
 	3) Traverse
 	4) Top
 	5) Exit
 	Enter your choise : 5

 	Thank you !
(base) mansi@mansi-Vostro-15-3568:~$ 

*/
