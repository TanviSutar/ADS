//https://www.spoj.com/problems/INVCNT/
#include<iostream>
#define ll long long
using namespace std;

ll prefixSum(ll BIT[],ll index){
    ll sum = 0;
    while(index > 0){
        sum += BIT[index];
        index = index & (index-1);
    }
    return sum;
}

void updateBIT(ll BIT[],ll size,ll index,ll incval){
    while(index < size){
        BIT[index] += incval;
        index += index & (-index);
    }
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
        ll max = -1;
        for(int i=0;i<n;i++){
            //cout<<i<<endl;
            cin>>arr[i];
            max = (arr[i]>max)?arr[i]:max;
        }
        cin.ignore();
        getline(cin,space);
        ll BIT[max+1] = {0};
        ll sum = 0;
        for(ll i=n-1;i>=0;i--){
            sum += prefixSum(BIT,arr[i]-1);
            updateBIT(BIT,max+1,arr[i],1);
        }
        cout<<sum<<endl;
    }
    return 0;
}