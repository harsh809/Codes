//coding ninja  Longest Increasing Subsequence

//tle
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n+1,0),cur(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prev=ind-1;prev>=-1;prev--){
            int len = 0 + next[prev+1];
            if(prev==-1 || arr[ind]>arr[prev]){
                len = max(len,1+next[ind+1]);
            }
            cur[prev+1] = len;
        }
        next = cur;
    }
    return next[0];
}

// printing  of longest increasing subsequence
#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1),hash(n);
    int maxi = 1;
    int lastindex = 0;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && dp[i]<1+dp[prev]){
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
        }
        if(maxi<dp[i]){
            maxi = dp[i];
            lastindex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex = hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    for(auto i:temp){
        cout<<i<" ";
    }
    cout<<endl;
    return maxi;
}



//using binary search
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    int len = 1;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
            int index = distance(temp.begin(), it);
            temp[index] = arr[i];
        }
    }
    return len;
}
//TC = O(n)  sc = o(n)