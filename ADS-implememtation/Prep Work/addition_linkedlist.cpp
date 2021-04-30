//Given two numbers represented by two linked lists, write a function that returns the sum list. The sum list is linked list representation of the addition of two input numbers. It is not allowed to modify the lists. Also, not allowed to use explicit extra space
// Eg: 
// ll1: 2->4->3->2
// ll2: 6->8->5
// o/p ll: 3->1->1->7

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
        LinkedList(Node *h){
            head = h;
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
        void traverse(){
            Node *tmp = head;
            while(tmp != NULL){
                cout<<tmp->data<<"->";
                tmp = tmp->next;
            }
            cout<<"NULL"<<endl;
        }   
        void traverse(Node *head){
            Node *tmp = head;
            while(tmp != NULL){
                cout<<tmp->data<<"->";
                tmp = tmp->next;
            }
            cout<<endl;
        } 
        Node* rethead(){
            return head;
        }   
        Node* add(Node *h2){//function using extra space
            Node *newhead = NULL, *newtail = NULL;
            Node *h1 = head, *tmp = head->next, *tmp2 = NULL;
            h1->next = NULL;
            while(tmp != NULL){// reverse the first list
                tmp2 = tmp->next;
                tmp->next = h1;
                h1 = tmp;
                tmp = tmp2;
            }
            //traverse(h1);
            tmp = h2->next;
            h2->next = NULL;
            while(tmp != NULL){// reverse the second list
                if(tmp != NULL) tmp2 = tmp->next;
                tmp->next = h2;
                h2 = tmp;
                tmp = tmp2;
            }
            //traverse(h2);
            int carry = 0;
            while(h1 != NULL and h2 != NULL){
                int sum = h1->data + h2->data + carry;
                if(sum < 10) {
                    tmp = new Node(sum);
                    carry = 0;
                }
                else{
                    tmp = new Node((sum%10));
                    carry = 1;
                }
                if(newhead == NULL) {
                    newhead = newtail = tmp;
                }
                else{
                    newtail->next = tmp;
                    newtail = newtail->next;
                }
                h1 = h1->next;
                h2 = h2->next;
                //cout<<1<<endl;
            }
            while(h1){
                int sum = h1->data + carry;
                if(sum < 10){
                    tmp = new Node(sum);
                    carry = 0;
                }
                else{
                    tmp = new Node((sum%10));
                    carry = 1;
                }
                newtail->next = tmp;
                newtail = newtail->next;
                h1 = h1->next;
            }
            while(h2){
                int sum = h2->data + carry;
                if(sum < 10){
                    tmp = new Node(sum);
                    carry = 0;
                }
                else{
                    tmp = new Node((sum%10));
                    carry = 1;
                }
                newtail->next = tmp;
                newtail = newtail->next;
                h2 = h2->next;
                //cout<<3<<endl;
            }
            if(carry){
                newtail->next = new Node(1);
                newtail = newtail->next;
            }
            tmp = newhead->next;
            newhead->next = NULL;
            while(tmp != NULL){// reverse the first list
                tmp2 = tmp->next;
                tmp->next = newhead;
                newhead = tmp;
                tmp = tmp2;
            }
            return newhead;
        }
};

int main(){
    LinkedList ll1, ll2;
    ll1.insert(7);
    ll1.insert(9);
    ll1.insert(4);
    ll2.insert(2);
    ll2.insert(3);
    ll2.insert(3);
    //ll2.insert(5);
    LinkedList ll(ll1.add(ll2.rethead()));
    ll.traverse();
    return 0;
}

//add function using no extra space
/*Node* add(Node *h2){
    Node *newhead = NULL, *newtail = NULL;
    Node *h1 = head, *tmp = head->next, *tmp2 = NULL;
    h1->next = NULL;
    int cnt1 = 0;
    while(tmp != NULL){// reverse the first list
        cnt1++;
        tmp2 = tmp->next;
        tmp->next = h1;
        h1 = tmp;
        tmp = tmp2;
    }
    //traverse(h1);
    tmp = h2->next;
    h2->next = NULL;
    int cnt2 = 0;
    while(tmp != NULL){// reverse the second list
        cnt2++;
        if(tmp != NULL) tmp2 = tmp->next;
        tmp->next = h2;
        h2 = tmp;
        tmp = tmp2;
    }
    //traverse(h2);
    if(cnt1 > cnt2) newhead = newtail = h1;
    else newhead = newtail = h2;
    int carry = 0;
    while(h1 != NULL and h2 != NULL){
        int sum = h1->data + h2->data + carry;
        if(sum < 10) {
            //tmp = new Node(sum);
            newtail->data = sum;
            newtail = newtail->next;
            carry = 0;
        }
        else{
            //tmp = new Node((sum%10));
            newtail->data = sum%10;
            newtail = newtail->next;
            carry = 1;
        }
        h1 = h1->next;
        h2 = h2->next;
        //cout<<1<<endl;
    }
    while(h1){
        int sum = h1->data + carry;
        if(sum < 10){
            newtail->data = sum;
            carry = 0;
        }
        else{
            newtail->data = sum%10;
            carry = 1;
        }
        newtail = newtail->next;
        h1 = h1->next;
    }
    while(h2){
        int sum = h2->data + carry;
        if(sum < 10){
            newtail->data = sum;
            carry = 0;
        }
        else{
            newtail->data = sum%10;
            carry = 1;
        }
        newtail = newtail->next;
        h2 = h2->next;
        //cout<<3<<endl;
    }
    if(carry){
        newtail->next = new Node(1);
        newtail = newtail->next;
    }
    tmp = newhead->next;
    newhead->next = NULL;
    while(tmp != NULL){// reverse the first list
        tmp2 = tmp->next;
        tmp->next = newhead;
        newhead = tmp;
        tmp = tmp2;
    }
    return newhead;
}*/