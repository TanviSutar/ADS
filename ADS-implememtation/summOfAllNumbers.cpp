#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    cout<<"Sum of all numbers from 1 to "<<n<<": "<<(n*(n+1))/2<<endl;
    return 0;
}