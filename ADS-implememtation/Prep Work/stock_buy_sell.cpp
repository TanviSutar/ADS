//An array is given as Input where ith element is the price of a given stock on day You were permitted to complete unlimited transaction. Derive an algorithm to find the maximum profit in O(n) Time complexity and O(n) Space Complexity Asked in: Amazon, Microsoft, Flipkart, DE-Shaw

#include <bits/stdc++.h> 
using namespace std; 
  
//function finds the buy sell 
// schedule for maximum profit 
void stockBuySell(int array1[], int n) 
{ 
    // Prices must be given for at least two days 
    if (n == 1) 
        return; 
  
    // Traverse through given price array 
    int i = 0; 
    while (i < n - 1) { 
  
        // Find Local Minima 
        // Note that the limit is (n-2) as we are 
        // comparing present element to the next element 
        while ((i < n - 1) && (array1[i + 1] <= array1[i])) 
            i++; 
  
        // If we reached the end, break 
        // as no further solution possible 
        if (i == n - 1) 
            break; 
  
        // Store the index of minima 
        int buy = i++; 
  
        // Find Local Maxima 
        // Note that the limit is (n-1) as we are 
        // comparing to previous element 
        while ((i < n) && (array1[i] >= array1[i - 1])) 
            i++; 
  
        // Store the index of maxima 
        int sell = i - 1; 
  
        cout << "Buy on day: " << buy 
             << "\t Sell on day: " << sell << endl; 
    } 
} 

int main() 
{ 
    int array1[] = { 98, 178, 250, 300, 40, 540, 690 }; 
    int n = sizeof(array1) / sizeof(array1[0]); 
  
    stockBuySell(array1, n); 
  
    return 0; 
} 