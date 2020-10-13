//length of longest non-decreasing subarray
#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0;i<n;i++) cin>>arr[i];
    int max = 1, curr = 1;
    for(int i=1;i<n;i++){
        if(arr[i] >= arr[i-1]) curr++;
        else curr = 1;
        if(curr > max) max = curr;
    }
    cout<<"Length of longest non-decreasing subarray: "<<max<<endl;
    return 0;
}