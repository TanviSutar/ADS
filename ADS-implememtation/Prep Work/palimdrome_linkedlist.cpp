//Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

/* Link list Node */
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    int count = 0;
    Node *tmp = head;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    if(count == 1) return true;
    if(count == 2){
        if(head->data == head->next->data) return true;
        else return false;
    } 
    
    Node *curr = head->next, *prev = head;
    for(int i=1;i<(count/2);i++){
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    head->next = NULL;
    if(count&1) curr = curr->next;
    //cout<<prev->data<<" "<<curr->data<<endl;
    while(prev != NULL and curr != NULL and prev->data == curr->data) {
        prev = prev->next;
        curr = curr->next;
    }
    if(prev == NULL and curr == NULL) return true;
    return false;
}
