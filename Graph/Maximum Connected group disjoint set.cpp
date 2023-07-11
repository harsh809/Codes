//gfg  Maximum Connected group

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
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                int dr[4] = {1,0,-1,0};
                int dc[4] = {0,1,0,-1};
                for(int k=0;k<4;k++){
                    int adjr = i + dr[k];
                    int adjc = j + dc[k];
                    if((adjr>=0 && adjr<n) && (adjc>=0 && adjc<n) && grid[adjr][adjc]==1){
                        int node = i*n + j;
                        int adjnode = adjr*n + adjc;
                        ds.UnionBysize(node,adjnode);
                    }
                }
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                int dr[4] = {1,0,-1,0};
                int dc[4] = {0,1,0,-1};
                set<int> components;
                for(int k=0;k<4;k++){
                    int adjr = i + dr[k];
                    int adjc = j + dc[k];
                    if((adjr>=0 && adjr<n) && (adjc>=0 && adjc<n)){
                        if(grid[adjr][adjc]==1){
                            components.insert(ds.findparent(adjr*n + adjc));
                        }
                    }
                }
                int sizetotal = 0;
                for(auto it:components){
                    sizetotal += ds.size[it]; 
                }
                mx = max(mx,sizetotal+1);
            }
        }
        for(int cell= 0;cell<n*n;cell++){
            mx = max(mx,ds.size[ds.findparent(cell)]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends