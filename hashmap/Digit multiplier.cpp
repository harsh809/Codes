//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string getSmallest(long long N) {
        string ans =  "";
        if(N==0){
            ans += to_string(-1);
            return ans;
        }
        if(N<10){
            ans += to_string(N);
            return ans;
        }
        for(int i=9;i>1;i--){
            while(N%i==0){
                N = N/i;
                ans += to_string(i);
            }
        }
        if(N>10){
            ans = "";
            ans += to_string(-1);
            return ans;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.getSmallest(N) << endl;
    }
    return 0;
}
// } Driver Code Ends