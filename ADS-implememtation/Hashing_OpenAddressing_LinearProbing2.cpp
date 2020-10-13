//Linear probing with chaining without replacement
#include<bits/stdc++.h>
#define MAX 10 

using namespace std;

class OpenAddressing2
{
    private:
        struct Node
        {
            int data;
            Node *next;
        }*arr[MAX];

    public:
        OpenAddressing2()
        {
            initialize();
        }

        void initialize()
        {
            for(int i=0;i<MAX;i++)
            {
                arr[i] = new Node;
                arr[i]->data = -1;
                arr[i]->next = NULL;
            }
        }

        int insert(int data)
        {
            int index = hashfunc(data);
            if(arr[index]->data == -1)//if the required location is empty
            {
                arr[index]->data = data;
                arr[index]->next = NULL;
                return index;
            }

            //if the element at the obtained index is a synonym of the element to be inserted eg:21 ,131,81,1 are all synonyms 
            if(hashfunc(arr[index]->data) == hashfunc(data))
            {
                Node *dummy = arr[index];
                while(dummy->next != NULL)//this will find the last element inserted that is the synonym of the element to be inserted
                    dummy = dummy->next;// the element to be inserted would be placed in a location after this element
               
                for(int j=0,i=index+1;j<MAX;j++,i++)
                {
                    if(arr[hashfunc(i)]->data == -1)//hashfunc(i) would provide us with circular list functionality
                    {
                        arr[hashfunc(i)]->data = data;
                        arr[hashfunc(i)]->next = dummy->next;
                        dummy->next = arr[hashfunc(i)];
                        return hashfunc(i);
                    }
                }
                dummy = NULL;
                delete dummy;
            }

            //if the element already stored at the obtained index is not a synonym of the element to be inserted
            {
                Node *dummy = NULL;
                for(int i=0,j=index+1;i<MAX;i++,j++)
                {
                    if(arr[hashfunc(j)]->data == -1)
                    {
                        arr[hashfunc(j)]->data = data;
                        arr[hashfunc(j)]->next = NULL;
                        if(dummy != NULL)
                            dummy->next = arr[j];
                        return hashfunc(j);
                    }
                    if(hashfunc(arr[hashfunc(j)]->data) == hashfunc(data))
                    {
                        dummy = arr[hashfunc(j)];
                    }
                }
                dummy = NULL;
                delete dummy;
            }

            cout<<"Data cannot be added. Overflow occured.\n";
            return -1;
        }

        void search(int data)
        {
            int index = hashfunc(data);
            if(arr[index]->data == data)//if the element is found at its mapped location in first try
            {
                cout<<"Element found at index: "<<index<<endl;
                return;
            }

            //search in the next locations for the element or its synonym
            int i;
            for(int j=0,i=index+1;j<MAX;j++,i++)
            {
                if(arr[hashfunc(i)]->data == data)
                {
                    cout<<"Element found at "<<hashfunc(i)<<endl;
                    return;
                }
                if(hashfunc(arr[hashfunc(i)]->data) == hashfunc(data))
                    break;
            }

            //if  any synonym of required element is found then we can traverse directly using links
            Node *temp = arr[hashfunc(i)];
            while(temp != NULL)
            {
                if(temp->data == data)
                {
                    cout<<"Element found.\n";
                    return;
                }
                temp = temp->next;
            }

            temp = NULL;
            delete temp;
        }

        void display()
        {
            cout<<"\nData stored is:\n";
            for(int i=0;i<MAX;i++)
            {
                if(arr[i]->data == -1)
                    continue;
                cout<<arr[i]->data<<" ";
            }
            cout<<endl;
        }

        int hashfunc(int data)//hash function
        {
            return data%MAX;
        }

};

int main()
{
    OpenAddressing2 obj;
    int data;
    char ch;
    while(true)
    {
        cout<<"Enter data: ";
        cin>>data;
        int i = obj.insert(data);
        if(i == -1)
            break;
        cout<<"Continue?(y/n): ";
        cin>>ch;
        if(ch == 'n' || ch == 'N')
            break;
    }
    obj.display();
    cout<<"Enter an element to be searched: ";
    cin>>data;
    obj.search(data);
    return 0;
}