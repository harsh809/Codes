//2369. Check if There is a Valid Partition For The Array

class Solution {
public:
    bool f(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()) return true;
        if(dp[i]!=-1) return dp[i];
        
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            if(f(i+2,nums,dp)) return dp[i] = true;
            
            if(i+2<nums.size() && nums[i]==nums[i+2]){
                if(f(i+3,nums,dp)) return dp[i] = true;
            }
        }
        if(i+2<nums.size() && nums[i]+1==nums[i+1] && nums[i]+2==nums[i+2]){
            if(f(i+3,nums,dp)) return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};