//coding niinja   Edit Distance

//memoiztion  TC = O(N*M) SC = O(N*M) + (N+M)
int f(int i,int j,string &str1, string &str2,vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j]){
        return dp[i][j] = f(i-1,j-1,str1,str2,dp);
    }
    return dp[i][j] = 1+min(f(i,j-1,str1,str2,dp),min(f(i-1,j,str1,str2,dp),f(i-1,j-1,str1,str2,dp)));
}
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return f(n-1,m-1,str1,str2,dp);
}
//memoiztion  TC = O(N*M) SC = O(N*M)

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int j=0;j<=n;j++){
        dp[j][0] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }    
        }
    }
    return dp[n][m];
}
//memoiztion  TC = O(N*M) SC = O(2*M)

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int i=0;i<=m;i++){
        prev[i] = i;
        // cur[i] = i;
    }
    for(int i=1;i<=n;i++){
        cur[0] = i;
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                cur[j] = prev[j-1];
            }
            else{
                cur[j] = 1+min(cur[j-1],min(prev[j],prev[j-1]));
            }    
        }
        prev = cur;
    }
    return prev[m];
}


