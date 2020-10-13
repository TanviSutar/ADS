//Quadratic probing
#include<bits/stdc++.h>
#define MAX 20

using namespace std;

class QuadraticProbe
{
    private:
        int arr[MAX];

    public:
        QuadraticProbe()
        {
            initialize();
        }

        void initialize()
        {
            for(int i=0;i<MAX;i++)
            {
                arr[i] = -1;
            }
        }

        int insert(int data)
        {
            int index = hashfunc(data);
            for(int i=0;i<MAX;i++)
            {
                if(arr[hashfunc(index + (i*i))] == -1)
                {
                    arr[hashfunc(index + (i*i))] = data;
                    return (index + (i*i)); 
                }
            }
            cout<<"Cannot insert. Overflow occured.\n";
            return -1;
        }

        int search(int data)
        {
            int index = hashfunc(data);
            for(int i=0;i<MAX;i++)
            {
                if(arr[hashfunc(index+(i*i))] == data)
                {
                    cout<<"Element found at "<<hashfunc(index+(i*i))+1<<endl;
                    return hashfunc(index+(i*i));
                }
            }
            cout<<"Element does not exists.\n";
            return -1;
        }

        void display()
        {
            cout<<"\nSnapshot of memory storage:\n";
            for(int i=0;i<MAX;i++)
            {
                if(arr[i] == -1)
                {
                    cout<<"0"<<" ";
                    continue;
                }
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        int hashfunc(int data)
        {
            return data%MAX;
        }
};

int main()
{
    QuadraticProbe obj;
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
    cout<<"\nEnter data to be searched: ";
    cin>>data;
    obj.search(data);
    return 0;
}