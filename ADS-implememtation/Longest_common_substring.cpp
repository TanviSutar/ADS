#include<bits/stdc++.h>
using namespace std;

int main() {
	string str1, str2;
	cin>>str1>>str2;
	int m = str1.size();
	int n = str2.size();
	int maxlen = 0;
	int ind = -1;
	int dp[m+1][n+1] = {0};
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(str1.at(i-1) == str2.at(j-1)) dp[i][j] = dp[i-1][j-1] +1;
			if(dp[i][j] > maxlen){
				maxlen = dp[i][j];
				ind = i-1;
			}
		}
	}
	cout<<"Length of the longest common substring: "<<maxlen<<endl;
	if(maxlen > 0){
		stack<char> stk;
		while(maxlen > 0){
			stk.push(str1.at(ind));
			ind--;
			maxlen--;
		}
		cout<<"Longest common substring: ";
		while(!stk.empty()){
			cout<<stk.top();
			stk.pop();
		}
		cout<<endl;
	}
	return 0;
}
