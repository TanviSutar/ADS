//Given an array in which all numbers except two are repeated once. (i.e. we have 2n+2 numbers and n numbers are occurring twice and the remaining two have occurred once). Find those two numbers in the most efficient way

#include <iostream>
#include <math.h>
using namespace std;


pair<int, int> findDuplicates(int arr[], int n)
{
    int res = 0;
    for(int j=0;j<n;j++) res = res ^ arr[j];

    int i=1;
    while(i&res != 1) i = i<<1;

    res = 0;
    for(int j=0;j<n;j++) 
        if(arr[j]&i)
            res = res ^ arr[j];

    pair<int,int> p;
    p.first = res;

    res = 0;
    for(int j=0;j<n;j++) 
        if(!(arr[j]&i))
            res = res ^ arr[j];

    p.second = res;

	return p;
}

// Find two duplicate elements in a limited range array
int main()
{
	int arr[] = { 4, 3, 6, 5, 2, 4, 1, 1, 2, 3 };
	int n = 10;	// size of the array is n + 2

	pair<int, int> p = findDuplicates(arr, n);
	cout << "Duplicate elements are " << p.first << " and " << p.second;

	return 0;
}