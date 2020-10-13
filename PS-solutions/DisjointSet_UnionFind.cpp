//Union Find using array
#include <iostream>
#include <array>
#include <iterator>
using namespace std;
#define MAX 20

class Union_Find{
    struct Node{
        int val;
        Node *parent;
    };
    array<Node*,MAX> set;
    array<Node*,MAX>::iterator itr;
    public:
        Union_Find(){
            itr = set.begin();
        }

        void myMakeSet(int val){
            if(itr >= set.end()){
                cout<<"Overflow.\n";
                return;
            }
            itr->val = val;
            itr->parent = itr;
            itr++;  
        }

        void print(){
            for(auto itr:set.begin()){
                cout<<itr->val<<" ";
                itr++;
            }
        }
};


int main(){
    Union_Find obj;
    obj.myMakeSet(5);
    obj.myMakeSet(2);
    obj.myMakeSet(7);
    obj.print();
    return 0;
}
