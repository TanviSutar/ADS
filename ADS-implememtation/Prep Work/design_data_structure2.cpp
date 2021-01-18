//You need to design a data structure which support below operation in O(1) time complexity 1) Insert() which adds an element to the data structure 2) remove() which removes an element from the data structure 3) findMiddle() which will return middle element 4) deleteMiddle() which will delete the middle element. Insert(1) --- O(1) time complexity Insert(2) Insert(3) findMiddle() – 2 in O(1) time complexity Insert(4) Insert(5) deleteMiddle() - remove 3 in O(1) time complexity remove(5) – in O(1) time complexity

#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

class DLL{
    node *head;
    node *mid;
    bool flag;
    int size;

    public:
        DLL(){
            head = NULL;
            mid = NULL;
            size = 0;
        }  

        void insert(int val){
            node *tmp = new node;
            tmp->data = val;
            tmp->prev = tmp->next = NULL;
            if(head == NULL){
                head = tmp;
                mid = tmp;
                size++;
                return;
            }
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
            size++;
            if(size%2 == 0) mid = mid->prev;
        }

        void mydelete(){
            node *tmp = head;
            if(size == 1){
                head = NULL;
                size--;
                delete tmp;
                return;
            }
            head = head->next;
            head->prev = NULL;
            size--;
            if(size%2 != 0) mid = mid->next;
            delete tmp;
        }

        void findMid(){
            cout<<mid->data<<endl;
        }

        void deleteMid(){
            node *tmp = mid;
            if(size == 1){
                mid = head = NULL;
                delete tmp;
                return;
            }
            if(mid->prev != NULL) mid->prev->next = mid->next;
            if(mid->next != NULL) mid->next->prev = mid->prev;
            if(size%2 == 0) mid = mid->next;
            else mid = mid->prev;
        }

        void print(){
            node *tmp = head;
            while(tmp != NULL){
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
        }
};

int main(){
    DLL obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.print();
    obj.findMid();
    obj.mydelete();
    obj.findMid();
    obj.insert(6);
    obj.insert(8);
    obj.findMid();
    obj.deleteMid();
    obj.findMid();
    return 0;
}