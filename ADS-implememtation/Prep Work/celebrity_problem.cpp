//You are in a party of N people, where only one person is known to everyone. Such a person may be present at the party, if yes, (s)he doesn’t know anyone at the party. Your task is to find the celebrity at the party in Time Complexity O(n) Asked in: Google, Flipkart, Amazon, Microsoft

#include <bits/stdc++.h> 
using namespace std; 
#define N 8 
  
// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
                     {0, 0, 1, 0}, 
                     {0, 1, 0, 0},
                     {0, 0, 1, 0}} ;
  
bool knows(int a, int b) 
{ 
    return MATRIX[a][b]; 
} 
  
// Returns id of celebrity 
int findCelebrity(int n) 
{ 
    // Initialize two pointers as two corners 
    int X = 0; 
    int Y = n - 1; 
  
    // Keep moving while the two pointers don't become same.  
    while (X < Y) 
    { 
        if (knows(X, Y)) 
            X++; 
        else
            Y--; 
    } 
  
    // Check if X is actually a celebrity or not 
    for (int i = 0; i < n; i++) 
    { 
        // If any person doesn't  know 'X' or 'X' doesn't know any person, return -1 
        if ( (i != X) && 
                (knows(X, i) ||  
                !knows(i, X)) ) 
            return -1; 
    } 
  
    return X; 
} 

int my_findCelebrity(int n){
    int i=0, j=n-1;
    while(i < j){
        if(MATRIX[i][j] == 0) j--;
        else i++;
    }
    for(int k = i,l = 0;l < n;l++) if(k != l and MATRIX[k][l] == 1) return -1;
    for(int k = 0,l = j;k < n;k++) if(k != l and MATRIX[k][l] != 1) return -1;
    return j;
}
  
int main() 
{ 
    int n = 4; 
    int id = my_findCelebrity(n); 
    id == -1 ? cout << "No celebrity Found.\n" : 
               cout << "Celebrity ID is " 
                    << id<<".\n"; 
    return 0; 
} 