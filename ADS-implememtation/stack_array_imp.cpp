#include<iostream>
#define MAX 20
using namespace std;


class Stack{
    private:
        int top;
        int stk[MAX];
    public:
        Stack(){
            top = -1;
        }
        bool isFull(){
            if(top == MAX-1) return true;
            else return false;
        }
        bool isEmpty(){
            if(top == -1) return true;
            else return false;
        }
        void push(int val){
            if(isFull()){
                cout<<"Overflow.\n";
                return;
            }
            stk[++top] = val;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Underflow.\n";
                return -1;
            }
            int tmp = stk[top];
            top--;
            return tmp;
        }
        int topElem(){
            return stk[top];
        }
};

int main(){
    Stack stk;
    stk.push(7);
    stk.push(3);
    stk.push(9);
    stk.push(8);
    cout<<stk.topElem()<<endl;
    stk.pop();
    cout<<stk.topElem()<<endl;
    return 0;
}