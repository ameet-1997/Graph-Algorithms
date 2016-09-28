/*
Search Algorithm for undirected graphs
Can be modified for directed graphs

This program uses depth first search


Recursive program

Inputs : The number of vertices and the adjacency matrix

Ameet S Deshpande
CS15B001
*/

/*Working*/



int *graph,*visited;
int n;


#include <iostream>

using namespace std;

int main()
{
	void dfs(int);
	cin>>n;

	graph=new int[n*n];
	visited=new int[n];

	for(int i=0;i<n;++i)		//Inputting the graph
	{
		for(int j=0;j<n;++j)
		{
			cin>>graph[i*n+j];
		}

		visited[i]=0;
	}


	int source=0;		//Modify this for changing the source vertex
	visited[source] = 1;

 
	int current = source;

	dfs(source);

	cout<<"\n";

	delete[] graph;
	delete[] visited; 

} 




void dfs(int current)
{	
	cout<<current+1<<" ";

	for(int i=0;i<n;++i)
	{
		if((visited[i]==0)&&((graph[n*current+i])>0))
		{
			visited[i]=1;
			dfs(i);
		}
	}

	return;
}

/*5
0 1 1 1 0
1 0 1 0 1
1 1 0 0 0
1 0 0 0 1
0 1 0 1 0*/