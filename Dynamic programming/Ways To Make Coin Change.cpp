// coding ninja    Ways To Make Coin Change


#include <bits/stdc++.h>
long f(long ind,long target,int *a,vector<vector<long>> &dp){
    if(ind == 0){
        return (target%a[0]==0);
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    long nottake = f(ind-1,target,a,dp);
    long take = 0;
    if(a[ind]<=target){
        take = f(ind,target-a[ind],a,dp);
    }
    return dp[ind][target] = take+nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long> (value+1,0));
    for(int j=0;j<=value;j++){
        dp[0][j] = (j%denominations[0]==0);

    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=value;T++){
            long nottake = dp[ind-1][T];
            long take = 0;
            if(denominations[ind]<=T){
                take = dp[ind][T-denominations[ind]];
            }
            dp[ind][T] = take+nottake;
        }
    }
    
    return dp[n-1][value];
}

// space optimization  TC = O(N*V)    SC = O(V)

#include <bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value+1,0),cur(value+1,0);
    for(int j=0;j<=value;j++){
        prev[j] = (j%denominations[0]==0);
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=value;T++){
            long nottake = prev[T];
            long take = 0;
            if(denominations[ind]<=T){
                take = cur[T-denominations[ind]];
            }
            cur[T] = take+nottake;
        }
        prev = cur;
    }
    
    return prev[value];
}