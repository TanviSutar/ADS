//Weighted activity selection
//Time complexity: O(n logn), used binary search to optimize
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define strt(i) vec[i].first.second
#define fin(i) vec[i].first.first
#define wgh(i) vec[i].second
#define vpp vector<pair<pair<int,int>,int>> 
using namespace std;

int binary_search(vpp vec,int i){
    int low = 0,high = i-1,mid = -1,ans = -1;
    if(high == low and fin(low) <= strt(i)) return low;
    while(high >= low){
        mid = (high+low)/2;
        if(fin(mid) <= strt(i)) low = mid+1;
        else high = mid-1;
        if(fin(mid) <= strt(i)) ans = mid;
    }
    return ans;
}

int main(){
    cout<<"Enter the number of tasks: ";
    int n,s,e,w;
    cin>>n;
    vpp vec;
    cout<<"Enter the start and end time with weight of the tasks:\n";
    for(int i=0;i<n;i++){
        cin>>s>>e>>w;
        vec.push_back(make_pair(make_pair(e,s),w));
    }
    sort(vec.begin(),vec.end());
    vector<int> opt(n,0);
    try{
    for(int i=0;i<n;i++){
        int total = wgh(i);
        if(i-1 >= 0){
            int tmp = binary_search(vec,i);
            if(tmp >= 0)
                total = std::max(opt[i-1],total+opt[tmp]);
            else 
                total = std::max(opt[i-1],total);
        }
        opt[i] = total;
    }
    }
    catch(...){cout<<"Error";}
    cout<<opt[n-1]<<endl;
    return 0;
}