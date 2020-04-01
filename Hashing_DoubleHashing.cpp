#include<bits/stdc++.h>
#define MAX 20

using namespace std;

class DoubleHashing
{
    private:
        int arr[MAX];

    public:
        DoubleHashing()
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
            int index = hfunc1(data);
            for(int i=1;i<MAX;i++)
            {
                if(arr[index] == -1)
                {
                    arr[index] = data;
                    return index;
                }
                index = (hfunc1(data) + i*hfunc2(data))%MAX; 
            }
            cout<<data<<" cannot be inserted.\n";
            return -1;
        }

        int hfunc1(int data)
        {
            return data%MAX;
        }

        int hfunc2(int data)
        {
            return ((data*data)%MAX);
        }

        void display()
        {
            cout<<"Snapshot of memory arrangement: ";
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
};

int main()
{
    DoubleHashing obj;
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
    return 0;
}