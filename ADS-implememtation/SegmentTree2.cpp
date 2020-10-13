//segment tree for finding sum(Range minimun Query)
#include<iostream>
#include<cmath>
#define loop(a,b) for(int a=0;a<b;a++)
#define MAX 20
#define MAX_VALUE 100000000
using namespace std;

int powof2(int n){
    for(int i=0;i<n;i++){
        if(pow(2,i) > n) return pow(2,i);
    }
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
    stree[pos] = stree[pos*2+1]+stree[pos*2+2];
}

int rmq(int stree[],int qlow,int qhigh,int low,int high,int pos){
    if(qlow <= low and qhigh >= high) return stree[pos];
    if(qlow > high or qhigh < low) return 0;
    int mid = (low+high)/2;
    return (rmq(stree,qlow,qhigh,low,mid,pos*2+1)+rmq(stree,qlow,qhigh,mid+1,high,pos*2+2));
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
    int arr[n],stree[ssize];
    loop(i,n) cin>>arr[i];
    loop(i,ssize) stree[i] = MAX_VALUE;

    constructTree(arr,stree,0,ssize-1,0);

    cout<<"Enter the number of queries: ";
    cin>>q;
    int l,r;
    cout<<"Enter the queries(left index and right index):\n";
    loop(i,q){
        cin>>l>>r;
        if(l < 1 or r > n or l > r){
            cout<<"Invalid index\n";
            continue;
        }
        cout<<rmq(stree,l-1,r-1,0,ssize-1,0)<<endl;
    } 
    return 0;
}