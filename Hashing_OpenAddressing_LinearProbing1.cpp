//Linear probing without chaining
#include<bits/stdc++.h>
#define MAX 8 // increase this value to increase the size of hashtable 

using namespace std;

class OpenAddressing
{
private:
	int arr[MAX],isempty[MAX];

public:
	OpenAddressing()
	{
		initialize();
	}

	void initialize()
	{
		for(int i=0;i<MAX;i++)
			isempty[i] = 0;
	}
	
	int insert_LinearProbing(int data)
	{
		int index = hashfunc(data);
		for(int i=0;i<MAX;i++)
		{
			if(isempty[index] == 0)
			{
				isempty[index] = 1;
				arr[index] = data;
				return index;
			}
			index = hashfunc(index+1);
		}
		cout<<"Cannot insert.Array overflow.\n\n";
		return -1;
	}

	int search_LinearProbing(int data)
	{
		int index = hashfunc(data);
		for(int i=0;i<MAX;i++)
		{
			if(arr[index] == data)
			{
				cout<<"Data found at index "<<(index+1)<<".\n\n";
				return index;
			}
			index = hashfunc(index+1);
		}
		cout<<"Data element not present in the htable.\n\n";
	}

	int hashfunc(int data)
	{
		return data%MAX;
	}

	void traverse()
	{
		cout<<"Contents of htable:\n";
		for(int i=0;i<MAX;i++)
		{		
			cout<<arr[i]<<" ";
		}	
		cout<<endl;
	}
};

int main()
{
	OpenAddressing obj;
	int data;
	char ch;
	while(true)
	{
		cout<<"Enter data: ";
		cin>>data;
		int val = obj.insert_LinearProbing(data);
		if(val == -1)
			break;
		cout<<"Continue?(y/n): ";
		cin>>ch;
		if(ch == 'n' || ch == 'N')
			break;
	}
	cout<<"Enter the data element to be searched: ";
	cin>>data;
	obj.search_LinearProbing(data);
	obj.traverse();
	return 0;
}
