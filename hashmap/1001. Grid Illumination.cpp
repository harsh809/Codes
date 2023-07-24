//1001. Grid Illumination

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;
        if(n==0){
            return ans;
        }
        unordered_map<int,int> x,y,dig1,dig2;
        set<pair<int,int>> s;
        for(auto c:lamps){
            if(s.count({c[0],c[1]})) continue;
            s.insert({c[0],c[1]});
            x[c[0]]++;
            y[c[1]]++;
            dig1[c[0]-c[1]]++;
            dig2[c[0]+c[1]]++;
        }
        
        for(auto c:queries){
            if(x[c[0]]>0 || y[c[1]]>0 || dig1[c[0]-c[1]]>0 || dig2[c[0]+c[1]]>0){
                ans.push_back(1);
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        int row = c[0]+i;
                        int col = c[1]+j;
                        if((row>=0 && row<n) && (col>=0 && col<n) && s.count({row,col})){
                            x[row]--;
                            y[col]--;
                            dig1[row-col]--;
                            dig2[row+col]--;
                            s.erase({row,col});
                        }
                    }
                }
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};