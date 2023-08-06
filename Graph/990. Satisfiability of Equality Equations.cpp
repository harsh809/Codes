//leetcode  990. Satisfiability of Equality Equations

class Solution {
public:
    char par(char x,unordered_map<char,char>& parent,unordered_map<char,int>& size){
        if(parent.find(x)==parent.end()){
            parent[x] = x;
            size[x] = 1;
            return x;
        }
        if(parent[x]==x){
            return x;
        }
        return parent[x] = par(parent[x],parent,size);
    }
    void union_size(char x,char y,unordered_map<char,char>& parent,unordered_map<char,int>& size){
        char ult_x = par(x,parent,size);
        char ult_y = par(y,parent,size);
        if(ult_x == ult_y) return;
        if(size[ult_x] < size[ult_y]){
            parent[ult_x] = ult_y;
            size[ult_y] += size[ult_x];
        }
        else{
            parent[ult_y] = ult_x;
            size[ult_x] += size[ult_y];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,char> parent;
        unordered_map<char,int> size;
        for(auto it:equations){
            if(it[1]=='='){
                union_size(it[0],it[3],parent,size);
            }
        }
        for(auto it:equations){
            if(it[1]=='!'){
                if(par(it[0],parent,size)==par(it[3],parent,size)){
                    return false;
                }
            }
        }
        return true;
    }
};