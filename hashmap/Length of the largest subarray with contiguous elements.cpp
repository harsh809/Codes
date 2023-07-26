//gfg Length of the largest subarray with contiguous elements
#include <bits/stdc++.h>
using namespace std;

int findLength(int arr[],int n){
    
    int ans = 1;
    for(int i=0;i<n-1;i++){
        int maxi = arr[i];
        int mini = arr[i];
        unordered_set<int> s;
        s.insert(arr[i]);
        for(int j=i+1;j<n;j++){
            if(s.count(arr[j])){
                break;
            }
            s.insert(arr[j]);;
            maxi = max(maxi,arr[j]);
            mini = min(mini,arr[j]);
            if(maxi-mini == j-i){
                int len = j-i+1;
                ans = max(ans,len);
            }
        }
    }
    return ans;
}
int main ()
{
    int arr[] = {10, 12, 12, 10, 10, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest contiguous"<< " subarray is " << findLength(arr, n);
}