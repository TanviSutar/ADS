#include<iostream>
#define ll long long
#define mod 1000000007 
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n],presum[n+1];
        presum[0] = 0;
        bool flag = false;
        for(int i=0;i<n;i++) cin>>arr[i];
        if(arr[0] == 1){
            for(int i=1;i<=n;i++) presum[i] = 1;
            flag = true;
        } 
        else{
            for(int i=0;i<n;i++){
                if(i<n-2 and arr[i+1] == 1){
                    if(arr[i]%2 == 0)//Even number of candies are offered
                        presum[i+1] = presum[i] + arr[i]-1;
                    else //Odd number of candies are offered
                        presum[i+1] = presum[i] + arr[i];
                }
                else{
                    if(i < n-1){
                        if(arr[i]%2 == 0)//Even number of candies are offered 
                            presum[i+1] = presum[i] + arr[i];
                        else //Odd number of candies are offered
                            presum[i+1] = presum[i] + arr[i]-1;
                    }
                    else{
                        if(arr[i]%2 == 0)//Even number of candies are offered
                            presum[i+1] = presum[i] + arr[i]-1;
                        else //Odd number of candies are offered
                            presum[i+1] = presum[i] + arr[i];
                    }
                }
            }
        }
        ll q,r;
        cin>>q;
        while(q--){
            cin>>r;
            ll sum = presum[n]*(r/n);
            if(arr[0] != 1){
                if(r != n)
                    sum += presum[(r-1)%n+1];
                if(arr[(r-1)%n] != 1)
                    if(presum[(r-1)%n+1]-presum[(r-1)%n] < arr[(r-1)%n])
                        sum++;
            }
            else{
                if(r != 1 and arr[r%n] == 1) sum--;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}