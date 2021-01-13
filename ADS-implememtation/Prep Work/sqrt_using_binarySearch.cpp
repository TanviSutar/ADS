//Find square root of Guven Num without sqrt() function in Time Complexity O(Logn) and No Space Complexity Asked in : Accolite, Qualcomm

#include<bits/stdc++.h> 
using namespace std; 
          
int findSqrt(int x)  
{     
    int low = 1, high = x, ans;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid*mid == x) return mid;
        if(mid*mid > x) high = mid -1;
        else{
            low = mid +1;
            ans = mid;
        } 
    }
    return ans;
} 
   
int main()  
{      
    int x = 8; 
    cout << findSqrt(x) << endl; 
    return 0;    
} 