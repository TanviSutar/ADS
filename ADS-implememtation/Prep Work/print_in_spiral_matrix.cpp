//you are given a matrix of m x n elements (m rows, n columns), Print all elements of the matrix in spiral order in O(m*n) Time Complexity and O(1) Space Complexity Asked in: Microsoft, OLA, PayTm, Oracle

#include <iostream>
using namespace std;

#define M 5
#define N 5

void printSpiral(int matrix[][N+1], int top, int bottom, int left, int right)
{
	if (left > right)
		return;
	// print top row
	for (int i = left; i <= right; i++)
		cout << matrix[top][i] << " ";
	top++;

	if (top > bottom)
		return;
	// print right column
	for (int i = top; i <= bottom; i++)
		cout << matrix[i][right] << " ";
	right--;

	if (left > right)
		return;
	// print bottom row
	for (int i = right; i >= left; i--)
		cout << matrix[bottom][i] << " ";
	bottom--;

	if (top > bottom)
		return;
	// print left column
	for (int i = bottom; i >= top; i--)
		cout << matrix[i][left] << " ";
	left++;

	printSpiral(matrix, top, bottom, left, right);

}

void my_printSpiral(int matrix[][N+1],int top,int bottom,int left,int right){
    while(top <= bottom){
        for(int j=left;j<=right;j++)
            cout<<matrix[top][j]<<" ";
        if(left == right) break;
        for(int j=top+1;j<=bottom;j++)
            cout<<matrix[j][right]<<" ";
        for(int j=right-1;j>=left;j--)
            cout<<matrix[bottom][j]<<" ";
        for(int j=bottom-1;j>top;j--)
            cout<<matrix[j][left]<<" ";
        top++;
        left++;
        right--;
        bottom--;
    }
}

int main()
{
	int matrix[M][N] =
	{
		{ 1,  2,  3,  4, 5},
		{16, 17, 18, 19, 6},
		{15, 24, 25, 20, 7},
		{14, 23, 22, 21, 8},
		{13, 12, 11, 10, 9}
	};

    int mat[M][N+1]={
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30}
    };

	int top = 0, bottom = M - 1;
	int left = 0, right = N;

	my_printSpiral(mat, top, bottom, left, right);

	return 0;
}