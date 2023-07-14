//coding ninja   Rod cutting problem

//memoization 
int f(int ind,int n,vector<int> &price,vector<vector<int>> &dp){
	if(ind==0){
		return n*price[0];
	}
	if(dp[ind][n]!=-1) return dp[ind][n];
	int nottake = 0 + f(ind-1,n,price,dp);
	int take = INT_MIN;
	int rodlength = ind+1;
	if(rodlength<=n){
		take = price[ind] + f(ind,n-rodlength,price,dp);
	}
	return dp[ind][n] = max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n,vector<int> (n+1,-1));
	return f(n-1,n,price,dp);
}


//space optimization
int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1,0),cur(n+1,0);
	for(int i=0;i<=n;i++){
		prev[i] = i*price[0];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			int nottake = 0 + prev[j];
			int take = INT_MIN;
			int rodlength = i+1;
			if(rodlength<=j){
				take = price[i] + cur[j-rodlength];
			}
			cur[j] = max(take,nottake);
		}
		prev = cur;
	}
	return prev[n];
}
