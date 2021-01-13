//One array of integers is given as an input ,which is initially increasing and then decreasing or it can be only increasing or decreasing , you need to find the maximum value in the array in O(n) Time complexity and O(1) Space Complexity Asked in: Amazon, Microsoft, Uber

#include <bits/stdc++.h> 
using namespace std; 

int maxVal(int arr[],int low,int high){
  int mid = (low+high)/2;
  if(mid-1 < 0 and arr[mid+1] < arr[mid]) return arr[mid];
  else if(mid+1 > high and arr[mid-1] < arr[mid]) return arr[mid];
  else if(arr[mid-1] < arr[mid] and arr[mid+1] < arr[mid]) return arr[mid];
  else if(arr[mid-1] < arr[mid] and arr[mid+1] > arr[mid]) 
    return maxVal(arr,mid+1,high);
  else
    return maxVal(arr,low,mid-1);
}

int main()  
{  
    int array1[] = {55,45,34,32,21,1,0};  
    int n = sizeof(array1)/sizeof(array1[0]);  
    cout << "The maximum Value  is " << maxVal(array1, 0, n-1);  
    return 0;  
} 