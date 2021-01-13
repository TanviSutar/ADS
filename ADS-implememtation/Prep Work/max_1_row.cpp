//A 2-D array of 1's and 0's is given. Find the row with max 1's in Time Complexity O(logn) and Space Complexity O(1) . The array is sorted row wise (all 0's in a row are followed by all 1's

#include <iostream>
using namespace std;

#define M 5
#define N 5

int findRowIndex(bool arr[][N])
{
	//Write your code here
    int m = N+1, row = -1;
    for(int i=0;i<M;i++){
        int low = 0, high = N, ans = m;
        while(low <= high){
            int mid = (low+high)/2;
            if(mid < N and arr[i][mid] == 1){
                ans = mid;
                high = mid -1;
            } 
            else low = mid +1;
        }
        if(ans < m){
            m = ans;
            row = i;
        }
    }
	return row;
}

int main()
{
	bool mat[M][N] =
	{
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 }
	};

	int rowIndex = findRowIndex(mat);

	// rowIndex = 0 means no 1's are present in the matrix
	if (rowIndex)
		cout << "Maximum 1's are present in the row " << rowIndex<<endl;

	return 0;
}