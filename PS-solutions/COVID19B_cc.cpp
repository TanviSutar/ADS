#include<iostream>
#include<utility>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct node{
    int root;
    int count;
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int vel[n+1],pos[n+1];
        node arr[n+1];
        for(int i=1;i<=n;i++) cin>>vel[i];
        for(int i=1;i<=n;i++){
            pos[i] = i;
            arr[i].root = i;
            arr[i].count = 1;
        }
        int min = 1,max = 1;
        unordered_map<int,int> map;
        for(float i=0.01;i<=5;i += 0.01){
            map.clear();
            for(int j=1;j<=n;j++){
                pos[j] = j+vel[j]*i;
                if(map[pos[j]] >= 1){
                    node *root1 = &arr[map[pos[j]]];
                    node *root2 = &arr[j];
                    if(root1->count == root2->count or root1->count > root2->count){
                        root2->root = root1->root;
                        root1->count++;
                        root2->count = root1->count;
                    }
                    else{
                        root2->count++;
                        root1->root = root2->root;
                        root1->count = root2->count;
                    }
                }
                else map[pos[j]] = 1;
            }
            map.clear();
            for(int j=1;j<=n;j++){
                if(map[arr[j].root] >= 1) map[arr[j].root]++;
                else map[arr[j].root] = 1;
            }
            int tmin = 5,tmax = 1;
            for(auto j:map){
                if(j.second < tmin) tmin = j.second;
                if(j.second > tmax) tmax = j.second;
            }
            min = std::max(min,tmin);
            max = std::max(max,tmax);
        }
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}
