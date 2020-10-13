//Linear probing with chaining and replacement
#include<bits/stdc++.h>
#define MAX 10 

using namespace std;

class OpenAddressing3
{
    private:
        struct Node
        {
            int data;
            Node *next;
        }*arr[MAX];

    public:
        OpenAddressing3()
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
                Node *temp = new Node;//copy the data of the misplaced node
                temp->data = arr[index]->data;
                temp->next = arr[index]->next;

                int i,j;
                for(i=0,j=index+1;i<MAX;i++,j++)//find a new position for the misplaced node and place it there
                {
                    if(arr[hashfunc(j)]->data == -1)
                    {
                        arr[hashfunc(j)] = temp;
                        break;
                    }
                }
                if(i >= MAX)//return if htable overflows
                {
                    cout<<"Data cannot be added. Overflow occured.\n";
                    return -1;
                }

                arr[index]->data = data;
                arr[index]->next = NULL;

                //adjust the links for the misplaced node
                Node *dummy = arr[hashfunc(temp->data)];
                while(dummy->next != temp && dummy->next != NULL)
                {
                    dummy = dummy->next;
                }
                dummy->next = temp->next;

                dummy = temp->next;
                while(dummy->next != NULL)
                    dummy = dummy->next;
                dummy->next = temp;

                temp->next = NULL;

                temp = dummy = NULL;
                delete temp,dummy;

                return hashfunc(j);
            }
        }

        void search(int data)
        {
            int index = hashfunc(data);

            if(hashfunc(arr[index]->data) == hashfunc(data))
            {
                Node *temp = arr[index];
                while(temp != NULL)
                {
                    if(temp->data == data)
                    {
                        cout<<"Element found.\n";
                        return;
                    }
                    temp = temp->next;
                }
            }
            cout<<"Element not found\n";
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
    OpenAddressing3 obj;
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
    cout<<"\nEnter the element to be found: ";
    cin>>data;
    obj.search(data);
    return 0;
}