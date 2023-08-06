//coding ninja  Identical sentences

#include<bits/stdc++.h>
string par(string x,unordered_map<string,string>& parent,unordered_map<string,int>& size){
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
void union_size(string x,string y,unordered_map<string,int>& size,unordered_map<string,string>& parent){
    string ult_x = par(x,parent,size);
    string ult_y = par(y,parent,size);
    if(ult_x==ult_y) return;
    if(size[ult_x]<size[ult_y]){
        parent[ult_x] = ult_y;
        size[ult_y] += size[ult_x];
    }
    else{
        parent[ult_y] = ult_x;
        size[ult_x] += size[ult_y];
    }
}
bool identicalSentences(vector<string> word1, vector<string> word2, vector<vector<string>> pairs, int n, int m, int p) {
    if(n!=m) return 0;
    unordered_map<string,string> parent;
    unordered_map<string,int> size;
    for(auto it:pairs){
        string u = it[0];
        string v = it[1];
        union_size(u,v,size,parent);
    }
    for(int i=0;i<n;i++){
        string x = word1[i];
        string y = word2[i];
        if(x!=y && par(x,parent,size)!=par(y,parent,size)){
            return false;
        }
    }
    return true;
}