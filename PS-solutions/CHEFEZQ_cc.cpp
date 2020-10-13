#include <iostream>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    ll rm = 0,flag = 0;
	    for(ll i=1;i<=n;i++){
	        ll q;
	        cin>>q;
	        if((rm+q) < k){
	          cout<<i<<endl;
	          flag = 1;
	          break;
	        }
	        rm = rm+q - k;
	    }
	    if(!flag){
            cout<<n+int(rm/k)+1<<endl;

	    }
	}
	return 0;
}