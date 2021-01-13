//Array of length n having integers 1 to n with some elements being repeated. Count frequencies of all elements from 1 to n in Time Complexity O(n) and Space Complexity O(1) Asked in : : PayTm, VmWa

#include<bits/stdc++.h>
using namespace std;
 
// Function to find counts of all elements present in
// arr[0..n-1]. The array elements must be range from
// 1 to n
void findfrequency(int arr[],int n)
{
    // Subtract 1 from every element so that the elements
    // become in range from 0 to n-1
    for (int j =0; j<n; j++)
        arr[j] = arr[j]-1;
 
    // Use every element arr[i] as index and add 'n' to
    // element present at arr[i]%n to keep track of count of
    // occurrences of arr[i]
    for (int i=0; i<n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;
 
    // To print counts, simply print the number of times n
    // was added at index corresponding to every element
    for (int i =0; i<n; i++)
        cout << i + 1 << " ->  " << arr[i]/n << endl;
}

void my_findfrequency(int arr[],int n){
    for(int i=0;i<n;i++) arr[i]--;
    for(int i=0;i<n;i++){
        if(arr[i] < n){
            arr[arr[i]] += n;
        }
        else{
            arr[(arr[i]%n)] += n;
        }
    }
    for(int i=0;i<n;i++) cout<<i+1<<" -> "<<arr[i]/n<<endl;
}
 

int main()
{
    int arr[] = {2, 3, 3, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    my_findfrequency(arr,n);
    return 0;
}