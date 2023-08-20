//1339. Maximum Product of Splitted Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int mod = 1e9 + 7;
    int sum(TreeNode* root,vector<int>& s){
        if(root==NULL){
            return 0;
        }
        int left = sum(root->left,s);
        int right = sum(root->right,s);
        int a = left+right+root->val;
        s.push_back(a);
        return a;
    }
    int maxProduct(TreeNode* root) {
    vector<int> s;
    int rootsum = sum(root, s);
    int n = s.size();
    long long ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans = max(ans, (1LL * ((rootsum  - s[i] ))*s[i]));
    }
    return ans%mod;
}

};