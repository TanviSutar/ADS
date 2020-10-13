//showing only maximum sum
#include<iostream>
using namespace std;

int main(){
    cout<<"Enter size of array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements of array:\n";
    for(int i=0;i<n;i++) cin>>arr[i];
    int max = arr[0],curr=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] <= curr+arr[i]) curr += arr[i];
        else curr = arr[i];
        if(max < curr) max = curr;
    }
    cout<<"Maximum sum from sum of all subarray is: "<<max<<endl;
    return 0;
}