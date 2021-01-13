//https://www.codechef.com/NOV20B/problems/UNSQUERS
#include<iostream>
#include<algorithm>
using namespace std;

int m = 0;

int getSizeOfTree(int val){
    int i = 1;
    while(i < val){
        i = i*2;
    }
    return 2*i-1;
}

void constructStree(int arr[],int stree[],int low,int high,int pos){
    if(low == high){
        if(arr[low] > m){
            stree[pos] = 1;
            m = arr[low];
            cout<<m<<arr[low]<<endl;
        }
        else stree[pos] = 0;
        return;
    }
    int mid = (low+high)/2;
    constructStree(arr,stree,low,mid,pos*2+1);
    constructStree(arr,stree,mid+1,high,pos*2+2);
    stree[pos] = stree[pos*2+1]+stree[pos*2+2];
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
    if(qlow <= low and qhigh >= high) return stree[pos];//total overlap
    if(qlow > high or qhigh < low) return 0;
    int mid = (low+high)/2;
    return rmq(stree,qlow,qhigh,low,mid,pos*2+1) + rmq(stree,qlow,qhigh,mid+1,high,pos*2+2);
}


int main(){
    int n,q,s;
    cin>>n>>q>>s;
    int arr[n];
    int size = getSizeOfTree(n);
    int stree[size];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<size;i++) stree[i] = 0;
    constructStree(arr,stree,0,n-1,0);
    for(auto i:stree) cout<<i<<" ";cout<<endl;
    int last = 0,x,y,L,R;
    while(q--){
        cin>>x>>y;
        L = (x+s*last-1)%n;
        R = (y+s*last-1)%n;
        if(L > R) swap(L,R);
        last = rmq(stree,L,R,0,n-1,0);
        cout<<last<<endl;
    }
    return 0;
}