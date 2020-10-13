//Segment Tree for finding maximum with update(Range Minimun Query)
#include<iostream>
#include<cmath>
#include<algorithm>
#include<array>
#define loop(a,b) for(int a=0;a<b;a++)
#define loop2(a) while(a--)
#define loop3(a,b,i) for(int i=a;i<=b;i++)
#define MAX 20
#define MIN_VAL -100000000
using namespace std;

int powof2(int n){
    loop(i,n)
        if(pow(2,i) >= n) return 2*pow(2,i)-1;
    return -1;
}

void constructTree(int arr[],int stree[],int low,int high,int pos){
    if(low == high){
        stree[pos] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    constructTree(arr,stree,low,mid,pos*2+1);
    constructTree(arr,stree,mid+1,high,pos*2+2);
    stree[pos] = std::max(stree[pos*2+1],stree[pos*2+2]);  
}

int bruteforce_rmq(int stree[],int qlow,int qhigh,int low,int high,int pos){
    if(qlow <= low and qhigh >= high) return stree[pos];
    if (qlow > high or qhigh < low) return MIN_VAL;
    int mid = (low+high)/2;
    return std::max(bruteforce_rmq(stree,qlow,qhigh,low,mid,pos*2+1),bruteforce_rmq(stree,qlow,qhigh,mid+1,high,pos*2+2));
}

void bruteforce_update(int stree[],int qlow,int qhigh,int low,int high,int pos,int incval){
    if(low > high)  return;
    if(qlow > high or qhigh < low) return;//no overlap
    if(low != high){//not a leaf node
        int mid = (low+high)/2;
        bruteforce_update(stree,qlow,qhigh,low,mid,pos*2+1,incval);
        bruteforce_update(stree,qlow,qhigh,mid+1,high,pos*2+2,incval);
        stree[pos] = std::max(stree[pos*2+1],stree[pos*2+2]);
    }
    else stree[pos] += incval;
}

int lazypropogation_rmq(int stree[],int updaterep[],int qlow,int qhigh,int low,int high,int pos){
    if(updaterep[pos] != 0){//assimilating pending updates
        stree[pos] += updaterep[pos];
        if(low != high){
            updaterep[pos*2+1] += updaterep[pos];
            updaterep[pos*2+2] += updaterep[pos];
        }
        updaterep[pos] = 0;
    }
    if(qlow <= low and qhigh >= high) return stree[pos];//total overlap
    if(qlow > high or qhigh < low) return MIN_VAL;//no overlap
    int mid = (low+high)/2;//partial overlap
    return std::max(lazypropogation_rmq(stree,updaterep,qlow,qhigh,low,mid,pos*2+1),lazypropogation_rmq(stree,updaterep,qlow,qhigh,mid+1,high,pos*2+2));
}

void lazypropogation_update(int stree[],int updaterep[],int qlow,int qhigh,int low,int high,int pos,int incval){
    if(low > high) return;
    if(updaterep[pos] != 0){
        stree[pos] += updaterep[pos];
        if(low != high){//not a leaf node
            updaterep[pos*2+1] += updaterep[pos];
            updaterep[pos*2+2] += updaterep[pos];
        }
        updaterep[pos] = 0;
    }
    if(qlow > high or qhigh < low) return;//no overlap
    if(qlow <= low and qhigh >= high){//total overlap
        stree[pos] += incval;
        if(low != high){//not a leaf node
            updaterep[pos*2+1] += incval;
            updaterep[pos*2+2] += incval;
        }
        return;
    }
    //partial overlap
    int mid = (low+high)/2;
    lazypropogation_update(stree,updaterep,qlow,qhigh,low,mid,pos*2+1,incval),lazypropogation_update(stree,updaterep,qlow,qhigh,mid+1,high,pos*2+2,incval);
    stree[pos] = std::max(stree[pos*2+1],stree[pos*2+2]);
}


int main(){
cout<<"Enter the number of elements in the array: ";
    int n,q;
    cin>>n;
    if(n > MAX or n <= 0){
        cout<<"Invalid array size.\n";
        return 0;
    }

    cout<<"Enter "<<n<<" elements of the array:\n";
    int ssize = powof2(n);
    int arr[n];
    int stree[ssize];
    int updaterep[ssize];
    loop(i,n) cin>>arr[i];
    loop(i,ssize) stree[i] = MIN_VAL;
    loop(i,ssize) updaterep[i] = 0;

    constructTree(arr,stree,0,n-1,0);    

    cout<<"Enter the number of queries: ";
    cin>>q;
    int l,r,ch,incval;
    if(q > 0) cout<<"1. Finding Max value from range.\n2. Incrementing/decrementing range/individual value.\n3. Display current array values.\n";
    loop2(q){
        cout<<"\nEnter the choice: ";
        cin>>ch;
        if(ch == 1){
            cout<<"Enter left and right index: ";
            cin>>l>>r;
            if(l < 1 or r > n or l > r){
                cout<<"Invalid index or index sequence.\n";
                continue;
            }
            cout<<lazypropogation_rmq(stree,updaterep,l-1,r-1,0,n-1,0)<<endl;
            //cout<<bruteforce_rmq(stree,l-1,r-1,0,n-1,0)<<endl;
        }
        else if(ch == 2){
            cout<<"Enter left and right index and inc/dec value: ";
            cin>>l>>r>>incval;
            if(l < 1 or r > n  or l > r){
                cout<<"Invalid index or index sequence.\n";
                continue;
            }
            lazypropogation_update(stree,updaterep,l-1,r-1,0,n-1,0,incval);
            //bruteforce_update(stree,l-1,r-1,0,n-1,0,incval);
            loop3(l-1,r-1,i) arr[i] += incval; cout<<endl;
        }
        else if(ch == 3){
            loop(i,n) cout<<arr[i]<<" ";
            cout<<endl;
        }
        else{
            cout<<"Invalid option.\n";
        }
    }
    return 0;
}