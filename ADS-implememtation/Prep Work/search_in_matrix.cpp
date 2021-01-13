//Matrix n*n is given, where all elements in any individual row or column are sorted. In such a matrix, we have to find the position of a value in O(n) Time Complexity and O(1) Space Complexity

#include <bits/stdc++.h>  
using namespace std;

int  M = 0; int const  N = 4;

void search(int arr[][N], int m, int n, int key){
    int i = 0, j = n-1;
    while(j >= 0 and i < m){
        if(arr[i][j] == key){
            cout<<"Element found at "<<i<<j<<endl;
            return;
        }
        else if(key < arr[i][j]) j--;
        else i++;
    }   
    cout<<"Element not found\n.";
}
   

int main() 
{ 
    M = 4;
    int mat[M][N] = { { 10, 20, 30, 40 }, 
                      { 15, 25, 35, 45 }, 
                      { 27, 29, 37, 48 }, 
                      { 32, 33, 39, 50 } }; 
    search(mat, 4, 4, 32); 
   
    return 0; 
} 