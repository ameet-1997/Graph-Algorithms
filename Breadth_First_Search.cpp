/*
Search Algorithm for undirected graphs
Can be modified for directed graphs

This program uses breadth first search and uses an inbuilt list library


Iterative program

Inputs : The number of vertices and the adjacency matrix

Ameet S Deshpande
CS15B001
*/


//Working




#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n;

	int *graph,*visited;

	list<int> queue;	//Creating a queue

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

	queue.push_back(source); 
	int current = source;

	while(!queue.empty())
	{	
		current=queue.front();

		for(int i=0;i<n;++i)
		{
			if(graph[current*n+i]!=0)
			{
				if(visited[i]==0)
				{
					visited[i]=visited[current]+1;		//Modify this for weighted graphs
					queue.push_back(i);
				}
			}
		}

		queue.pop_front();


	}


	visited[source]=0;

	for(int i=0;i<n;++i)		//Printing the distances from the source vertex
	{
		cout<<visited[i]<<" ";
	}

	cout<<"\n";

	delete[] graph;
	delete[] visited; 

}