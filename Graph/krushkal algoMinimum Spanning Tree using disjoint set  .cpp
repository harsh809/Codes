//gfg     Minimum Spanning Tree

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjoint{
    public:
     vector<int> parent,size;
     disjoint(int n){
         parent.resize(n+1);
         size.resize(n+1);
         for(int i=0;i<=n;i++){
             size[i] = 1;
             parent[i] = i;
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
         if(ulp_u==ulp_v) return ;
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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int v = it[0];
                int wt = it[1];
                int u = i;
                edges.push_back({wt,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        int mst = 0;
        disjoint ds(V);
        for(auto it:edges){
            int u = it.second.first;
            int v = it.second.second;
            int wt = it.first;
            
            if(ds.findparent(u)!=ds.findparent(v)){
                mst += wt;
                ds.UnionBysize(u,v);
            }
        }
        return mst;    
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends