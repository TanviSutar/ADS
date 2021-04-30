    #include<iostream>
    #include<algorithm>
    #include<string>
    #define ll long long
    using namespace std;

    int main(){
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            string str[n];
            for(int i=0;i<n;i++) cin>>str[i];
            sort(str, str+n);
            string tmp1, tmp2;
            ll score = 0;
            for(ll i=0; i<n; i++){
                for(ll j=i+1; j<n; j++){
                    tmp1 = str[i];
                    tmp2 = str[j]; 
                    swap(tmp1[0], tmp2[0]);
                    if(tmp1 != tmp2 and tmp1[0] != tmp2[0]){
                        if((!binary_search(str, str+n, tmp1)) and (!binary_search(str, str+n, tmp2)))
                            score += 2;
                    }
                }
            }
            cout<<score<<endl;
        }
        return 0;
    }