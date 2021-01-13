//List of arrival and departure time is given, Find the minimum number of platforms are required for the railway as no train waits

#include<iostream>
#include<algorithm>
using namespace std;

int minPlatform(int arrival[], int departure[], int n) {
   sort(arrival, arrival+n);     //sort arrival and departure times
   sort(departure, departure+n);

   int platform = 1, minPlatform = 1;
   int i = 1, j = 0;

   while (i < n && j < n) {
      if (arrival[i] < departure[j]) {
         platform++;     //platform added
         i++;
         if (platform > minPlatform)    //if platform value is greater, update minPlatform
            minPlatform = platform;
      } else {
         platform--;      //delete platform
         j++;
      }
   }
   return minPlatform;
}

int my_minPlatform(int arr[],int dep[],int n){
    sort(arr,arr+n);
    sort(dep,dep+n);
    int max = 0,i=0,j=0,platforms=0;
    while(i < n and j < n){
        if(arr[i] < dep[j]){
            platforms++;
            i++;
            max = std::max(max,platforms);
        }
        else{
            platforms--;
            j++;
        }
    }
    return max;
}

int main() {
   int arrival[] = {900, 940};
   int departure[] = {910, 1200};
   int n = 2;
   cout<< "Minimum Number of Platforms Required: "<<my_minPlatform(arrival, departure, n)<<endl;
   return 0;
}