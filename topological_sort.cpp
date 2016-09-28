/*
This program prints the topologically sorted array of numbers
corresponding to the vertices of the directed graph

Inputs: Directed graph in the form of adjacency matrix
M[u,v] is one if the head is v and tail is u

Output: Topologically sorted vertices



Ameet S Deshpande
CS15B001
*/

/*
Working
*/

/*
Prints vertices based on 0 based indexing
*/


#include <iostream>

using namespace std;


int *graph,*visited,*can_start;
int n;	//Stores the number of vertices in the graph

int main()
{
	void topological_sort(int);

	cin>>n;		//take as input the number of vertices

	graph = new int[n*n];
	visited = new int[n];
	can_start = new int[n];

	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < n;++j)
		{
			cin>>graph[n*j+i];		//The graph is being stored in reverse order, i.e., the transpose of the graph is being stored
		}
		visited[i] = 0;
	}


	int flag = 0;
	int count = 0;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(graph[n*j+i])
			{
				flag = 1;
				break;
			}
		}

		if(flag == 0)
		{
			can_start[count] = i;
			count++;
		}
		else
		{
			flag = 0;
		}
	}

	//Here, existence of cycles have not been checked, but if every vertex's out degree and in degree are >0, then cycle exists

	for( int i = 0;i < count; ++i)
	{
		visited[can_start[i]] = 1;
		topological_sort(can_start[i]);		//Calling the function only if the in degree of the modified graph is 0
	}


	cout<<"\n";



}




void topological_sort(int a)
{
	for(int i=0;i<n;++i)
	{
		if((graph[n*a+i] > 0)&&(visited[i]==0))
		{	
			visited[i] = 1;
			topological_sort(i);
		}
	}

	cout<<a<<" ";
}