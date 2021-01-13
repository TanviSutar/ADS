//We rotate an ascending order sorted array at some point unknown to user. So for instance, 3 4 5 6 7 might become 5 6 7 3 4. Modify binary search algorithm to find an element in the rotated array in O(log n) time and O(1) Space complexity

#include <stdio.h>

// Function to find an element x in a circularly sorted array
int arraySearch(int arr[], int n, int x)
{
	int low = 0, high = n-1,mid;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] == x) return mid;
        if(arr[mid] > arr[0]){//first subsequence
            if(x > arr[0] and x < arr[mid]) high = mid-1;
            else low = mid+1;
        }
        else{//second subsequence
            if(x > arr[mid] and x < arr[n-1]) low = mid+1;
            else high = mid-1;
        }
    }
	return -1;
}

int main(void)
{
	int array1[] = {3,4,5,6,7,8,9,10,1,2};
	int target = 1;

	int n = sizeof(array1)/sizeof(array1[0]);
	int index = arraySearch(array1, n, target);

	if (index != -1)
		printf("Element found at index %d\n", index);
	else
		printf("Element not found in the array\n");
	return 0;
}