#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root;

void insert(int x);
void postorder(struct node * p);
void preorder(struct node * p);
void inorder(struct node * p);
int search(int x);
void delete(struct node *,int x,struct node*);
int find_min(struct node* p);

int main()
{
	int choise=1,x;
	while(choise!=7)
	{
		printf("\n\n ---------------------------------------------------------\n");
		printf("\n		Binary Search Tree Operations");
		printf("\n	1) Insert ");
		printf("\n	2) Delete");
		printf("\n	3) Search");
		printf("\n	4) Inorder Traversal");
		printf("\n	5) Preorder Traversal");
		printf("\n	6) Postorder Traversal");
		printf("\n	7) Exit");
		printf("\n     Enter your choise : ");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1: printf("\n	Enter data to insert : ");
				scanf("%d",&x);
				insert(x);
				break;

			case 2: printf("\n	Enter data to delete : ");
				scanf("%d",&x);
				delete(root,x,NULL);
				break;

			case 3: printf("\n	Enter data to search : ");
				scanf("%d",&x);
				int y=search(x);
				if(y==0)
				printf("\n	Sorry ...%d not present in BST ",x);
				else	
				printf("\n	%d present in BST ",x);
				break;

			case 4: printf("\n	Inorder Traversal : ");
				printf("\n	");
				inorder(root);//4) Inorder Traversal
				break;

			case 5: printf("\n	Preorder Traversal : ");
				printf("\n	");
				preorder(root);//5) Preorder Traversal
				break;

			case 6:	printf("\n	Postorder Traversal : ");
				printf("\n	");
				postorder(root);//6) Postorder Traversal
				break;

			case 7: printf("\n\n	Thank you ! \n");
				break;
			default: printf("\n	Please enter vallide choise ..............");

		}
	}

}

void insert(int x)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->left=NULL;
	p->right=NULL;
	p->data=x;

	if(root==NULL)
	{
		root=p;
	}
	else 
	{
		struct node* q=root;
		struct node* parent;

		while(q!=NULL)
		{
			parent=q;
			if(x<q->data)
			{
				q=q->left;
			}
			else
			{
				q=q->right;
			}
		}
		if(x<parent->data)
		{
			parent->left=p;
		}
		else
		{
			parent->right=p;
		}
	}
}

void preorder(struct node * p)
{
	if(p!=NULL)
	{
		printf(" %d",p->data);
		preorder(p->left);
		preorder(p->right);
	}
	else
		return;
}
void postorder(struct node * p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf(" %d",p->data);
	}
	else
		return;
}
void inorder(struct node * p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf(" %d",p->data);
		inorder(p->right);
	}
	else
		return;

}

void delete(struct node* curr,int x,struct node* parent)
{
	struct node* p=curr;
	struct node* q;
	//struct node* parent=NULL;
	int y;

	if(root==NULL)
	{
		printf("	Sorry , BST is empty....");
	}
	else if(p==NULL)
	{
		return;
	}
	else if(!search(x))
	{
		printf("	Sorry , BST do not contain %d",x);
	}
	else
	{
		while(p->data!=x && p!=NULL)
		{
			parent=p;
			if(x<p->data)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}

		}

		if(p->left==NULL && p->right==NULL)//leaf node ie. no child nodes
		{
			if(p==root)
			{
				root=NULL;
			}
			else
			{
				if(parent->left==p)
				{
					parent->left=NULL;
				}
				else
				{
					parent->right=NULL;
				}
			}
			free(p);
			//printf("	%d is deleted from BST",x);
		}
		else if(p->left==NULL)//only right child
		{
			if(p!=root)
			{
				if(parent->left==p)
				{
					parent->left=p->right;
				}
				else
				{
					parent->right=p->right;
				}
				p->right=NULL;
			}
			else
			{
				root=p->right;
			}
			free(p);
			//printf("	%d is deleted from BST",x);
		}
		else if(p->right==NULL)//only left child
		{
			//q=p;
			//p=p->left;
			if(p!=root)
			{
				if(parent->left==p)
				{
					parent->left=p->left;
				}
				else
				{
					parent->right=p->left;
				}
				p->left=NULL;
			}
			else
			{
				root=p->left;
			}
			free(p);
			//printf("	%d is deleted from BST",x);
		}
		else//both childs present
		{			
			y=find_min(p->right);
			p->data=y;
			delete(p->right,y,p);
		}
			
	}
}
int find_min(struct node* p)
{
	
	while(p!=NULL && p->left!=NULL)
	{
		p=p->left;
	}
	return p->data;
}

int search(int x)
{
	struct node* p=root;
	int flag=0;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			flag=1;
			break;
		}
		else if(x<p->data)
		{
			p=p->left;
		}
		else
		{
			p=p->right;
		}
	}
	if(flag==0)
	{
		return 0;
	}
	return 1;
}



/* OUTPUT   

(base) mansi@mansi-Vostro-15-3568:~$ gcc BST.c
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 1

	Enter data to insert : 3


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 1

	Enter data to insert : 4


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 1

	Enter data to insert : 5


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 1

	Enter data to insert : 2


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 1

	Enter data to insert : 1


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 1

	Enter data to insert : 6


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 4

	Inorder Traversal : 
	 1 2 3 4 5 6

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 5

	Preorder Traversal : 
	 3 2 1 4 5 6

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 6

	Postorder Traversal : 
	 1 2 6 5 4 3

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 3

	Enter data to search : 3

	3 present in BST 

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 3

	Enter data to search : 9

	Sorry ...9 not present in BST 

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 2

	Enter data to delete : 3


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 4

	Inorder Traversal : 
	 1 2 4 5 6

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 2

	Enter data to delete : 1


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 4

	Inorder Traversal : 
	 2 4 5 6

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 2

	Enter data to delete : 5


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 4

	Inorder Traversal : 
	 2 4 6

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 2

	Enter data to delete : 4


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 4

	Inorder Traversal : 
	 2 6

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 2

	Enter data to delete : 6


 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 4

	Inorder Traversal : 
	 2

 ---------------------------------------------------------

		Binary Search Tree Operations
	1) Insert 
	2) Delete
	3) Search
	4) Inorder Traversal
	5) Preorder Traversal
	6) Postorder Traversal
	7) Exit
     Enter your choise : 7


	Thank you ! 
(base) mansi@mansi-Vostro-15-3568:~$ 



*/






























