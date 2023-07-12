// coding ninja   maximmum sum of non adjacent elements


//approach TC = O(n) sc = O(n) + O(n);
#include <bits/stdc++.h> 
int f(int n,vector<int> &nums,vector<int> &dp){
    if(n==0) return nums[n];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int pick = nums[n] + f(n-2,nums,dp);
    int notpick = 0 + f(n-1,nums,dp);
    return dp[n] = max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp)
}


//approach 2  TC = O(n)  SC = O(1)

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1){
            take += prev2;
        }
        int nottake = 0 + prev;
        int curr = max(take,nottake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}