//Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
//Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

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
        void traverse(){
            Node *tmp = head;
            while(tmp != NULL){
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }
        void traverse(Node *head){
            Node *tmp = head;
            while(tmp != NULL){
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }
        Node* mergeSort(Node* head) {
            if(head == NULL or head->next == NULL) return head;
            Node *first = head, *last = head, *middle = head, *second;
            while(last->next != NULL and last->next->next != NULL){
                middle = middle->next;
                last = last->next->next;
            }
            second = middle->next;
            middle->next = NULL;
            Node *head1 = mergeSort(first);
            Node *head2 = mergeSort(second);
            return merge(head1, head2);
        }
        Node* merge(Node *head1, Node* head2){
            if(head1 == NULL) return head2;
            if(head2 == NULL) return head1;
            Node *head, *h;
            if(head1->data < head2->data){
                h = head1;
                head1 = head1->next;
            }
            else{
                h = head2;
                head2 = head2->next;
            }
            head = h;
            while(head1 != NULL and head2 != NULL){
                if(head1->data < head2->data){
                    head->next = head1;
                    head1 = head1->next;
                }
                else{
                    head->next = head2;
                    head2 = head2->next;
                }
                head = head->next;
            }
            while(head1){
                head->next = head1;
                head1 = head1->next;
                head = head->next;
            }
            while(head2){
                head->next = head2;
                head2 = head2->next;
                head = head->next;
            }
            return h;
        }
        void mysort(){
            head = mergeSort(head);
        }       
};

int main(){
    LinkedList ll;
    ll.insert(4);
    ll.insert(2);
    ll.insert(8);
    ll.insert(5);
    ll.insert(1);
    ll.insert(6);
    ll.mysort();
    cout<<"After sorting: ";
    ll.traverse();
    return 0;
}