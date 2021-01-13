//String is given as input that contains only lowercase letters, remove duplicate letters so that every letter appears once In O(n) Time Complexity and O(1) Space

#include <bits/stdc++.h> 
using namespace std; 
  
char *removeDuplicate(char arr[], int n) 
{ 
    int store[255] = {0};//using ascii array of size 256
    int i = 0,ptr = 0;
    while(i < n){
        if(store[arr[i]] == 0){
            arr[ptr] = arr[i];
            ptr++;
            store[arr[i]] = 1;
        }
        i++;
    }
    arr[ptr] = '\0';
    return arr; 
} 

char *removeDuplicate2(char arr[], int n){
    int counter = 0;//using variable bits to signify first occurence of any letter
    int i=0;
    int ptr = 0;
    while(i<n){
        int x = arr[i] - 'a';
        if((counter & (1<<x)) == 0){//occured first time
            arr[ptr] = 'a' + x;
            ptr++;
            counter = counter | (1<<x);
        }
        i++;
    }
    arr[ptr] = '\0';
    return arr;
}
  
int main() 
{ 
   char str[]= "cbacdcdffwwaqasdcvdeebc"; 
   int n = sizeof(str) / sizeof(str[0]); 
   cout << removeDuplicate2(str, n)<<endl; 
   return 0; 
} 