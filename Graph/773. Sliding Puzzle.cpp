//773. Sliding Puzzle

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string tag = "123450";
        string initial = "";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                initial += to_string(board[i][j]);
            }
        }
        vector<vector<int>> move(6);
        move = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        set<string> vis;
        int level = 0;
        queue<string> q;
        q.push(initial);
        vis.insert(initial);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string org = q.front();
                q.pop();
                if(tag == org){
                    return level;
                }
                int idx = 0;
                for(int i=0;i<6;i++){
                    if(org[i]=='0'){
                        idx = i;
                        break;
                    }
                }
                string temp = org;
                vector<int> it = move[idx];
                for(auto c:it){
                    swap(temp[c],temp[idx]);
                    if(!vis.count(temp)){
                        q.push(temp);
                        vis.insert(temp);
                    }
                    swap(temp[c],temp[idx]);
                }
            }
            level++;
        }
        return -1;
    }
};