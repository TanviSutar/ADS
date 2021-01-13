//We have an array, we have to find an element before which all elements are less than it, and after which all are greater than it. Finally, return the index of the element, if there is no such element, then return -1: Time complexity O(n) and Space Complexity O(n)
#include <bits/stdc++.h> 
using namespace std; 
  
int findElement(int arr[], int n) 
{ 
    //Write your code here 
    return -1; 
} 
  
int my_findElement(int arr[], int n){
    int max = 0;
    int min = 100000000;
    int maxarr[n],minarr[n];
    for(int i=0,j=n-1;i<n;i++,j--){
        if(arr[i] > max) max = arr[i];
        maxarr[i] = max;
        if(arr[j] < min) min = arr[j];
        minarr[j] = min;
    }
    /*for(int i=0;i<n;i++) cout<<maxarr[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<minarr[i]<<" ";*/
    for(int i=0;i<n;i++){
        if(arr[i] == maxarr[i] and arr[i] == minarr[i]) return i;
    }
    return -1;
}

int main() 
{ 
    int arr[] = {6,2,5,4,7,9,11,8,10}; 
    int n = sizeof arr / sizeof arr[0]; 
    cout << "Index of the element is " << my_findElement(arr, n); 
    return 0; 
} 