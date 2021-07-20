#include<bits/stdc++.h>
using namespace std;

int main(){
    //arrays allow homogenous data only 

    //declaration
    int arr[10];
    double doub[8];
    char chararr[9];

    //accessing 
    arr[0]= 1;
    arr[1] = 2;

    //traverse the aray
    for(int i=0;i<2;i++) cout<<arr[i]<<" ";

    //initialization
    int arr1[] = {1,2,3,4,5}; //arr1 of 5 elements
    int arr2[10] = {2};// arr2[10] = {0,0,0...}; 10 elements initialized to zero

    //sizeof function
    int arr3[] = {1,2,3,4,2,3,5,1,3,4,5,6,7,8,1,2};

    int size = sizeof(arr3)/sizeof(arr3[0]);
    cout<<size<<endl;

    //Garbage value example
    int arr[5] = {1,2,3,4,5};
    cout<< arr[6] <<endl; //some garbage

    //2d array
    int matrix[2][2] = {
                            {1,2},
                            {3,4}
                        };

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}