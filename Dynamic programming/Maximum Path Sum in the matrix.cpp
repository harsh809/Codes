//coding ninja   Maximum Path Sum in the matrix

//approach 1     TC = O(N*M)   SC = O(N*M) + O(N);
#include <bits/stdc++.h> 
int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
    if(j<0 || j>=matrix[0].size()) return -1e9;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int s = matrix[i][j] + f(i-1,j,matrix,dp);
    int lfd = matrix[i][j] + f(i-1,j-1,matrix,dp);
    int rd = matrix[i][j] + f(i-1,j+1,matrix,dp);
    return dp[i][j] = max(s,max(rd,lfd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    int maxi = -1e9;
    for(int j = 0;j<m;j++){
        maxi = max(maxi,f(n-1,j,matrix,dp));
    }
    return maxi;
}

//approach 1     TC = O(N*M)   SC = O(N*M);

#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int> (m,0));
    int maxi = -1e9;
    for(int j = 0;j<m;j++){
        dp[0][j] = matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j = 0;j<m;j++){
            int s = matrix[i][j] + dp[i-1][j];
            int lfd = matrix[i][j]; 
            if(j-1>=0) lfd += dp[i-1][j-1];
            else lfd = -1e9;
            int rd = matrix[i][j]; 
            if(j+1<m) rd += dp[i-1][j+1];        
            else rd = -1e9;
            dp[i][j] = max(s,max(rd,lfd));
        }
    }
    for(int j=0;j<m;j++){
        maxi = max(dp[n-1][j],maxi);
    }
    return maxi;
}

//approach 3     TC = O(N*M)   SC = O(N);

#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m,0),cur(m,0); 
    int maxi = -1e9;
    for(int j = 0;j<m;j++){
        cur[j] = matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j = 0;j<m;j++){
            int s = matrix[i][j] + cur[j];
            int lfd = matrix[i][j]; 
            if(j-1>=0) lfd += cur[j-1];
            else lfd = -1e9;
            int rd = matrix[i][j]; 
            if(j+1<m) rd += cur[j+1];        
            else rd = -1e9;
            prev[j] = max(s,max(rd,lfd));
        }
        cur = prev;
    }
    for(int j=0;j<m;j++){
        maxi = max(cur[j],maxi);
    }
    return maxi;
}