
#include <bits/stdc++.h>
#define MAX 10

using namespace std;

class BFSTraversal
{
private:
	struct Node
	{
		int data;
		Node* next;
	}*N[MAX];
	int visited[MAX],n,e;

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
		cout<<"Enter number of nodes(should be <= 10): ";
		cin>>n;
		for(int i=0;i<n;i++)
		{	
			cout<<"Enter node "<<(i+1)<<": ";
			N[i] = new Node;
			cin>>N[i]->data;
			N[i]->next = NULL;
		}
	}

	void getEdgeList()
	{
		Node *temp;
		Node *dummy;
		cout<<"Enter the number of edges: ";
		cin>>e;
		int vi,vj;
		for(int i=0;i<e;i++)
		{
			cout<<"Enter the edge"<<i+1<<": ";
			cin>>vi>>vj;
			
			try
			{
				temp = new Node;
				temp->data = vj;
				temp->next = NULL;
				dummy = getNode(vi);
				while(dummy->next != NULL)
					dummy = dummy->next;
				dummy->next = temp;

				temp = new Node;
				temp->data = vi;
				temp->next = NULL;
				dummy = getNode(vj);
				while(dummy->next != NULL)
					dummy = dummy->next;
				dummy->next = temp;
			}
			catch(...)
			{
				cout<<"Error occured.\n";
			} 
		}
		temp = NULL;
		delete temp;
	}

	Node* getNode(int val)
	{
		for(int i=0;i<n;i++)
		{
			if(N[i]->data == val)
				return N[i];
		}
		return NULL;
	}

	int getIndex(int val)
	{
		for(int i=0;i<n;i++)
			if(N[i]->data == val)
				return i;
		return -1;
	}

	void displayAdjacencyList()
	{
		Node *temp;
		for(int i=0;i<n;i++)
		{
			cout<<N[i]->data<<": ";
			temp = N[i]->next;
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		temp = NULL;
		delete temp;
		BFS(N[0]->data);
	}

	void BFS(int val)
	{
		cout<<"\nBFS Traversal:\n";
		cout<<val<<" ";
		visited[getIndex(val)] = 1;
		queue<int> q;		
		q.push(val);
		while(!q.empty())
		{
			Node *temp = getNode(q.front());
			q.pop();
			temp = temp->next;
			while(temp != NULL)
			{
				if(!visited[getIndex(temp->data)])
				{
					cout<<temp->data<<" ";
					visited[getIndex(temp->data)] = 1;
					q.push(temp->data);
				}
				temp = temp->next;
			}
		}
		cout<<endl;		
	}
};

int main()
{
	BFSTraversal obj;
	obj.getNodeList();
	obj.getEdgeList();
	obj.displayAdjacencyList();
	return 0;
}


