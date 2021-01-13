//You are given a square matrix, You need to rotate the matrix in a clockwise direction by 90 degrees in Time Complexity O(m*n) and No Extra Space i.e O(1) Asked in : Facebook, Google, Amazon, Microsoft

#include <bits/stdc++.h> 
using namespace std; 
  
#define N 4 

void rotate(int arr[][N]){
    int n = N;
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-1-i;j++){
            int tmp = arr[j][n-1-i];
            arr[j][n-1-i] = arr[i][j];
            arr[i][j] = arr[n-1-j][i];
            arr[n-1-j][i] = arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j] = tmp; 
        }
    }
}

void printMatrix(int arr[N][N]) 
{ 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout << arr[i][j] << " "; 
        cout << '\n'; 
    } 
} 
  

int main() 
{ 
    int arr[N][N] = { { 1, 2, 3, 4 }, 
                      { 5, 6, 7, 8 }, 
                      { 9, 10, 11, 12 }, 
                      { 13, 14, 15, 16 } }; 
    rotate(arr); 
    printMatrix(arr); 
    return 0; 
} 