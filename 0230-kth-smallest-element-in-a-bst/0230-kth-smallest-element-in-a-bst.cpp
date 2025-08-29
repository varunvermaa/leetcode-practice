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
    // int count = 0;
    
    // int a;
    // void helper(TreeNode* root, int k){
    //     if(root==NULL) return;
    //     helper(root->left,k);
    //     count++;
    //     if(count == k) a = root->val;
    //     helper(root->right,k);
    //     return;
    // }

    void inorder(TreeNode* root, int& k, int& ans){
        if(root==NULL) return;
        inorder(root->left, k, ans);
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        if(k>0) inorder(root->right, k, ans);
    }


    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        inorder(root, k, ans);
        return ans;
       
    }
};