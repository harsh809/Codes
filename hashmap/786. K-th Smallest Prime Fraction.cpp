//786. K-th Smallest Prime Fraction

class Solution {
public:
    // vector<long long> func(vector<int>& arr,int target){
    //     int n = arr.size();
    //     int num  = arr[0];
    //     int deno = arr[n-1];
    //     long long count = 0;
    //     int i=0;
    //     vector<long long> ans(3,0);
    //     for(int j=1;j<n;j++){
    //         if(arr[i]<=target*arr[j]){
    //             i++;
    //         }
    //         count += i;
    //         if(arr[i-1]*deno > arr[j]*num){
    //             num = arr[i-1];
    //             deno = arr[j];
    //         }
    //     }
    //     ans[0] = count;
    //     ans[1] = num;
    //     ans[2] = deno;
    //     return ans;
    // }
    // vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    //     int n = arr.size();
    //     double lo = arr[0]/(double)arr[n-1];
    //     double hi = 1;
    //     vector<int> ans(2,0);
    //     while(lo<hi){
    //         double mid = (lo+hi)/2;
    //         vector<long long> count = func(arr,mid);
    //         if(k<count[0]){
    //             hi = mid;
    //         }
    //         else if(k>count[0]){
    //             lo = mid;
    //         }
    //         else{
    //             ans[0] = count[1];
    //             ans[1] = count[2];
    //             return ans;
    //         }
    //     }
    //     return {};
    // }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};