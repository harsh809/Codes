//gfg Tricky Sorting Cost

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int sortingCost(int N, int arr[]){
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        for(int i=0;i<N;i++){
            if(mp[arr[i]-1]){
                mp[arr[i]] = mp[arr[i]-1]+1;
                maxi = max(maxi,mp[arr[i]]);
                continue;
            }
            mp[arr[i]]++;
        }
        return N-maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        Solution ob;
        
        cout<<ob.sortingCost(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends