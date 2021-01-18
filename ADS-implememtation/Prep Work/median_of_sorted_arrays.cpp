//There are two sorted array A and B, both of odd length say size n. Your task is to find the median of the array formed after merging these arrays in sorted manner in time complexity O(log n) and space complexity O(1).

#include<iostream>
#include<algorithm>
using namespace std;

//D&C approach used
float find_median(int arr1[], int arr2[], int low1, int high1, int low2, int high2){
    if(low1 >= high1 or low2 >= high2) return -1;
    if(high1 == low1+1){
        float n1 = std::max(arr1[low1],arr2[low2]);
        float n2 = std::min(arr1[high1],arr2[high2]);
        return (n1+n2)/2;
    }
    int m1 = (low1+high1)/2;
    int m2 = (low2+high2)/2;
    if(arr1[m1] == arr2[m2]) return m1;
    else if(arr1[m1] > arr2[m2]) 
        return find_median(arr1,arr2,low1,m1,m2,high2);
    else 
        return find_median(arr1,arr2,m1,high1,low2,m2);
}

int main(){
    int arr1[] = {1,2};
    int arr2[] = {3,4};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout<<find_median(arr1,arr2,0,n-1,0,n-1);
    return 0;
}