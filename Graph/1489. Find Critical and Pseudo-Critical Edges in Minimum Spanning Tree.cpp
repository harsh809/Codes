class dsu{
    public:
    vector<int> parent,size;
    dsu(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int par(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = par(parent[node]);
    }
    void union_size(int u,int v){
        int ulp_u = par(u);
        int ulp_v = par(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
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
    int krushkal(int a,int skip,int add,vector<vector<int>>& edges){
        dsu ds(a);
        int sum = 0;
        int cnt = 1;
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        int i = 0;
        for(auto edge : edges){
            pq.push({edge[2] , i});
            i++;
        }
        if(add!=-1){
            ds.union_size(edges[add][0],edges[add][1]);
            sum += edges[add][2];
            cnt++; 
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int j = it.second;
            if(skip==j){
                continue;
            }
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(ds.par(u)!=ds.par(v)){
                ds.union_size(u,v);
                sum += wt;
                cnt++;
            }
        }
        if(cnt!=a){
            return INT_MAX;
        }
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int mst = krushkal(n,-1,-1,edges);
        vector<vector<int>> ans(2);
        int i = 0;
        for(auto it:edges){
            if(krushkal(n,i,-1,edges)>mst){
                ans[0].push_back(i);
            }
            else if(krushkal(n,-1,i,edges)==mst){
                ans[1].push_back(i);
            }
            i++;
        }
        return ans;
    }
};
