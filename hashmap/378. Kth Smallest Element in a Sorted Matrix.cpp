//378. Kth Smallest Element in a Sorted Matrix

class Solution {
public:
    // int f(vector<vector<int>>& matrix,int k,int mid){
    //     int count = 0;
    //     int n = matrix.size();
    //     int j = n-1;
    //     for(int i=0;i<n;i++){
    //         for(j;j>=0;j--){
    //             if(matrix[i][j]<=mid){
    //                 count += j+1;
    //                 break;
    //             }
    //         }
    //     }
    //     return count;
    // }
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     int n = matrix.size();
    //     int low = matrix[0][0];
    //     int high = matrix[n-1][n-1];
    //     while(low<high){
    //         int mid = (low+high)/2;
    //         int count = f(matrix,k,mid);
    //         if(count>=k){
    //             high = mid;
    //         } 
    //         else{
    //             low  = mid+1;
    //         }
    //     }
    //     return low;
    // }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};