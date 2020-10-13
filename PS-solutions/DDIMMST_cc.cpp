//https://www.codechef.com/OCT20B/problems/DDIMMST
#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstdlib>
#include<unordered_set>
#define ll long long
using namespace std;

class Union_Find{
    unordered_map<ll,ll> parent;
    unordered_map<ll,ll> rank;
    vector<pair<ll,ll>> edges;
    ll sum,n;
    public:
    Union_Find(ll n){
        sum = 0;
        this->n = n;
    }

    void myMakeSet(ll ch){
        parent[ch] = ch;
        rank[ch] = 0;
    }

    ll myFind(ll ch){
        int x = ch;
        if(parent[x] != x)
            x = myFind(parent[x]);
        parent[ch] = x;//path compression
        return x;
    }

    void myUnion(ll ch1,ll ch2,ll wgh){
        int pch1 = myFind(ch1);
        int pch2 = myFind(ch2);
        if(pch1 == pch2 or pch1 == '-' or pch2 == '-') return;
        //union by rank
        if(rank[pch1] > rank[pch2])
            parent[pch2] = pch1;
        else if(rank[pch1] < rank[pch2])
            parent[pch1] = pch2;
        else{
            rank[pch1]++;
            parent[pch2] = pch1;
        }
        sum += wgh;
        edges.push_back(make_pair(ch1,ch2));
    }

    void answer(vector<pair<ll,pair<ll,ll>>> vec){
        ll i=0;
        unordered_map<ll,ll>::iterator itr1,itr2;
        while(edges.size() < n-1){
            itr1  = parent.find(vec[i].second.first);
            itr2 = parent.find(vec[i].second.second);
            if(itr1 == parent.end() or itr2 == parent.end()){
                cout<<"Invalid edge(s) found.\n";
                return;
            }
            myUnion(vec[i].second.first,vec[i].second.second,vec[i].first);
            i++;
        }
        /*cout<<"\nThe edges of the MST: "<<endl;
        i=0;
        while(i < edges.size()){
            cout<<edges[i].first<<edges[i].second<<" ";
            i++;
        }
        cout<<endl;*/
        cout<<sum<<endl;
    }

    void show(){
        for(auto i:parent)
            cout<<i.first<<"->"<<i.second<<" ";
        cout<<endl;
    }
};

vector<pair<ll,pair<ll,ll>>> createGraph(ll arr[][5],int n,int d){
    vector<pair<ll,pair<ll,ll>>> vec;
    unordered_set<ll> set1;
    int i,j,k;
    for(i=0;i<n;i++){
        set1.insert(i);
        for(j=0;j<n;j++){
            if(j == i) continue;
            if(set1.find(j) != set1.end()) continue;
            //remove the inserted element from the set
            cout<<i<<" "<<j<<endl;
            ll sum = 0;
            for(k=0;k<d;k++){
                sum += abs(arr[i][k]-arr[j][k]);
            }
            vec.push_back(make_pair(sum,make_pair(i,j)));
        }
    }
    return vec;
};

int main() {
	// your code goes here
	int n,d;
    cin>>n>>d;
	ll arr[n][5];
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<d;j++) 
	        cin>>arr[i][j];
	}

    Union_Find obj(n);
    for(int i=0;i<n;i++){
        obj.myMakeSet(i);
    }

	vector<pair<ll,pair<ll,ll>>> vec = createGraph(arr,n,d);
	sort(vec.begin(),vec.end(),greater<>());
    obj.answer(vec);
	return 0;
}