#include<iostream>
#define MAX 20
using namespace std;

int adj[MAX][MAX];
int visited[MAX];
int n,front=-1,rear=-1;
int queue[MAX];

int empty()
{
	if(front==-1 && rear==-1)
	{
		return 1;
	}
	return 0;
}
void enque(int x)
{
	if(empty())
	{
		front++;
		rear++;
	}
	else
	{
		rear++;
	}
	queue[rear]=x;
}
int deque()
{
	int x;
	if(!empty())
	{
		x=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front++;
		return x;
	}
}
void bfs(int x)
{
	int y;
	enque(x);
	while(!empty())
	{
		y=deque();
		if(!visited[y])
		{
			cout<<" "<<y;
		}
		visited[y]=1;
		for(int i=0;i<n;i++)
		{
			if(adj[y][i] && !visited[i])
			{
				enque(i);
			}
		}
	}
}
int main()
{
	int x;
	cout<<"\n	Breadth First Search or BFS for a Graph\n";
	cout<<"\n Enter total number of vertex in graph : ";
	cin>>n;
	cout<<"\n Enter adjacency matrix :\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>adj[i][j];
		}
	}
	cout<<"\n Enter starting vertex : ";
	cin>>x;
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	cout<<"\n BFS is : ";
	bfs(x);
	cout<<"\n";
	return 0;
}

/*
Output

(base) mansi@mansi-Vostro-15-3568:~$ g++ BFS.cpp
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out

	Breadth First Search or BFS for a Graph

 Enter total number of vertex in graph : 6

 Enter adjacency matrix :
0 1 1 1 0 0 
1 0 0 0 1 1
1 0 0 0 0 1
1 0 0 0 0 0
0 1 0 0 0 0
0 1 1 0 0 0

 Enter starting vertex : 0

 BFS is :  0 1 2 3 4 5
(base) mansi@mansi-Vostro-15-3568:~$ 


*/
