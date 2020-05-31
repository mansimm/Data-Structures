#include<iostream>
#define MAX 20
using namespace std;

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int x)
{
	if(!visited[x])
	{
		visited[x]=1;
		cout<<" "<<x;
		for(int i=0;i<n;i++)
		{
			if(adj[x][i] && !visited[i])
			{
				dfs(i);
			}
		}
	}
}
int main()
{
	int x;
	cout<<"\n	Depth First Search (DFS) for a Graph";
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
	cout<<"\n DFS is : ";
	dfs(x);
	cout<<"\n";
	return 0;

}
/*

OUTPUT--

(base) mansi@mansi-Vostro-15-3568:~$ g++ DFS_1.cpp
(base) mansi@mansi-Vostro-15-3568:~$ ./a.out

	Depth First Search (DFS) for a Graph
 Enter total number of vertex in graph : 6

 Enter adjacency matrix :
0 1 1 1 0 0
1 0 0 0 1 1
1 0 0 0 0 1
1 0 0 0 0 0
0 1 0 0 0 0
0 1 1 0 0 0

 Enter starting vertex : 0

 DFS is :  0 1 4 5 2 3
(base) mansi@mansi-Vostro-15-3568:~$ 

*/
