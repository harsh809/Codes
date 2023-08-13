//1579. Remove Max Number of Edges to Keep Graph Fully Traversable

class Solution {
public:
    class dsu{
public:
    vector<int> parent, size;
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1);
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
    bool union_size(int u, int v){
        int ulp_u = par(u);
        int ulp_v = par(v);
        if(ulp_u == ulp_v) return false;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
};
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu ds1(n);
        dsu ds2(n);
        sort(edges.begin(),edges.end());
        int remove = 0;
        int countnode1 = 1;
        int countnode2 = 1;
        int t = edges.size();
        for(int i=t-1;i>=0;i--){
            auto it = edges[i];
            int type = it[0];
            if(type==3){
                bool tempa = ds1.union_size(it[1],it[2]);
                bool tempb = ds2.union_size(it[1],it[2]);
                if(tempa){
                    countnode1++;
                }
                if(tempb){
                    countnode2++;
                }
                if(tempa==false && tempb==false){
                    remove++;
                }
            }
            else if(type == 1){
                bool tempa = ds1.union_size(it[1],it[2]);
                if(tempa){
                    countnode1++;
                }
                else{
                    remove++;
                }
            }
            else{
                bool tempb = ds2.union_size(it[1],it[2]);
                if(tempb){
                    countnode2++;
                }
                else{
                    remove++;
                }
            }
        }
        if(countnode1!=n || countnode2!=n){
            return -1;
        }
        return remove;
    }
};