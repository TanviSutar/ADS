//Array consist of only 0's, 1's and 2's. Write an algorithm to sort  this array in O(n) time complexity and O(1) Space complexity with only one traversal Asked in : : Amazon, Microsoft, Adobe, WalmartLabs

#include<iostream>
using namespace std;

int main(){
    int arr[] = {0,2,0,0,1,2,0,2,0,0,0,0,2,1,1,2,1,0,2};
    int s = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = s-1;
    int i = 0;
    while(i <= high){
        if(arr[i] == 0){
            arr[i] = arr[low];
            arr[low] = 0;
            while(arr[low] == 0){
                if(low == i) i++;
                low++;
            }
            if(low == i) i--;
            i++;
        }
        else if(arr[i] == 2){
            arr[i] = arr[high];
            arr[high] = 2;
            while(arr[high] == 2) high--; 
        }
        else i++;
    }
    for(int i=0;i<s;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}