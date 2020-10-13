//disjoint-set-union-find using unordered map
#include <iostream>
#include <unordered_map>
using namespace std;

class Union_Find{
        unordered_map<int,int> parent;
        unordered_map<int,int> rank;
    public: 
        void myMakeSet(int val){
            parent[val] = val;
            rank[val] = 0;
        }

        int myFind(int val){
            int x = val;
            if(parent[x] != x)
                x = myFind(parent[x]);
            parent[val] = x;//path compression
            return parent[x];
        }

        void myUnion(int no1,int no2){
            int p1 = myFind(no1);
            int p2 = myFind(no2);
            if(p1 == p2){
                cout<<"Already in the same set."<<endl;
                return;
            }
            //union by rank
            if(rank[p1] > rank[p2])
                parent[p2] = p1;
            else if(rank[p1] < rank[p2])
                parent[p1] = p2;
            else{
                rank[p1]++;
                parent[p2] = p1;
            }
        }

        void print(){
            for(auto i:parent)
                cout<<i.first<<"->"<<i.second<<" ";
            cout<<endl;
        }
};

int main(){
    Union_Find obj;
    cout<<"Enter the number of sets required: ";
    int n,tmp;
    cin>>n;
    cout<<"Enter the sets: "<<endl;
    while(n--){
        cin>>tmp;
        obj.myMakeSet(tmp);
    }
    int no1,no2;
    do{
        cout<<"Enter sets/set values to be unified: ";
        cin>>no1>>no2;
        obj.myUnion(no1,no2);
        obj.print();
        cout<<"\nContinue?(-1 to exit): ";
        cin>>n;
    }while(n != -1);
    return 0;
}