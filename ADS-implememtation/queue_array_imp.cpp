#include<iostream>
#define MAX 20
using namespace std;

class Queue{
    private:    
        int front,rear;
        int que[MAX];
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        bool isFull(){
            if(rear == MAX-1) return true;
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
            que[++rear] = val;
            if(front == -1) front++; 
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Underflow.\n";
                return -1;
            }
            int tmp = que[front];
            front++;
            if(rear < front) rear = front = -1;
            return tmp;
        }
        int frontElem(){
            return que[front];
        }
};

int main(){
    Queue q;
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);
    q.dequeue();
    cout<<q.frontElem()<<endl;
    q.dequeue();
    cout<<q.frontElem()<<endl;
    return 0;
}