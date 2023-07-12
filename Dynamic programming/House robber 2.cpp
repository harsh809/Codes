// coding ninja   house robber

#include <bits/stdc++.h> 
long long int maximumNonAdjacentSum(vector<int> &nums){
    long long int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;
    for(long long int i=1;i<n;i++){
        long long int take = nums[i];
        if(i>1){
            take += prev2;
        }
        long long int nottake = 0 + prev;
        long long int curr = max(take,nottake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1, temp2;
    long long int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(long long int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}