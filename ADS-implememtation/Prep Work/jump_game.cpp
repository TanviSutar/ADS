//You have an array of non-negative integers,you are initially positioned at the first index of the array.Each element in the array represents your maximum jump length at that position.Determine if you are able to reach the last index in O(n) Time complexity and O(1) Space Complexity Asked in: Adobe, Intuit
#include<iostream>
using namespace std;

int func(int nums[],int len){
    int a = nums[0];
    int b = nums[0];
    int jump = 1;
    for(int i=0;i<len;i++){
        if(i == len-1)
            return jump;
        a--;
        b--;
        if(nums[i] > b) b = nums[i];
        if(a == 0){
            a = b;
            jump++;
        }
    }
    return jump;
}

int main(){
    int arr[] = {3,2,1,0,4};
    int s = sizeof(arr)/sizeof(arr[0]);
    int curr = 1;
    int k = 1;
    int jump = 0;
    int i = 0;
    while(i < s){
        curr--;
        k--;
        if(arr[i] > k) k = arr[i];
        if(curr <= 0 and k <= 0) break;
        if(curr == 0 and i != s-1){
            curr = k;
            jump++;
        }
        i++;
    }
    if(i < s) cout<<-1<<endl;
    else cout<<jump<<endl; 
    //cout<<func(arr,s);
    return 0;
}

