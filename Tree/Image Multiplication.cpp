//gfg Image Multiplication

class Solution
{
    public:
    int mod = 1e9+7;
    void f(Node* root1,Node* root2,long long& sum){
        if(root1==NULL || root2==NULL) return;
        
        sum = (sum%mod + (root1->data*root2->data)%mod)%mod;
        
        f(root1->left,root2->right,sum);
        f(root1->right,root2->left,sum);
    }
    long long imgMultiply(Node *root)
    {
        long long sum = root->data * root->data;
        f(root->left,root->right,sum);
        return sum;
    }
};