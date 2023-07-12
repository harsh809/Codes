//coding ninja   0 1 Knapsack

//memorization  TC = O(N*wt)   SC = O(N*wt) + O(N);
#include <bits/stdc++.h> 
int f(int ind,int wt,vector<int>& weight,vector<int> &value,vector<vector<int>>& dp){
	if(ind==0){
		if(weight[ind]<=wt) return value[0];
		else return 0;
	}
	if(dp[ind][wt]!=-1)  return dp[ind][wt];
	int nottake = 0 + f(ind-1,wt,weight,value,dp);
	int take = INT_MIN;
	if(weight[ind]<=wt){
		take = value[ind] + f(ind-1,wt-weight[ind],weight,value,dp);
	}
	return dp[ind][wt] = max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}


//tabulation  TC = O(N*wt)   SC = O(N*wt);
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
	for(int j=weight[0];j<=maxWeight;j++){
		dp[0][j] = value[0];
	}
	for(int i=1;i<n;i++){
		for(int wt=0;wt<=maxWeight;wt++){
			int nottake = 0 + dp[i-1][wt];
			int take = INT_MIN;
			if(weight[i]<=wt){
				take = value[i] + dp[i-1][wt-weight[i]];
			}
			dp[i][wt] = max(take,nottake);
		}
	} 
	return dp[n-1][maxWeight];
}


//space optimization  TC = O(N*wt)   SC = O(wt);

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0),cur(maxWeight+1,0);
	for(int j=weight[0];j<=maxWeight;j++){
		prev[j] = value[0];
	}
	for(int i=1;i<n;i++){
		for(int wt=0;wt<=maxWeight;wt++){
			int nottake = 0 + prev[wt];
			int take = INT_MIN;
			if(weight[i]<=wt){
				take = value[i] + prev[wt-weight[i]];
			}
			cur[wt] = max(take,nottake);
		}
		prev = cur;
	} 
	return prev[maxWeight];
}

//require only one array
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);
	for(int j=weight[0];j<=maxWeight;j++){
		prev[j] = value[0];
	}
	for(int i=1;i<n;i++){
		for(int wt=maxWeight;wt>=0;wt--){
			int nottake = 0 + prev[wt];
			int take = INT_MIN;
			if(weight[i]<=wt){
				take = value[i] + prev[wt-weight[i]];
			}
			prev[wt] = max(take,nottake);
		}
	} 
	return prev[maxWeight];
}