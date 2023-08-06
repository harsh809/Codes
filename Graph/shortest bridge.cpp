// leetcode shortest bridge

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, queue<pair<int, int>> &q)
    {
        vis[row][col] = 1;
        q.push({row, col});
        int n = mat.size();
        int m = mat[0].size();
        int del_row[4] = {1, 0, -1, 0};
        int del_col[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int adjr = row + del_row[i];
            int adjc = col + del_col[i];
            if ((adjr >= 0 && adjr < n) && (adjc >= 0 && adjc < m) && mat[adjr][adjc] == 1 && !vis[adjr][adjc])
            {
                dfs(adjr, adjc, mat, vis, q);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    dfs(i, j, mat, vis, q);
                    found = true;
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        int del_row[4] = {1, 0, -1, 0};
        int del_col[4] = {0, 1, 0, -1};
        int step = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size-- > 0)
            {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;
                for (int i = 0; i < 4; i++)
                {
                    int adjr = row + del_row[i];
                    int adjc = col + del_col[i];
                    if ((adjr >= 0 && adjr < n) && (adjc >= 0 && adjc < m) && !vis[adjr][adjc])
                    {
                        if (mat[adjr][adjc] == 1)
                        {
                            return step;
                        }
                        q.push({adjr, adjc});
                        vis[adjr][adjc] = 1;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};