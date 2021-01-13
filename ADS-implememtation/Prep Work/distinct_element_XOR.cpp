//Given an array where every element occurs two times, except one element which occurs only once. Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space Asked in : Flipkart, Amazon, PayTm

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 1, 5, 5, 3, 2, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = arr[0];
    for(int i=1;i<n;i++){
        result = result ^ arr[i];
    }
    cout<<result<<" is the element that occurs once."<<endl;
    return 0;
}