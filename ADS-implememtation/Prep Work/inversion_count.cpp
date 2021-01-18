// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long merge(long long arr[], long long low, long long high){
    long long cnt = 0;
    long long mid = (low+high)/2;
    long long nl = mid-low+1, nr = high - mid;
    long long lft[nl], rght[nr];
    for(int i=low;i<=mid;i++) lft[i-low] = arr[i];
    for(int i=mid+1;i<=high;i++) rght[i-mid-1] = arr[i];
    int i=0, j=0;
    while(i < nl and j < nr){
        if(lft[i] > rght[j]){
            arr[low] = lft[i];
            cnt += mid-i+1;
            i++;
        }
        else{
            arr[low] = rght[j];
            j++;
        }
        low++;
    }
    while(i < nl){
        arr[low] = lft[i];
        i++; low++;
    }
    while(j < nr){
        arr[low] = rght[j];
        j++; low++;
    }
    return cnt;
}

long long mergeSort(long long arr[], long long low, long long high){
    if(low >= high) return 0;
    long long mid = (low+high)/2;
    long long cnt = 0;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,high);
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr,0,N-1);
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends