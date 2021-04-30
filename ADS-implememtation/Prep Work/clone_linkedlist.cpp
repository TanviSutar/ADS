//You are given a double Link List with one reference of each node pointing to the next node just like in a single link list. The second reference however can point to any node in the list and not just the previous node.Write a program in O(n) time which will create a copy of this list Asked in : Myntra, Expdia, Microsoft, J P Morgan

#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *rndm;
        Node(int data){
            this->data = data;
            this->next = this->rndm = NULL;
        }
        Node(){
            this->next = this->rndm = NULL;
        }
};

void traverse(Node *head){
    Node *tmp = head;
    while(tmp != NULL){
        cout<<tmp->data<<" ";
        if(tmp->rndm) cout<<tmp->rndm->data<<endl;
        else cout<<"NULL"<<endl;
        tmp = tmp->next;
    }
}

void insert(Node **head){
    cout<<"Enter the linked list elements sequencially:\n";
    cout<<"Enter -1 to end:\n";
    int ch;
    Node *prev = NULL;
    unordered_map<int,Node*> map;
    do{
        cin>>ch;
        if(ch != -1){
            Node *n = new Node(ch);
            map[n->data] = n;
            if(prev == NULL) *head = n;
            else prev->next = n;
            prev = n;
        }
    }while(ch != -1);
    cout<<"Enter the random links of the elements sequencially:\n";
    cout<<"Enter -1 to skip for a particular element:\n";
    Node *tmp = *head;
    while(tmp != NULL){
        cin>>ch;
        if(ch == -1){
            tmp = tmp->next;
            continue;
        }
        if(map.find(ch) != map.end()) tmp->rndm = map[ch];
        else tmp->rndm = NULL;
        tmp = tmp->next;
    }
}

void clone(Node *head, Node **copy){// using O(n) space i.e. using map
    Node *tmp = head, *prev = NULL, *node, *head2;
    unordered_map<int, Node*> map;
    
    while(tmp != NULL){
        if(map.find(tmp->data) != map.end())
            node = map[tmp->data];
        else
            node = new Node(tmp->data);
            
        if(prev != NULL) prev->next = node;
        else head2 = node;
        
        map[node->data] = node;
        
        if(tmp->rndm){
            if(map.find(tmp->rndm->data) == map.end()){
                Node *n = new Node(tmp->rndm->data);
                node->rndm = n;
                map[n->data] = n;
            }
            else{
                node->rndm = map[tmp->rndm->data];
            }
        }
        
        prev = node;
        tmp = tmp->next;
    }
    *copy = head2;
}

void copyList(Node *head, Node **second) {// using no extra space i.e. O(1)
    Node *first = head, *fptr = head, *sptr;
    Node *prev = NULL, *nxt = first->next;
    while(fptr != NULL){
        Node *node = new Node(fptr->data);
        if(prev == NULL) *second = node;
        else prev->next = node;
        prev = node;
        node->rndm = fptr;
        nxt = fptr->next;
        fptr->next = node;
        fptr = nxt;
    }
    
    sptr = *second; 
    
    while(sptr != NULL){
        if(sptr->rndm and sptr->rndm->rndm)
            sptr->rndm = sptr->rndm->rndm->next;
        else sptr->rndm = NULL;
        sptr = sptr->next;
    }
}

int main(){
    Node *head;
    insert(&head);
    Node *copy = NULL;
    copyList(head, &copy);
    traverse(copy);
    return 0;
}