#include<bits/stdc++.h>
#define MAX 20

using namespace std;

class DFS
{
private:
	struct Node
	{
		int data;
		Node *next;
	}*G[MAX];
	int visited[MAX];
	int n,e;

public:
	DFS()
	{
		initialize();
	}

	void initialize()
	{
		for(int i=0;i<MAX;i++)
			visited[i] = 0;
	}

	void getNodelist()
	{
		cout<<"Enter the number of nodes(should not be more than 20): ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter data for node"<<i+1<<": ";
			G[i] = new Node;
			cin>>G[i]->data;
			G[i]->next = NULL;
		}
	}	

	void getEdgelist()
	{
		int vi,vj;
		cout<<"Enter the number of edges: ";
		cin>>e;
		for(int i=0;i<e;i++)
		{
			cout<<"Enter egde pair"<<i+1<<"(u,v): ";
			cin>>vi>>vj;
			insert(vi,vj);
		}
		displayAdjacencyList();
	}

	void insert(int vi,int vj)
	{
		if(getIndex(vi) == -1 || getIndex(vj) == -1)
		{
			cout<<"Invalid edge. Edge with unknown vertex or vertices.\n";
			return;
		}
		
		Node *temp = G[getIndex(vi)];
		Node *temp2 = new Node;
		temp2->data = vj;
		temp2->next = NULL;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = temp2;

		temp = G[getIndex(vj)];
		temp2 = new Node;
		temp2->data = vi;
		temp2->next = NULL;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = temp2;
	
		temp = temp2 = NULL;
		delete temp,temp2;
	}

	int getIndex(int val)
	{
		for(int i=0;i<n;i++)
			if(G[i]->data == val)
				return i;
		return -1;
	}

	void displayAdjacencyList()
	{
		cout<<"\nAdjacency List is: \n";
		for(int i=0;i<n;i++)
		{
			Node *temp = new Node;
			temp = G[i];
			cout<<temp->data<<": ";
			temp = temp->next;
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	int isConnected()
	{
		cout<<"\nConnected nodelist: ";
		dfs(G[0]->data);
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			if(visited[i] == 0)
				return 0;
		}
		initialize();
		return 1;
	}

	void numberOfComponents()
	{
		initialize();
		int count;
		for(int i=0;i<n;i++)
		{
			if(visited[i] == 0)
			{
				dfs(G[i]->data);
				count++;				
			}	
		}
		cout<<"Number of components: "<<count<<endl;
	}

	void dfs(int data)
	{
		cout<<data<<" ";
		visited[getIndex(data)] = 1;
		Node *temp = G[getIndex(data)];
		while(temp != NULL)
		{
			if(!visited[getIndex(temp->data)])
				dfs(temp->data);
			temp = temp->next;
		}
	}

	void dfsNonRecursive(int data)//needs some fixes
	{
		initialize();
		stack<Node*> stk;
		stk.push(G[getIndex(data)]);
		while(!stk.empty())
		{
			Node *temp = stk.top();
			stk.pop();
			if(!visited[getIndex(temp->data)])
			{
				cout<<temp->data<<" ";
				visited[getIndex(temp->data)] = 1;
				temp = temp->next;
				cout<<temp->data<<"**"<<endl;
				while(temp != NULL)
				{
					if(!visited[getIndex(temp->data)])
						stk.push(temp);
					cout<<stk.top()->data<<endl;
					temp = temp->next;
				}
			}
		}
	}

	void display(int i)
	{
		cout<<"\nDFS traversal result: ";
		if(i == 0)
			dfs(G[0]->data);
		else
			dfsNonRecursive(G[0]->data);
		cout<<endl;
	}
};

int main()
{
	DFS obj;
	obj.getNodelist();
	obj.getEdgelist();
	obj.display(0);
	return 0;
}



