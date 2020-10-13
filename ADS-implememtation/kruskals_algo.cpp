#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class Union_Find{
    unordered_map<char,char> parent;
    unordered_map<char,int> rank;
    vector<pair<char,char>> edges;
    int sum,n;
    public:
    Union_Find(int n){
        sum = 0;
        this->n = n;
    }

    void myMakeSet(char ch){
        parent[ch] = ch;
        rank[ch] = 0;
    }

    char myFind(char ch){
        char x = ch;
        if(parent[x] != x)
            x = myFind(parent[x]);
        parent[ch] = x;//path compression
        return x;
    }

    void myUnion(char ch1,char ch2,int wgh){
        char pch1 = myFind(ch1);
        char pch2 = myFind(ch2);
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

    void answer(vector<pair<int,pair<char,char>>> vec){
        int i=0;
        unordered_map<char,char>::iterator itr1,itr2;
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
        cout<<"\nThe edges of the MST: "<<endl;
        i=0;
        while(i < edges.size()){
            cout<<edges[i].first<<edges[i].second<<" ";
            i++;
        }
        cout<<endl;
        cout<<"Weight of MST: "<<sum<<endl;
    }

    void show(){
        for(auto i:parent)
            cout<<i.first<<"->"<<i.second<<" ";
        cout<<endl;
    }
};

int main(){
    cout<<"Enter the number of vertices in the graph: ";
    int n;
    cin>>n;
    Union_Find obj(n);
    char ch;
    cout<<"Enter "<<n<<" vertices' names:\n";
    while(n--){
        cin>>ch;
        obj.myMakeSet(ch);
    }
    cout<<"Enter the number of edges: ";
    cin>>n;
    cout<<"Enter "<<n<<" edges' names and weights respectively:\n";
    char ch2;
    int tmp;
    vector<pair<int,pair<char,char>>> vec;
    while(n--){
        cin>>ch>>ch2>>tmp;
        vec.push_back(make_pair(tmp,make_pair(ch,ch2)));
    }
    sort(vec.begin(),vec.end(),greater <>());
    obj.answer(vec);
    return 0;
}