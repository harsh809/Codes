// gfg Replace O's with X's

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>> mat,int deltarow[],int deltacol[],int n,int m){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row + deltarow[i];
            int ncol = col + deltacol[i];
            if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m) && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat,deltarow,deltacol,n,m);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int deltarow[4] = {1,0,-1,0};
        int deltacol[4] = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && mat[0][i]=='O'){
                dfs(0,i,vis,mat,deltarow,deltacol,n,m);
            }
            if(!vis[n-1][i] && mat[n-1][i]=='O'){
                dfs(n-1,i,vis,mat,deltarow,deltacol,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat,deltarow,deltacol,n,m);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat,deltarow,deltacol,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends