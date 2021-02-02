//Given a linked list where every node represents a linked list and contains two pointers of its type: 
//(i) Pointer to next node in the main list (we call it ‘right’ pointer in below code)
//(ii) Pointer to a linked list where this node is head (we call it ‘down’ pointer in below code).
//All linked lists are sorted. Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted.

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class MLinkedList{
    class Node{
        public:
            int data;
            Node *next, *child;
            Node(int data){
                this->data = data;
                this->next = this->child = NULL;
            }
    };
    void insert(Node* parent, int ind, int data){
        if(data == -1) return;
        Node *node = new Node(data);
        if(!ind){//add child node
            node->child = parent->child;
            parent->child = node;
        }
        else{//add neighbour node
            node->next = parent->next;
            parent->next = node;
        }
        int tmp1, tmp2;
        cout<<"Enter child of "<<node->data<<": ";
        cin>>tmp1;
        insert(node, 0, tmp1);
        cout<<"Enter next of "<<node->data<<": ";
        cin>>tmp2;
        insert(node, 1, tmp2);
    }
    Node *head;
    public:
        void insert_util(){
            cout<<"Enter data of multiple linked list:\nEnter root node:  ";
            int tmp, tmp1, tmp2; 
            cin>>tmp;
            Node *node = new Node(tmp);
            if(tmp != -1){
                head = node;
            }
            cout<<"Enter child of "<<tmp<<": ";
            cin>>tmp1;
            insert(head, 0, tmp1);
            cout<<"Enter next of "<<tmp<<": ";
            cin>>tmp2;
            insert(head, 1, tmp2);
        }
        void traversal(){
            Node *tmp = head;
            while(tmp != NULL){
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
            cout<<endl;
        }
        void traversal(Node *h){
            Node *tmp = h;
            while(tmp != NULL){
                cout<<tmp->data<<" ";
                tmp = tmp->child;
            }
            cout<<endl;
        }
        Node* sorted_merge(Node *heada, Node *headb){
            if(heada == NULL) return headb;
            if(headb == NULL) return heada;
            Node *tmp1, *tmp2, *tmp;
            if(heada->data < headb->data){
                tmp = heada;
                tmp1 = heada->child;
                tmp2 = headb;
            }
            else{
                tmp1 = heada;
                heada = headb;
                tmp = heada;
                tmp2 = headb->child;
            }
            while(tmp1 != NULL and tmp2 != NULL){
                if(tmp1->data < tmp2->data){
                    tmp->child = tmp1;
                    tmp1 = tmp1->child;
                }
                else{
                    tmp->child = tmp2;
                    tmp2 = tmp2->child;
                }
                tmp = tmp->child;
            }
            while(tmp1 != NULL){
                tmp->child = tmp1;
                tmp1 = tmp1->child;
                tmp = tmp->child;
            }
            while(tmp2 != NULL){
                tmp->child = tmp2;
                tmp2 = tmp2->child;
                tmp = tmp->child;
            }
            tmp = tmp1 = tmp2 = NULL;
            delete tmp, tmp1, tmp2;
            return heada;
        }
        Node *flatten(Node *root)
        {
            Node *head = NULL, *i = root;
            while(i != NULL){
                head = sorted_merge(i, head);
                i = i->next;
            }
            return head;
        }
        Node* getHead(){
            return head;
        }
};

int main(){
    MLinkedList mll;
    mll.insert_util();
    cout<<"Traversal after flattening:";
    mll.traversal(mll.flatten(mll.getHead()));
    return 0;
}