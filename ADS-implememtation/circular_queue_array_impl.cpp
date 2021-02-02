#include<iostream>
#define MAX 4
using namespace std;

class Queue{
    private:
        int front, rear;
        int que[MAX];
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool isFull(){
            if((front == 0 and rear == MAX-1) or (front == rear+1)) return true;
            return false;
        }
        bool isEmpty(){
            if(front == -1) return true;
            return false;
        }
        void enqueue(int val){
            if(isFull()){
                cout<<"Overflow.\n";
                return;
            }
            rear = (rear+1)%MAX;
            que[rear] = val;
            if(front == -1) front++;
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Underflow.\n";
                return -1;
            }
            int  tmp = que[front];
            front = (front+1)%MAX;
            return tmp;
        }
        int print(){
            for(int i=0;i<=MAX;i++) cout<<que[i]<<" ";cout<<endl;
        }
};

int main(){
    Queue q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(2);
    q.print();
    cout<<q.isFull();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.isFull();
    return 0;
}