#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	//cout<<T;
	while(T--)
	{
	    int N,K;
	    long long int sonres=0;
	    long long int chefres=0;
	    long long int sum=0;
	    vector<long long int> a;
	    cin>>N>>K;
	    for(int i=0; i<N; i++)
	    {
	        int num;
	        cin>>num;
	        a.push_back(num);
	    }
	    sort(a.begin(),a.end());
	    for(int i=0; i<N; i++)
	    {
	        if(i<=K)
	        {
	            sonres+=a[i];
	        }
	        if(i>=K)
	        {
	            chefres+=a[i];
	        }
	        sum+=a[i];
	    }
	    cout<<max(abs(chefres-(sum-chefres)),abs(sonres-(sum-sonres)))<<endl;
	}
	return 0;
}
