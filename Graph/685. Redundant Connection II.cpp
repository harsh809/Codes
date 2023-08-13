// 685. Redundant Connection II

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
        bool union_size(int u, int v) {
            int ult_u = par(u);
            int ult_v = par(v);
            if (ult_u == ult_v) return true;
            if (size[ult_u] < size[ult_v]) {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            } else {
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
            return false;
        }
    };
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1,-1);
        int bl1 = -1;
        int bl2 = -1;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(indegree[v]==-1){
                indegree[v] = i;
            }
            else{
                bl1 = i;
                bl2 = indegree[v];
                break;
            }
        }
        dsu ds(n);
        for(int i=0;i<n;i++){
            if(i == bl1){
                continue;
            }
            int u = edges[i][0];
            int v = edges[i][1];
            bool flag = ds.union_size(u,v);
            if(flag){
                if(bl1==-1){
                    return edges[i];
                }
                else{
                    return edges[bl2];
                }
            }
        }
        return edges[bl1];
    }
};