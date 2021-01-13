#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#define index itr->first
#define sheets itr->second
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k,cnt=0;
	    cin>>n>>k;
	    char s;
        vector<pair<int,int>> Iq,Mq;
		vector<pair<int,int>>::iterator itr,end;
	    for(int i=1;i<=n;i++){
			cin>>s;
			if(s == 'I'){
				bool flag = false;
				if(!Mq.empty()){
					itr = Mq.begin();
					while(itr != Mq.end()){
						if((k+1-abs(index-i)-sheets) > 0){
							cnt++;
							flag = true;
						}
						Mq.erase(Mq.begin());
						itr = Mq.begin();
						if(flag) break;
					}
				}
				if(!flag) Iq.push_back(make_pair(i,0));
			}
			else if(s == 'M'){
				bool flag = false;
				if(!Iq.empty()){
					itr = Iq.begin();
					while(itr != Iq.end()){
						if((k+1-abs(index-i)-sheets) > 0){
							cnt++;
							flag = true;
						}
						Iq.erase(Iq.begin());
						itr = Iq.begin();
						if(flag) break;
					}
				}
				if(!flag) Mq.push_back(make_pair(i,0));
			}
			else if(s == ':'){
				if(Iq.empty() and Mq.empty()) continue;
				if(!Iq.empty()) {
					itr = Iq.begin();
					end = Iq.end();
				}
				else{
					itr = Mq.begin();
					end = Mq.end();
				} 
				while(itr != end){
					itr->second++;
					itr++;
				}
			}
			else if(s == 'X'){
				Iq.clear();
				Mq.clear();
			}
			else continue;
		}
	    cout<<cnt<<endl;
	}
	return 0;
}
