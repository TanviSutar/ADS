//Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle Time Complexity O(n2) Space Complexity O(1)

#include <iostream>  
#include <algorithm>
using namespace std;


int findNumberOfTriangles(int arr[], int n) 
{ 
    n = n-1;
    int sum = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int k = j+1;
            while(k <= n and arr[i]+arr[j] > arr[k]) k++;
            sum += (k-1)-j;
        }
    }
    return 0; 
} 
  
//some optimization to reduce number of iterations
int my_findNumberOfTriangles(int arr[], int n) 
{ 
    sort(arr,arr+sizeof(arr)/sizeof(arr[0]));
    n = n-1;
    int sum = 0, prev = 0,i,j,k;
    for(i=0;i<n-1;i++){
        prev = 0;
        j = i+1;
        k = j+1;
        for(j=i+1;j<n;j++){
            if(prev > 0){
                sum += prev -1;
                prev--;
            }
            for(k=j+1;k<=n;k++){
                if(arr[i]+arr[j] > arr[k]){
                    sum++;
                    prev++;
                }
                else break;
            }
        }
    }
    return sum; 
} 

// Driver program to test above functionarr[j+1] 
int main() 
{ 
    int arr[] = {4, 6, 3, 7}; 
    int size = sizeof( arr ) / sizeof( arr[0] ); 
  
    printf("Total number of triangles possible is %d ", 
        my_findNumberOfTriangles( arr, size ) ); 
  
    return 0; 
} 