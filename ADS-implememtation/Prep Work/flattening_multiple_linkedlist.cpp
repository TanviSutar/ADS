//Given a linked list where in addition to the next pointer, each node has a child pointer, which may or may not point to a separate list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in below figure.You are given the head of the first level of the list. Flatten the list so that all the nodes appear in a single-level linked list. You need to flatten the list in way that all nodes at first level should come first, then nodes of second level, and so on.

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
    Node *head;
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
        void BFS(){//breadth first traversal
            Node *tmp = head;
            cout<<"BFS Traversal: ";
            if(head->next == NULL and head->child == NULL){
                cout<<head->data<<endl;
                return;
            }
            queue<Node*> q;
            while(true){
                cout<<tmp->data<<" ";
                if(tmp->child) q.push(tmp->child);
                if(tmp->next == NULL and q.empty()) break;
                if(tmp->next) tmp = tmp->next;
                else{
                    tmp = q.front();
                    q.pop();
                }
            }
            cout<<endl;
        }
        void DFS_util(){
            cout<<"DFS Traversal: ";
            DFS(head);
            cout<<endl;
        }
        void DFS(Node *tmp){//depth first traversal
            if(tmp == NULL) return;
            cout<<tmp->data<<" ";
            DFS(tmp->child);
            DFS(tmp->next);
        }
        void BFS_flattening(){//level-wise flattening
            if(head == NULL) return;
            Node *tmp = head;
            queue<Node*> q;
            while(true){
                if(tmp->child) q.push(tmp->child);
                if(tmp->next == NULL and q.empty()) break;
                if(tmp->next) tmp = tmp->next;
                else{
                    tmp->next = q.front();
                    tmp = q.front();
                    q.pop();
                }
            }
        }
        void DFS_flattening(){//depth-wise flattening
            Node *tmp = head;
            stack<Node*> stk; 
            while(true){
                if(tmp->next) stk.push(tmp->next);
                if(tmp->child == NULL and stk.empty()) break;
                if(tmp->child){
                    tmp->next = tmp->child;
                    tmp = tmp->next;
                }
                else{
                    tmp->next = stk.top();
                    tmp = tmp->next;
                    stk.pop();
                }
            }  
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
};

int main(){
    MLinkedList mll;
    mll.insert_util();
    mll.BFS();
    mll.DFS_util();
    cout<<"1. Level-wise flattening\n2. Depth-wise flattening\nEnter your choice: ";
    int ch;
    cin>>ch;
    if(ch == 1){
        cout<<"Traversal after level-wise flattening: ";
        mll.BFS_flattening();
        mll.traversal();
    }
    else if(ch == 2){
        cout<<"Traversal after depth-wise flattening: ";
        mll.DFS_flattening();
        mll.traversal();
    }
    else{
        cout<<"Invalid option.\n";
    }
    return 0;
}