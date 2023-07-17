//coding ninja   Boolean Evaluation

#include <bits/stdc++.h>
typedef long long ll;
int mod = 1000000007;
ll f(int i,int j,int istrue,string & exp,vector<vector<vector<ll>>> &dp){
    if(i>j) return 0;
    if(i==j){
        if(istrue){
         return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }
    if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
    ll ways = 0;
    for(int ind = i+1;ind<=j-1;ind +=2){
        ll lt = f(i,ind-1,1,exp,dp);
        ll lf = f(i,ind-1,0,exp,dp);
        ll rt = f(ind+1,j,1,exp,dp);
        ll rf = f(ind+1,j,0,exp,dp);
        if(exp[ind] == '&'){
            if(istrue){
                ways = (ways + (lt*rt)%mod)%mod;
            }
            else{
               ways = (ways + (lt*rf)%mod + (lf*rt)%mod + (lf*rf)%mod)%mod;
            }
        }
        else if(exp[ind] == '|'){
            if(istrue){
                ways = (ways + (lt*rt)%mod + (lt*rf)%mod+ (lf*rt)%mod)%mod;
            }
            else{
                ways = (ways + (lf*rf)%mod)%mod;
            }
        }
        else{
            if(istrue){
                ways = (ways + (lt*rf)%mod+ (lf*rt)%mod)%mod;
            }
            else{
                ways = (ways + (lf*rf)%mod + (lt*rt)%mod)%mod;
            }
        }
    }
    return dp[i][j][istrue] = ways;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>> (n,vector<ll> (2,-1)));
    return f(0,n-1,1,exp,dp);
}