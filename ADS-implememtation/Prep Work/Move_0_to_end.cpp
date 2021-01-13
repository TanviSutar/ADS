#include <iostream> 
using namespace std; 
  
void moveZeroToTheEnd(int array1[], int n) 
{ 
   //Write Your Code Here 
   //Try YourSelf
} 
  
void my_moveZeroToTheEnd(int arr[], int n) 
{ 
   int i=0,j=-1;
   for(i=0;i<n;i++){
       if(j == -1){
           if(arr[i] == 0) j = i;
       }
       else{
           if(arr[i]){
               arr[j] = arr[i];
               j++;
           }
       }
   }
   while(j<n){
       arr[j] = 0;
       j++;
   }
} 

int main() 
{ 
    int array1[] = {0,0,4,0,3,0,5,6,0,4,4,2,0,9}; 
    int n = sizeof(array1) / sizeof(array1[0]); 
    my_moveZeroToTheEnd(array1, n); 
    cout << "Result is :\n"; 
    for (int i = 0; i < n; i++) 
        cout << array1[i] << " "; 
    return 0; 
} 