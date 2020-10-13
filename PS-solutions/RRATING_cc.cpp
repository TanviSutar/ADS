#include<iostream>
#include<queue>
using namespace std;

void show(priority_queue<int,vector<int>,greater<int>> pq){
    priority_queue<int,vector<int>,greater<int>> q = pq;
    cout<<"minpq: ";
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}
void show2(priority_queue<int> pq){
    priority_queue<int> q = pq;
    cout<<"maxpq: ";
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> minpq;
    priority_queue<int> maxpq;
    int count = 0;
    while(n--){
        int ch;
        cin>>ch;
        if(ch == 1){
            count++;
            int val;
            cin>>val;
            if(count <= 1){
                minpq.push(val);
                continue;
            }
            if(count%3==0 and count > 3){
                if(val > maxpq.top()){
                    minpq.push(val);
                }
                else{
                    minpq.push(maxpq.top());
                    maxpq.pop();
                    maxpq.push(val);
                }
            }
            else{
                if(val > minpq.top()){
                    maxpq.push(minpq.top());
                    minpq.pop();
                    minpq.push(val);
                }
                else{
                    maxpq.push(val);
                }
            }
        }
        else{
            if(!minpq.empty() and count > 2){
                cout<<minpq.top()<<endl;
            }
            else{
                cout<<"No reviews yet"<<endl;
            }
        }
        show(minpq);
        show2(maxpq);
    }
    return 0;
}