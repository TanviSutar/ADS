//segment tree for finding minimun(Range Minimum Query)
#include<iostream>
#include<cmath>
#include<algorithm>
#define MAX 20
#define MAX_VAL 100000000
#define loop(a,b) for(int a=0;a<b;a++)
using namespace std;

int powof2(int n){
    for(int i=0;i<n;i++){
        if(pow(2,i) >= n) return 2*pow(2,i)-1;
    }
    return -1;
}

void constructStree(int arr[],int stree[],int low,int high,int pos){
    if(low == high){
        stree[pos] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    constructStree(arr,stree,low,mid,pos*2+1);
    constructStree(arr,stree,mid+1,high,pos*2+2);
    stree[pos] = std::min(stree[pos*2+1],stree[pos*2+2]);
}

int rmq(int stree[],int qlow,int qhigh,int low,int high,int pos){
    if(low >= qlow and high <= qhigh) return stree[pos];
    if (qlow > high or qhigh < low) return MAX_VAL;
    int mid = (low+high)/2;
    return std::min(rmq(stree,qlow,qhigh,low,mid,pos*2+1),rmq(stree,qlow,qhigh,mid+1,high,pos*2+2));
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    if(n > MAX or n == 0){
        cout<<"Array with "<<n<<" elements not supported.\n";
        return 0;
    }

    int ssize = powof2(n);
    int arr[n],stree[ssize];

    cout<<"Enter "<<n<<" array elements:\n";
    loop(i,n)
        cin>>arr[i];
    loop(i,powof2(n))
        stree[i] = MAX_VAL;

    constructStree(arr,stree,0,n-1,0);

    /*-----------------------------------------
    cout<<powof2(n)<<endl<<n<<endl;
    cout<<"Segment tree\n";
    loop(i,powof2(n)) cout<<i<<" "<<stree[i]<<" ";
    cout<<endl;
    -----------------------------------------*/
    
    cout<<"Enter the number of queries: ";
    cin>>n;
    int l,r;
    if(n>0) cout<<"Enter the queries(left index value and right index value):\n";
    while(n--){
        cin>>l>>r;
        cout<<rmq(stree,l,r,0,ssize-1,0)<<endl;
    }
    return 0;
}