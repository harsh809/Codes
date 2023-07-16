//coding ninja  Best Time to Buy and Sell Stock II

//memoiztion  TC = O(N*2) SC = O(N*2) + (N)
#include <bits/stdc++.h>
long f(int ind,int buy,int n,long *values,vector<vector<long>> &dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    long profit;
    if(buy){
        profit = max(-values[ind]+f(ind+1,0,n,values,dp),0+f(ind+1,1,n,values,dp));
    }
    else{
        profit = max(values[ind]+f(ind+1,1,n,values,dp),0+f(ind+1,0,n,values,dp));
    }
    return dp[ind][buy] = profit;
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n,vector<long> (2,-1));
    return f(0,1,n,values,dp);
}

//tabulation  TC = O(N*2) SC = O(N*2)

#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long> (2,0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit = max(-values[ind]+dp[ind+1][0],0+dp[ind+1][1]);
            }
            else{
                profit = max(values[ind]+dp[ind+1][1],0+dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

//space optization  TC = O(N*2) SC = O(2)
#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<long> prev(2,0),cur(2,0);
    prev[0] = 0;
    prev[1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit = max(-values[ind]+prev[0],0+prev[1]);
            }
            else{
                profit = max(values[ind]+prev[1],0+prev[0]);
            }
            cur[buy] = profit;
        }
        prev = cur;
    }
    return prev[1];
}
//space optization  TC = O(N) SC = O(1)
#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    long prev0,prev1,cur0,cur1;
    prev0 = 0;
    prev1 = 0;
    for(int ind=n-1;ind>=0;ind--){
        cur1 = max(-values[ind]+prev0,0+prev1);

        cur0 = max(values[ind]+prev1,0+prev0);

        prev0 = cur0;
        prev1 = cur1;
    }
    return prev1;
}
