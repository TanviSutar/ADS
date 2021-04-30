#include<bits/stdc++.h>
using namespace std;

int main() {
	string str1, str2;
	cin>>str1>>str2;
	int m = str1.size();
	int n = str2.size();
	int dp[m+1][n+1] = {0};
	for(int i=0;i<=m;i++) dp[i][0] = 0;
	for(int i=0;i<=n;i++) dp[0][i] = 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(str1.at(i-1) == str2.at(j-1)) dp[i][j] = dp[i-1][j-1] +1;
			else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout<<"Length of the longest common subsequence is: "<<dp[m][n]<<endl;
	stack<char> stk;
	int i = m, j = n;
	while(i > 0 and j > 0){
		if(dp[i][j] == std::max(dp[i-1][j],dp[i][j-1])){
			if(dp[i-1][j] > dp[i][j-1]) i--;
			else j--;
		}
		else{
			stk.push(str1.at(i-1));
			i--;j--;
		}
	}
	cout<<"Longest common subsequence is: ";
	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
	}
	cout<<endl;
	return 0;
}
