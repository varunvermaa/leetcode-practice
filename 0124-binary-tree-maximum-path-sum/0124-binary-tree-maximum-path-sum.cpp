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

    int sum=INT_MIN;

    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int lh = max(0,helper(root->left));
        int rh = max(0,helper(root->right));
        sum = max(sum, lh+rh+root->val);
        
        return max(lh, rh)+ root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return root->val;
        int a =  helper(root);
        return sum;
    }
};