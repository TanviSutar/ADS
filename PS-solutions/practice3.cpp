#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        if(!(n&(n-1))){
            cout<<-1<<endl;
            continue;
        }
        if(n == 3) cout<<2<<" "<<3<<" "<<1<<endl;
        else if(n == 5) cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<endl;   
        else{
            cout<<2<<" "<<3<<" "<<1<<" "<<5<<" "<<4<<" ";
            int i = 6;
            while(i<=n){
                if(!(i&(i-1))){
                    cout<<(i+1)<<" "<<i<<" ";
                    i += 2;
                    continue;
                }
                cout<<i<<" ";
                i++;
            }
            cout<<endl;
        }
    }
    return 0;
}