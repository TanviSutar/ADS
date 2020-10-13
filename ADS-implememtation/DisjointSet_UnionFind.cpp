//Union Find using linked-list(array of structure pointed to by iterator)
#include <iostream>
#include <array>
#include <iterator>
using namespace std;
#define MAX 20

class Union_Find{
    struct Node{
        int val;
        int rank;
        Node *parent;
    };
    array<Node,MAX> arr;
    array<Node,MAX>::iterator itr;
    int count;
    public:
        Union_Find(){
            itr = arr.begin();
            count = 0;
        }

        void myMakeSet(int val){
            if(count > MAX){
                cout<<"Overflow.\n";
                return;
            }
            itr->val = val;
            itr->rank = 0;
            itr->parent = itr;
            itr++;count++;
        }

        Node* myFind(int val){
            Node* tmp;
            array<Node,MAX>::iterator ptr = arr.begin();
            int i;
            for(i=0;i<count;i++,ptr++)
                if(ptr->val == val)
                    break;
            if(i >= count) return NULL;
            //path compression code ahead
            tmp = ptr;
            ptr = ptr->parent;
            while(ptr->val != ptr->parent->val)
                ptr = ptr->parent;
            tmp->parent = ptr;
            return tmp;
        }

        void myUnion(int a,int b){
            Node* p1 = myFind(a);
            Node* p2 = myFind(b);
            if(p1 == NULL or p2 == NULL){
                cout<<"Value not found."<<endl;
                return;
            }
            p1 = p1->parent;p2 = p2->parent;
            if(p1->val == p2->val){
                cout<<"Already in the same set.\n";
                return;
            }
            //union by rank code ahead
            if(p1->rank > p2->rank){
                p1->rank++;
                p2->parent = p1;
            }
            else{
                p2->rank++;
                p1->parent = p2;
            }
        }

        void print(){
            array<Node,MAX>::iterator ptr = arr.begin();
            for(int i=0;i<count;i++,ptr++){
                cout<<ptr->val<<"->"<<ptr->parent->val<<" ";
            }
            cout<<endl;
        }
};


int main(){
    Union_Find obj;
    cout<<"Enter the number of sets required: ";
    int n,tmp,tmp2;
    cin>>n;
    cout<<"Enter the sets:\n";
    while(n--){
        cin>>tmp;
        obj.myMakeSet(tmp);
    }
    obj.print();cout<<endl;
    do{
        cout<<"Enter values to be unified: ";
        cin>>tmp>>tmp2;
        obj.myUnion(tmp,tmp2);
        obj.print();
        cout<<"\nContinue?(-1 to exit): ";
        cin>>n;
    }while(n != -1);
    return 0;
}
