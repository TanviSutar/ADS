//Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that ll array elements are distinct. Time Complexity O(n) and Space Complexity O(1) Asked in :Vmware, SapLabs, WalmartLabs


#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = low,i = low;
    while(i < high){
        if(arr[i] < arr[high]){
            int tmp = arr[pivot];
            arr[pivot] = arr[i];
            arr[i] = tmp;
            pivot++;
        }
        i++;
    }
    int tmp = arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = tmp;
    return pivot;
}

int quickSelect(int arr[],int low,int high,int k){
    if(low > high) return -1;
    int pivot = partition(arr,low,high);
    k = k-1;
    if(pivot == k) return arr[k];
    if(k > pivot) return quickSelect(arr,pivot+1,high,k+1);
    else return quickSelect(arr,low,pivot-1,k+1);
}


int main(){
    int array1[] = {5, -8, 10, 37, 101, 2, 9}; 
    int n = sizeof(array1)/sizeof(array1[0]), k = 3; 
    cout << "K'th smallest element is " << quickSelect(array1, 0, n-1, k)<<endl; 
    return 0;
}