//Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array in Time Complexity : O(n) and Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct(int[], int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        vector <int> result = countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends



vector <int> countDistinct (int arr[], int n, int k)
{
    //code here.
    vector<int> vec;
    unordered_map<int,int> map;
    if(n < k) return vec;//number of elements in the array is less than window size
    
    for(int i=0;i<k-1;i++){
        if(map.find(arr[i]) != map.end()) map[arr[i]]++;
        else map[arr[i]] = 1;
    }
    
    for(int ptr=0,i=k-1;i<n;i++,ptr++){
        if(map.find(arr[i]) != map.end()) map[arr[i]]++;
        else map[arr[i]] = 1;
        vec.push_back(map.size());
        if(map[arr[ptr]] > 1) map[arr[ptr]]--;
        else map.erase(arr[ptr]);
    }
    return vec;
}