//Works only with undirected graph
#include <bits/stdc++.h>

using namespace std;

class DFSUsingAdjacencyMatrix
{
private:
	int M[10][10],visited[10],n;	
public:
	DFSUsingAdjacencyMatrix()
	{
		initialize();
	}
	
	void initialize()
	{
		for(int i=0;i<10;i++)
		{
			visited[i] = 0;
		}
	}
	
	void getAdjacencyMatrix()
	{
		cout<<"Enter the number of nodes(not more than 10): ";//the values for the nodes are not required to be specified, node values start from 0 and end at n-1
		cin>>n;
		cout<<"Enter adjacency matrix:\n";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>M[i][j];
	}

	void display()
	{
		cout<<"Nodes of the graph:\n";
		dfs(0);
	}

	void dfs(int vertex)
	{
		cout<<vertex<<" ";
		visited[vertex] = 1;
		for(int i=0;i<n;i++)
		{
			while(M[vertex][i] && !visited[i])//enter if connection exits and the node is not visited yet
				dfs(i);
		}
	}
};

int main()
{
	DFSUsingAdjacencyMatrix obj;
	obj.getAdjacencyMatrix();
	obj.display();
	cout<<endl;
	return 0;
}
