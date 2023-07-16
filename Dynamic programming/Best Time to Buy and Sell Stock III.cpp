//coding ninja  Best Time to Buy and Sell Stock III

//tabulation  TC = O(N*2*3) SC = O(N*2*3)
//now you done at max 2 transaction
#include <bits/stdc++.h> 
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

//space optimizAtion  TC = O(N*2*3) SC = O(2*3)
#include <bits/stdc++.h> 
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> prev(2,vector<int> (3,0)),curr(2,vector<int> (3,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    curr[buy][cap] = max(-prices[ind]+prev[0][cap],0+prev[1][cap]);
                }
                else{
                    curr[buy][cap] = max(prices[ind]+prev[1][cap-1],prev[0][cap]);
                }
            }
        }
        prev = curr;
    }
    return prev[1][2];
}