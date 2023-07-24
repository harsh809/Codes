#include <bits/stdc++.h>
using namespace std;
long long solve(long long* arr,long long n){
    unordered_map<long long,long long> mp;
    for(long long i=0;i<n;i++){
        mp[arr[i]-i]++;
    }
    long long total = 0;
    for(auto it:mp){
        int x = it.second;
        total += (x*(x-1))/2;
    }
    return total;
}
int main(){
    long long t;
    cin>>t;
    while(t){
        long long n;
        cin>>n;
        long long* arr = new long long[n];
        for(long long i = 0;i<n;i++){
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<endl;
        t--;
    }
}