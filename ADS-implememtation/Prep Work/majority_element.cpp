//Given an array of integer, write an efficient algorithm to find majority number in that array in Time Complexity O(n) and Space Complexity O(1). A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). Can also be solved using hash map, sorting, Binary Tree and Basic BF.

//we use Moore's Voting algorithm to solve this problem in O(n) TC.

#include <iostream>
using namespace std;

// Function to return majority element present in given array
int majorityElement(int arr[], int n)
{
    int me = arr[0],count = 1;
    int i = 1;
    while(i<n){
        if(arr[i] == me) count++;
        else count--;
        if(count == 0){
            me = arr[i];
            count = 1;
        }
        i++;
    }
    //variable me would give the majority element or candidate for majority element. We have to recheck whether the element in the me is actually majority element.
    count = 0;
    for(int i=0;i<n;i++)
        if(arr[i] == me) count++;
    if(count > n/2) return me;
    else return -1;
}
 
int main()
{
    //majority element may be present may not be present. If not present, print -1.
    int arr[] = {1, 3, 3, 1, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout<<"Majority element is: "<<majorityElement(arr, n)<<endl;
 
    return 0;
}