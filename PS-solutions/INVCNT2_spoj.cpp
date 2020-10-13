//https://www.spoj.com/problems/INVCNT/
//using merge sort
//needs amends
#include<iostream>
#define ll long long
using namespace std;

ll sum = 0;

void merge(ll arr[],ll strt,ll mid,ll end){
    ll lend = mid-strt+1,rend = end-mid;
    ll l[lend],r[rend];
    for(ll i=0;i<lend;i++)
        l[i] = arr[strt+i];
    for(ll i=0;i<rend;i++)
        r[i] = arr[mid+1+i];
    ll i=0,j=0,k=strt;
    while(i < lend and j < rend){
        if(l[i] > r[j]){
            arr[k] = r[j];
            j++;
            sum += lend-i+1;
        }
        else{
            arr[k] = l[i];
            i++;
        }
        k++;
    }
    while(i < lend){
        arr[k] = l[i];
        i++,k++;
    }
    while(j < rend){
        arr[k] = r[j];
        j++;k++;
    }
}

void mergeSort(ll arr[],ll strt,ll end){
    if(strt >= end) return;
    ll mid = (strt+end)/2;
    mergeSort(arr,strt,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,strt,mid,end);
}

int main(){
    ll t;
    string space;
    cin>>t;
    getline(cin,space);
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin.ignore();
        getline(cin,space);
        mergeSort(arr,0,n-1);
        cout<<sum<<endl;
    }
    return 0;
}