//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length. Do not allocate extra space for another array, Time complexity O(n) and Space complexity O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int removeDuplicates(vector<int>& nums) {
      //Write your code here
      return 0;
   }
   int my_removeDuplicates(vector<int>& nums) {
      int i=1,j=1,curr=nums[0];
      while(i<nums.size()){
          if(nums[i] != curr){
              nums[j] = nums[i];
              j++;
              curr = nums[i];
          }
          i++;
      }
      return j;
   }
};

int main(){
   Solution ob;
   vector<int> v = {1,2,3,4,5,5,6,6,6,7};
   cout << ob.my_removeDuplicates(v)<<endl;
}