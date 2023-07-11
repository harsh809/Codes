//gfg   Maximum Stone Removal

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxrow = 0;
        int maxcol = 0;
        for(auto it:stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        disjoint ds(maxrow + maxcol +1);
        unordered_map<int,int> stonenodes;
        for(auto it:stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.UnionBysize(noderow,nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }
        int cnt = 0;
        for(auto it:stonenodes){
            if(ds.findparent(it.first)== it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends