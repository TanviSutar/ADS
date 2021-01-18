//

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array
int maxIndexDiff(int arr[], int n) 
{ 
    
    // Your code here
    int rmax[n], lmin[n];
    rmax[n-1] = n-1; 
    lmin[0] = 0;
    
    for(int i=1;i<n;i++) {
        if(arr[lmin[i-1]] < arr[i])
            lmin[i] = lmin[i-1];
        else
            lmin[i] = i;
    }
      
    for(int i=n-2;i>=0;i--){
        if(arr[rmax[i+1]] > arr[i])
            rmax[i] = rmax[i+1];
        else
            rmax[i] = i;
    }
        
    int maxdiff = 0;
    int i=0,j=0;
    while(j < n and i < n){
        if(arr[rmax[j]] >= arr[lmin[i]]){
            maxdiff = std::max(maxdiff,rmax[j]-lmin[i]);
            j++;
        }
        else i++;
    }
    return maxdiff;
}

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        //calling maxIndexDiff() function
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends