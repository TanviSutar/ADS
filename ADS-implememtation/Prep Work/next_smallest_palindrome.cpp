//Find next smallest palindrome larger than this given number Asked in: Flipkart, Oracle

// { Driver Code Starts
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

long long getNextEven(string x);

int main() 
{
	int t;
	cin >> t;
	while(t--){
    	string x;
    	cin >> x;
        cout<< getNextEven(x) <<endl;
	}
	
	return 0;
}// } Driver Code Ends


long long convert(int arr[], int n){
    long long l = arr[0];
    for(int i=1;i<n;i++){
        l = l*10 + arr[i];
    }
    return l;
}

long long getNextEven(string x)
{
    int n = x.size();
    int arr[n];
    
    for(int i=0;i<n;i++){
        arr[i] = x.at(i) - '0';
    }
        
    int mid = -1,rght = n/2, lft = (n/2)-1;
    if(n&1) {
        mid = n/2;
        rght = n/2 +1;
    }
    
    int i = lft, j = rght;
    while(i >= 0 and arr[i] == arr[j]){
        i--;
        j++;
    }
    //if(i < 0) return convert(arr,n);//already a palindrome
    
    if(i >= 0 and arr[i] > arr[j]){//case 1
        int dummy = lft;
        for(int k=rght;k<n;k++,dummy--){
            arr[k] = arr[dummy];
        }
        return convert(arr,n);
    }
    
    if(mid != -1) i = mid;
    else i = lft;
    
    while(arr[i] == 9 and i >= 0) {
        i--;
    }
    
    if(i < 0){
        int arr2[n+1];
        n = n+1;
        arr2[0] = 1;
        j = 1;
        while(j < n-1) {
            arr2[j] = 0;
            j++;
        }
        arr2[n-1] = 1;
        return convert(arr2,n);
    }
    
    arr[i] = arr[i]+1;
    
    for(int k=i+1;k<n-1-i;k++) arr[k] = 0;

    for(j = n-1-i; j < n;j++,i--) arr[j] = arr[i];
    
    return convert(arr,n);
}