#include <bits/stdc++.h>
#define MAX 10


using namespace std;

class BFSTraversal
{
private:
	int n,N[MAX],visited[MAX],E[MAX][MAX];

public:
	BFSTraversal()
	{
		initialize();
	}

	void initialize()
	{
		for(int i=0;i<MAX;i++)
			visited[i] = 0;
	}

	void getNodeList()
	{
		cout<<"Enter the number of nodes: ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter node"<<i<<": ";
			cin>>N[i];
		}
	}

	int getIndex(int val)
	{
		for(int i=0;i<n;i++)
			if(N[i] == val)
				return i;
		return -1;
	}

	void getEdgeList()
	{
		cout<<"\nEnter adjacency matrix: ";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>E[i][j];	
	}

	void BFS(int val)
	{
		queue<int> que;
		cout<<val<<" ";
		visited[getIndex(val)] = 1;
		que.push(val);
		while(!que.empty())
		{
			int val = que.front();
			que.pop();
			for(int i=0;i<n;i++)
			{
				if(!visited[i] && E[getIndex(val)][i])
				{
					cout<<N[i]<<" ";
					que.push(N[i]);
					visited[i] = 1;
				}
			}
		}
	}
	
	void display()
	{
		cout<<"\nBFS Traversal is: \n";
		BFS(N[0]);	
		cout<<endl;
	}
};

int main()
{
	BFSTraversal obj;
	obj.getNodeList();
	obj.getEdgeList();
	obj.display();
	return 0;
}
