//https://www.codechef.com/AUG20B/problems/CHEFWED
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#define loop(i,s,e) for(int i=s;i<e;i++)
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n],eff[n];
        loop(i,0,n) cin>>arr[i];
        loop(i,0,n){
            if(i == 0){
                eff[i] = k;
                continue;
            }
            vector<int> vec;
            unordered_map<int,int> mmap;
            int cppl = 0;
            for(int j=i;j>=0;j--){
                if(mmap[arr[j]] >= 1){
                    if(mmap[arr[j]] >= 2) cppl++;
                    else cppl += 2;
                    mmap[arr[j]]++;
                }
                else mmap[arr[j]] = 1;
                if(j == 0) vec.push_back(cppl+k);
                else vec.push_back(eff[j-1]+cppl+k);
            }
            eff[i] = *min_element(vec.begin(),vec.end());
        }
        cout<<eff[n-1]<<endl;
    }
}