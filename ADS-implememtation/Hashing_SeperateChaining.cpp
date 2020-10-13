#include<bits/stdc++.h>
#define MAX 10

using namespace std;

class SeperateChaining
{
private:
	struct Node
	{
		int data;
		Node *next;
	}*htable[MAX];

public:
	SeperateChaining()
	{
		initialize();
	}

	void initialize()
	{
		for(int i=0;i<MAX;i++)
		{
			htable[i] = new Node;
			htable[i]->data = -1;
			htable[i]->next = NULL;
		}
	}

	void insert(int data)
	{
		int index = hashfunc(data);
		Node *temp;
		
		temp = htable[index];
		while(temp != NULL)
		{
			if(temp->data == data)
			{
				cout<<"Element already exits.\n";
				return;
			}
			temp = temp->next;
		}
		
		temp = new Node;
		temp->data = data;
		temp->next = htable[index]->next;
		htable[index]->next = temp;
		
		temp = NULL;
		delete temp;
	}

	void find(int data)
	{
		Node *temp = htable[hashfunc(data)]->next;
		while(temp != NULL)
		{
			if(temp->data == data)
			{
				cout<<"Data found.\n";
				return;
			}
			temp = temp->next;
		}
		cout<<"Data not found.\n";
	}

	void traverse(int data)
	{
		int index = hashfunc(data);
		Node *temp;
		for(int i=0;i<MAX;i++)
		{
			temp = htable[i]->next;
			cout<<i<<": ";
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		cout<<endl;
		delete temp;
	}

	int hashfunc(int data)
	{
		return (data%MAX);
	}

};

int main()
{
	SeperateChaining obj;
	int data;
	char ch;
	while(true)
	{
		cout<<"Enter the element to be inserted: ";
		cin>>data;
		obj.insert(data);
		cout<<"Continue?(y/n): ";
		cin>>ch;
		if(ch == 'n' || ch == 'N')
			break;
	}
	obj.traverse(data);
	cout<<"Enter the data to be searched: ";
	cin>>data;
	obj.find(data);
	return 0;	
}


