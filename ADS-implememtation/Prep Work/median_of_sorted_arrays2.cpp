////There are two sorted array A and B, both of even length say size n. Your task is to find the median of the array formed after merging these arrays in sorted manner in time complexity O(log n) and space complexity O(1).

#include<iostream>
#include<algorithm>
using namespace std;

float find_median(int arr1[], int arr2[], int low1, int high1, int low2, int high2){
    if(low1 >= high1 or low2 >= high2) return -1;
    if((high1-low1)%2 == 0){
        float n1 = arr1[(low1+high1)/2];
        float n2 = arr2[(low2+high2)/2];
        return ((n1+n2)/2);
    }
    int m1 = (low1+high1)/2;
    int m2 = (low2+high2)/2;
    if(arr1[m1] == arr2[m2]) return m1;
    else if(arr1[m1] > arr2[m2])
        return find_median(arr1,arr2,low1,m1+1,m2,high2);
    else 
        return find_median(arr1,arr2,m1,high1,low2,m2+1);
}

int main(){
    int arr1[] = {2,4,5,7,8,9};
    int arr2[] = {1,3,6,10,11,12};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<find_median(arr1,arr2,0,n1-1,0,n2-1)<<endl;
    return 0;
}