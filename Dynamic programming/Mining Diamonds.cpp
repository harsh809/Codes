//coding ninja   Mining Diamonds

// memoization   TC = o(n*n*n)  SC = o(n*n) + o(n)
#include <bits/stdc++.h> 
int f(int i,int j,vector<int> &a,vector<vector<int>> &dp){
	if(i>j)return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int maxi = INT_MIN;
	for(int k=i;k<=j;k++){
		int count = a[i-1]*a[k]*a[j+1] + f(i,k-1,a,dp) + f(k+1,j,a,dp);
		maxi = max(maxi,count);
	}
	return dp[i][j] = maxi;
}
int maxCoins(vector<int>& a)
{
	int n = a.size();
	a.push_back(1);
	a.insert(a.begin(),1);
	vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
	return f(1,n,a,dp);
}