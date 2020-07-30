/*
		Priority queue implementation using array

Priority queues are a type of container adapters, specifically designed such that the first element of the queue is the greatest of all elements in the queue and elements are in non increasing order(hence we can see that each element of the queue has a priority{fixed order}).
*/

#include<iostream>
using namespace std;

class Pri_queue
{
	public:
	int que[15];
			
	void show(int n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<" "<<que[i];
		}
	}
	void enque(int x,int n)
	{
		que[n]=x;
		sort(n+1);
	}
	void sort(int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				if(que[j]<que[j+1])
				{
					int temp;
					temp=que[j];
					que[j]=que[j+1];
					que[j+1]=temp;
				}
			}
		}
	}
	void deque(int n)
	{
		if(!isEmpty(n))
		{
			int y= que[0];
			for(int i=0;i<n-1;i++)
			{
				que[i]=que[i+1];
			}
			cout<<"\n "<<y<<" is deleted..";
		}
		else
		{
			cout<<"Queue is empty ! ";
		}
	}
	int isEmpty(int n)
	{
		if(n==0)
		{
			return 1;
		}
		else
		return 0;
	}
	void peek(int n)
	{
		if(!isEmpty(n))
		{
			cout<<"\n Peek element is : "<<que[0];
		}
		else
		cout<<"\n Queue is empty!";
	}
};
int main()
{
	Pri_queue p;
	int n=0,choice,x;

	while(choice!=6)
	{
		cout<<"\n------------------------------------------------";
		cout<<"\n		Priority Queue";
		cout<<"\n	1)Enque";
		cout<<"\n	2)Deque";
		cout<<"\n	3)Show";
		cout<<"\n	4)Check Empty";
		cout<<"\n	5)Top";
		cout<<"\n	6)Exit";
		cout<<"\n   Enter your choice :";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"\n Enter element :";
				cin>>x;
				p.enque(x,n++);
				break;

			case 2:p.deque(n--);
				break;

			case 3:p.show(n);
				break;

			case 4: if(p.isEmpty(n))
				cout<<"\n Priority queue is empty.";
				else
				cout<<"\n Priority queue is not empty.";
				break;

			case 5:p.peek(n);
				break;
			
			case 6:cout<<"\n Thank You!";
				break;
			
			default:cout<<"\n Invallide choice!";		

		}
	}

	return 0;
}
/*
(base) mansi@mansi-Vostro-15-3568:~$ g++ priority_queue.cpp
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out

------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :1

 Enter element :44

------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :1

 Enter element :22

------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :1

 Enter element :88

------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :1

 Enter element :11

------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :1

 Enter element :22

------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :3
 88 44 22 22 11
------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :2

 88 is deleted..
------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :3
 44 22 22 11
------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :2

 44 is deleted..
------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :3
 22 22 11
------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :4

 Priority queue is not empty.
------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :5

 Peek element is : 22
------------------------------------------------
		Priority Queue
	1)Enque
	2)Deque
	3)Show
	4)Check Empty
	5)Top
	6)Exit
   Enter your choice :6

 Thank You!(base) mansi@mansi-Vostro-15-3568:~$ 

*/
