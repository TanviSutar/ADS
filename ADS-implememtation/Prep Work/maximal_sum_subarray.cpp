//Find the contiguous subarray within an array[] of length N which has the largest sum in Time Complexity O(n) and Space Complexity O(1) - Kadane Algorithm

#include <iostream>
using namespace std;

// Function to find contiguous sub-array with the largest sum
// in given set of integers
int kadane(int arr[], int n)
{
  //Write your code here
    int max = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(sum+arr[i] > arr[i])
            sum += arr[i];
        else sum = arr[i];
        if(sum > max) max = sum;
    }
    return max;
}

int main()
{
	int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "The sum of contiguous sub-array with the largest sum is " <<
			kadane(arr, n)<<endl;

	return 0;
}