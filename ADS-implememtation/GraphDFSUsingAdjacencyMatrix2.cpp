//Works only with undirected graph
#include <bits/stdc++.h>
#define MAX 10

using namespace std;

class DFSUsingAdjacencyMatrix
{
private:
	struct Node
	{
		int data;
		int flag;
	}nodelist[MAX];
	int M[MAX][MAX],n;

public:	
	DFSUsingAdjacencyMatrix()
	{
		initialize();
	}

	void initialize()
	{
		for(int i=0;i<MAX;i++)
			nodelist[i].flag = 0;
	}

	void getNodelist()
	{
		cout<<"Enter the number of nodes required(not more than 10): ";
		cin>>n;
		try//for detecting array bound exceed exception
		{
			for(int i=0;i<n;i++)
			{	
				cout<<"Enter the node data: ";
				int d;
				cin>>d;
				nodelist[i].data = d;
			} 
			
			cout<<"Enter the adjacency matrix:\n";
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					cin>>M[i][j];
		}
		catch(int i)
		{
			cout<<"Number of specified nodes greater than the maximum limit.";
		}
	}

	void display()
	{
		cout<<"Nodes in the graph are:\n";
		dfs(nodelist[0].data);
		cout<<endl;
	}

	void dfs(int vertex)
	{
		cout<<vertex<<" ";
		nodelist[getIndex(vertex)].flag = 1;
		for(int i=0;i<n;i++)
		{
			while(M[getIndex(vertex)][i] && !nodelist[i].flag)
				dfs(nodelist[i].data);
		}
	}

	int getIndex(int val)
	{
		int i;
		for(i=0;i<n;i++)
			if (nodelist[i].data == val)
				break;
		return i;
	}
	
};

int main()
{
	DFSUsingAdjacencyMatrix obj;
	obj.getNodelist();
	obj.display();
	return 0;
}
