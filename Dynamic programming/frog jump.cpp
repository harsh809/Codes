// coding ninja  Frog jump
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int left = dp[i-1]+abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1){
            right = dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[n-1];
}

// space optimization

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int left = prev+abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1){
            right = prev2+abs(heights[i]-heights[i-2]);
        }
        prev2 = prev;
        prev = min(left,right);
    }
    return prev;
}