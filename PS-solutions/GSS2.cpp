#include<iostream>
#include<cstdio>
#include<unordered_set>
#include<vector>
#include<cmath>
using namespace std;

int powof2(int n){
    for(int i=0;i<n;i++)
        if(pow(2,i) >= n) return 2*pow(2,i)-1;
    return -1;
}

unordered_set<int> constructStree(vector<int> arr,vector<int> &stree,int low,int high,int pos){
    if(low >= high){
        stree[pos] = arr[low];
        unordered_set<int> s{stree[pos]};
        return s;
    }
    int mid = (low+high)/2;
    unordered_set<int> s1 = constructStree(arr,stree,low,mid,pos*2+1);
    unordered_set<int> s2 = constructStree(arr,stree,mid+1,high,pos*2+2);
    unordered_set<int> s(s1);
    s.insert(s2.begin(),s2.end());
    int sum = 0;
    for(auto i:s) sum += i; 
    stree[pos] = sum;
    return s;
}

int rmq(vector<int> stree,int qlow,int qhigh,int low,int high,int pos){
    
}

void print(vector<int> stree){
    int j=0;
    for(auto i:stree){
        cout<<j<<" "<<i<<endl;
        j++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n,tmp;
    cin>>n;
    vector<int> arr;
    vector<int> stree;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp < 0){
            arr.push_back(0);
            continue;
        }
        arr.push_back(tmp);
    }
    for(int i=0;i<powof2(n);i++){
        stree.push_back(0);
    }
    constructStree(arr,stree,0,n-1,0);//return value ignored
    int q,x,y;
    unordered_map<int,int> cmap;
    while(q--){
        cin>>x>>y;
        cmap.clear();
    }
    return 0;
}