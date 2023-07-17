//coding ninja  Number of Longest Increasing Subsequence

#include <bits/stdc++.h> 
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n,1),cnt(n,1);
    int maxi = 1;
    for(int i=1;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[i]>arr[prev] && 1+dp[prev]>dp[i]){
                dp[i] = 1+dp[prev];
                cnt[i] = cnt[prev];
            }
            else if(arr[i]>arr[prev] && 1+dp[prev]==dp[i]){
                cnt[i] += cnt[prev];
            }
        }
        if(maxi<dp[i]){
            maxi = dp[i];
        }
    }
    int nos = 0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi) nos += cnt[i];
    }
    return nos;
}