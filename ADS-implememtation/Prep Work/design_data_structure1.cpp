//Design a data structure which performs the following operations(Insert an element/Remove an element /find random element) in O(1) time complexity Asked in : Google, Facebook, Amazon

// we can implement this by combining arraylistand hashmap data structures.
#include<iostream>
#include<unordered_map>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;

int const N = 10;

class HashedArray{
    int arr[N];
    unordered_map<int,int> map;
    int i;

    public:
        HashedArray(){
            this->i = -1;
        }

        bool isFull(){
            if(i+1 >= 10) return true;
            return false;
        }

        void insert(int val){
            if(isFull()){
                cout<<"Overflow\n";
                return;
            }
            arr[++i] = val;
            map[val] = i;
        }

        int find(int val){
            if(map.find(val) == map.end())
                return -1;
            return map[val];
        }

        void mydelete(int val){
            int ind = find(val);
            if(ind == -1){
                cout<<"Element not found.\n";
                return;
            }
            map.erase(val);
            arr[ind] = arr[i];
            i--;
        }

        void random(){
            srand(time(0));
            cout<<arr[rand()%(i+1)]<<endl;
        }

        void print(){
            int j = 0;
            while(j <= i){
                cout<<arr[j]<<" ";
                j++;
            }
            cout<<endl;
        }
};

int main(){
    HashedArray obj;
    obj.insert(3);
    obj.insert(8);
    obj.insert(9);
    cout<<obj.find(6)<<endl;
    cout<<obj.find(8)<<endl;
    obj.mydelete(9);
    obj.mydelete(2);
    obj.random();
    obj.print();
    return 0;
}