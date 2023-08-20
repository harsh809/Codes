//1627. Graph Connectivity With Threshold

class Solution {
public:
    
    class dsu {
    public:
        vector<int> parent, size;
        dsu(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        int par(int node) {
            if (parent[node] == node) {
                return node;
            }
            return parent[node] = par(parent[node]);
        }
        int gcd(int a,int b){
            if(a==0) return b;
            if(b==0 || a==b) return a;

            if(a>b) return gcd(a-b,b);
            return gcd(a,b-a);
        }
        void union_size(int u, int v,int k) {
            int ult_u = par(u);
            int ult_v = par(v);
            if (ult_u == ult_v) return;
            if (size[ult_u] < size[ult_v] && gcd(u,v)>k) {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            } else if(gcd(u,v)>k){
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }
        
    };
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        dsu ds(n);
        vector<bool> ans(queries.size());
        if(threshold<1){
            for(int i=0;i<queries.size();i++){
                ans[i] = true;
            }
            return ans;
        }
        for(int i = threshold+1;i<=n;i++){
            for(int j = 2*i ;j<=n;j+=i){
                ds.union_size(i,j,threshold);
            }
        }
        
        int i = 0;
        for(auto it:queries){
            int u = it[0];
            int v = it[1];
            if(ds.par(u)==ds.par(v)){
                ans[i++] = true;
            }
            else{
                ans[i++] = false;
            }
        }
        
        return ans;
    }
};