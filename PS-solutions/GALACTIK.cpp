//https://www.codechef.com/problems/GALACTIK
#include<iostream>
#include<unordered_map>
#include<cmath>
#define ll long long 
using namespace std;

class Disjoint_Set{
        unordered_map<ll,ll> parent;
        unordered_map<ll,ll> rank;
        unordered_map<ll,ll> cost;
    public:
        void makeset(ll val){
            for(ll i=1;i<=val;i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }
        ll myfind(ll val){
            if(parent[val] == val) return val;
            ll x = val;
            x = myfind(parent[x]);
            parent[val] = x;
            return x;
        }
        void myunion(ll val1,ll val2){
            ll p1 = myfind(val1);
            ll p2 = myfind(val2);
            if(p1 == p2) return;
            if(rank[p1] > rank[p2]) parent[p2] = p1;
            else if(rank[p1] < rank[p2]) parent[p1] = p2;
            else{
                rank[p1]++;
                parent[p2] = p1;
            }
        }
        void getcost(ll val1,ll val2){
            if(val2 < 0) cost[val1] = pow(10,4)+1;
            else cost[val1] = val2;
        }
        void answer(){
            unordered_map<ll,ll> fcost;
            unordered_map<ll,ll>::iterator itr;
            for(auto i:parent){
                ll prnt = myfind(i.first);
                if(fcost.empty()){
                    fcost.insert(make_pair(prnt,cost[i.first]));
                    continue;
                }
                itr = fcost.find(prnt);
                if(itr == fcost.end())
                    fcost.insert(make_pair(prnt,cost[i.first]));
                else if(cost[i.first] < itr->second)
                    itr->second = cost[i.first];
            }
            ll sum = 0;
            itr = fcost.begin();
            ll small = itr->second;
            while(itr != fcost.end()){
                if(itr->second > pow(10,4)) break;
                else sum += itr->second;
                if(small > itr->second) small = itr->second;
                itr++;
            }
            if(itr != fcost.end()) cout<<-1<<endl;
            else cout<<small*(fcost.size()-1)+sum - small<<endl;
        }
};

int main(){
    Disjoint_Set obj;
    ll n,m,i,tmp1,tmp2;
    cin>>n>>m;
    obj.makeset(n);
    i = 1;
    while(i<=m){
        cin>>tmp1>>tmp2;
        obj.myunion(tmp1,tmp2);
        i++;
    }
    i = 1;
    while(i<=n){
        cin>>tmp1;
        obj.getcost(i,tmp1);
        i++;
    }
    if(n == 1) cout<<0<<endl;
    else obj.answer();
    return 0;
}