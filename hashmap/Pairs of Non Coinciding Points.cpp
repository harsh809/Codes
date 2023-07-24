//gfg  Pairs of Non Coinciding Points

//{ Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        unordered_map<int,int> x;
        unordered_map<int,int> y;
        unordered_map<string,int> xy;
        int ans = 0;
        for(int i=0;i<N;i++){
            string s = to_string(X[i]) + "," + to_string(Y[i]);
            ans += x[X[i]] + y[Y[i]] - 2*xy[s];
            x[X[i]]++;
            y[Y[i]]++;
            xy[s]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}
// } Driver Code Ends