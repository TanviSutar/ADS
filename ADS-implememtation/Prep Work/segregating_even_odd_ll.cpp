//Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same. The time complexity mush not increase more than O(n).

#include<iostream>
using namespace std;

class LinkedList{
    class Node{
        public:
            int data;
            Node *next;
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
    };
    Node *head;
    public:
        LinkedList(){
            head = NULL;
        }
        void insert(int data){
            Node *node = new Node(data);
            if(head == NULL){
                head = node;
                return;
            }
            Node *tmp = head;
            while(tmp->next != NULL) tmp = tmp->next;
            tmp->next = node;
            tmp = NULL;
            delete tmp;
        }
        void segregate(){
            if(head == NULL) return;
            Node *tmp = head;
            while(tmp->next != NULL) tmp = tmp->next;
            Node *t = head, *ptr = tmp, *prev = t;
            int count = 0;
            while(t != ptr and t != NULL){
                if(t->data&1){
                    cout<<t->data<<endl;
                    if(t == head) head = head->next;
                    else prev->next = t->next;
                    tmp->next = t;
                    t = t->next;
                    tmp = tmp->next;
                    tmp->next = NULL;
                }
                else {
                    prev = t;
                    t = t->next;
                }
                if(count == 0 and ptr->next != NULL){
                    count++;
                    ptr = ptr->next;
                }
            }
        }
        void traverse(){
            Node *tmp = head;
            while(tmp != NULL){
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }
};

int main(){
    LinkedList ll;
    ll.insert(4);
    ll.insert(1);
    ll.insert(5);
    ll.insert(8);
    ll.insert(6);
    ll.insert(7);
    ll.insert(3);
    ll.insert(2);
    ll.insert(9);
    ll.insert(11);
    ll.segregate();
    ll.traverse();
    return 0;
}

