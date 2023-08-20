//1202. Smallest String With Swaps

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
        void union_size(int u, int v) {
            int ult_u = par(u);
            int ult_v = par(v);
            if (ult_u == ult_v) return;
            if (size[ult_u] < size[ult_v]) {
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            } else{
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }
        
    };
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        dsu ds(n);
        for(auto it:pairs){
            int u = it[0];
            int v = it[1];
            ds.union_size(u,v);
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[ds.par(i)].push_back(i);
        }
        for(auto it:mp){
            vector<int> v = it.second;
            string ans = "";
            for(auto i:v){
                ans += s[i];
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++){
                s[v[i]] = ans[i];
            }
        }
        return s;
    }
};