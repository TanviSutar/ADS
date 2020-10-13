//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define strt(i) vec[i].first.second
#define fin(i) vec[i].first.first
#define index(i) vec[i].second
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,tmp;
        cin>>n;
        vector<pair<pair<int,int>,int>> vec(n,make_pair(make_pair(0,0),0));
        for(int i=0;i<n;i++){
            cin>>tmp;
            strt(i) = tmp;
            index(i) = i+1;
        }
        for(int i=0;i<n;i++){
            cin>>tmp;
            fin(i) = tmp;
        }
        //for(int i=0;i<n;i++) cout<<strt(i)<<" "<<fin(i)<<" "<<index(i)<<endl;
        sort(vec.begin(),vec.end());
        cout<<index(0)<<" ";
        int j = 0;
        for(int i=1;i<n;i++)
            if(strt(i) >= fin(j)){
                cout<<index(i)<<" ";
                j = i;
            }
        cout<<endl;
    }
    return 0;
}