//1145. Binary Tree Coloring Game

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
    void find(TreeNode* root,int x,TreeNode* &tg){
        if(root==NULL){
            return;
        }
        if(root->val==x){
            tg = root;
            return;
        }
        find(root->left,x,tg);
        find(root->right,x,tg);
    }
    void count(TreeNode* root,int &left){
        if(root==NULL) return;
        left++;
        count(root->left,left);
        count(root->right,left);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* tg = NULL;
        find(root,x,tg);
        int left = 0;
        int right = 0;
        count(tg->left,left);
        count(tg->right,right);
        int parent = n-(left+right+1);
        int maxi = max(parent,max(left,right));
        if(maxi>n/2){
            return true;
        }
        return false;
    }
};