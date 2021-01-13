//Given a matrix of M x N elements (M rows, N columns), Print all elements of the matrix in diagonal order in Time Complexity O(m*n) and Space Complexity O(1)

#include<iostream>
#define N 3
using namespace std;

void printAllDgl(int matrix[N][N])
{
    int row = 0,col = 0;
    bool flag = true; //when true increment row
    while(true){
        //cout<<matrix[row][col]<<" ";
        if(flag){
            while(row >= 0 and col <= N){
                cout<<matrix[row][col]<<" ";
                row--;
                col++;
            }
            row++;
        }
        else{
            while(col >= 0 and row <= N){
                cout<<matrix[row][col]<<" ";
                col--;
                row++;
            }
            col++;
        }
        if(row == N-1 and col == N-1) break;
        if(row > N) row--;
        if(col > N) col--;
        flag = !flag;
    }
}

int main(){
    int mat[][N] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    printAllDgl(mat);
    return 0;
}