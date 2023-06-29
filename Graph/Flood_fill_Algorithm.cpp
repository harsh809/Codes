// gfg Flood fill Algorithm

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image, int newColor, int initial, int deltarow[], int deltacol[]) {
    image[sr][sc] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++) {
        int row = sr + deltarow[i];
        int col = sc + deltacol[i];
        if ((row >= 0 && row < n) && (col >= 0 && col < m) && image[row][col] == initial && image[row][col]!=newColor) {
            dfs(row, col, image, newColor, initial, deltarow, deltacol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int initial = image[sr][sc];
    int deltarow[4] = {1, 0, 0, -1};
    int deltacol[4] = {0, -1, 1, 0};
    dfs(sr, sc, image, newColor, initial, deltarow, deltacol);
    return image;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends