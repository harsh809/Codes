//gfg    Connecting the graph using disjoint set

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class disjoint{
public:
    vector<int> parent, size;
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
    void UnionBySize(int u, int v){
        int ulp_u = findparent(u);
        int ulp_v = findparent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        disjoint ds(n);
        int ext = 0;
        for(auto it:edge){
            int u = it[0];
            int v = it[1];
            if(ds.findparent(u) == ds.findparent(v)){
                ext++;
            }
            else{
                ds.UnionBySize(u,v);
            }
        }
        int cntc = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntc++;
        }
        int ans = cntc-1;
        if(ext>=ans) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends