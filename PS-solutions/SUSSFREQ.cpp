//https://www.codechef.com/AUG20B/problems/SUBSFREQ
#include <bits/stdc++.h>
using namespace std;
#define MX 1000000007
#define ll int

bool compare(const pair<ll, ll>&a, const pair<ll, ll>&b)
{
   return a.second<b.second;
}

int main() {
    ll T;
    cin>>T;
    while(T--){
        ll n; 
        cin >> n;
        vector<ll> a(n);
        map<ll,ll> res;
        for(ll i = 1; i <= n; ++i) 
            cin >> a[i];
        ll size = pow(2,n);
        cout<<size<<endl;
        for (ll counter = 1; counter < size; counter++) {
            map<ll,ll> cnt;
            for (ll j = 1; j <= n; j++) {
                cout<<"counter:"<<counter<<"\tj:"<<j<<"\t(1<<(j-1)):"<<(1<<(j-1))<<"\tconter & (1<<(j-1)):"<<(counter & (1 << (j-1)))<<endl;
                if (counter & (1 << (j-1))){
                        if(cnt[a[j]]>0)
                            cnt[a[j]]=(cnt[a[j]]+1)%MX;
                        else
                            cnt[a[j]]=1;
                        //count[a[j]]++;
                }
            }
            ll max = std::max_element(cnt.begin(), cnt.end(), compare)->first;
            res[max]=(res[max]+1)%MX;
        
        }
        for(ll i=1; i<=n; i++)
        {
            cout<<res[i]%MX<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}