//Weighted activity selection
//Also called as weighted interval selection
//Time complexity: O(n2)
#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define wgh(i) vec[i].second.second
#define strt(i) vec[i].second.first
#define fin(i) vec[i].first
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    vector<pair<int,pair<int,int>>> vec;
    int n,s,f,w;
    cout<<"Enter the number of tasks: ";
    cin>>n;
    cout<<"Enter the start and end time and weight of the tasks:\n";
    for(int i=0;i<n;i++){
        cin>>s>>f>>w;
        vec.push_back(make_pair(f,make_pair(s,w)));
    }
    sort(vec.begin(),vec.end());
    int opt[n];
    for(int i=0;i<n;i++){
        //cout<<i<<" "<<strt(i)<<" "<<fin(i)<<" "<<wgh(i)<<endl;
        int j = i-1;
        int total = wgh(i);
        while(j >= 0){
            if(fin(j) <= strt(i)){
                total += wgh(j);
                break;
            }
            j--;
        }
        if(i > 0){
            total = std::max(total,opt[i-1]);
        }
        opt[i] = total;
        //cout<<i<<" "<<opt[i]<<endl;
    }
    cout<<"Enter value that can be achieved is: "<<opt[n-1]<<endl;
    return 0;
}