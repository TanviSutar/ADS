//Write an algorithm to find out next greater number to given number with the same set of digits Asked in : Morgan Stanley, Makemytrip, Amazon

#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std; 
  

void swap(char *a, char *b) 
{ 
    char temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// Given a number as a char array array1[], this function finds the 
// next greater number.  It modifies the same array to store the result 
void findNext(char array1[], int n) 
{ 
    int i, j; 
  
    //Start from the right most digit and find the first digit that is 
    // smaller than the digit next to it. 
    for (i = n-1; i > 0; i--) 
        if (array1[i] > array1[i-1]) 
           break; 
  
    // If no such digit is found, then all digits are in descending order 
    // means there cannot be a greater number with same set of digits 
    if (i==0) 
    { 
        cout << "Next number is not possible"; 
        return; 
    } 
  
    //Find the smallest digit on right side of (i-1)'th digit that is 
    // greater than array1[i-1] 
    int x = array1[i-1], smallest = i; 
    for (j = i+1; j < n; j++) 
        if (array1[j] > x && array1[j] < array1[smallest]) 
            smallest = j; 
  
    // Swap the above found smallest digit with array1[i-1] 
    swap(&array1[smallest], &array1[i-1]); 
  
    //Sort the digits after (i-1) in ascending order 
    sort(array1 + i, array1 + n); 
  
    cout << "Next number with same set of digits is " << array1; 
  
    return; 
} 
  
void my_findNext(char carr[],int n){
    int arr[n],i,j;
    for(i=0;i<n;i++){
        arr[i] = carr[i]-'0';
    }
    i = n-2;
    j = n-1;
    while(i >= 0 and arr[i] > arr[j]) i--;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    for(i=i+1;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    tmp = 0;
    for(int i=n-1,j=1;i>=0;i--,j=j*10) {
        arr[i] *= j; 
        tmp += arr[i];
    }
    cout<<tmp<<endl;
}
  
int main() 
{ 
    char digits[] = "218765"; 
    int n = strlen(digits); 
    my_findNext(digits, n); 
    return 0; 
} 