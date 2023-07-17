//coding ninja Count Square Submatrices with all Ones

#include <bits/stdc++.h> 
int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n,vector<int> (m,0));
    for(int i=0;i<m;i++){
        dp[0][i] = arr[0][i];
    }
    for(int j=0;j<n;j++){
        dp[j][0] = arr[j][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]){
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum += dp[i][j];
        }
    }
    return sum;
}


