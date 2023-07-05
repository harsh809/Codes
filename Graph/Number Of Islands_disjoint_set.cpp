//gfg   Number Of Islands disjoint set

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class disjoint{
    public:
        vector<int> parent,size;
    disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    void UnionBysize(int u,int v){
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
     }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        disjoint ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int dr[4] = {1,0,-1,0};
            int dc[4] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                if((adjr>=0 && adjr<n) && (adjc>=0 && adjc<m)){
                    if(vis[adjr][adjc]==1){
                        int node = row*m + col;
                        int adjnode = adjr*m + adjc;
                        if(ds.findparent(node) != ds.findparent(adjnode)){
                            cnt--;
                            ds.UnionBysize(node,adjnode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends