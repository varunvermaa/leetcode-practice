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

    void helper(TreeNode* root, vector<int>& a){
        if(!root) return;
        a.push_back(root->val);
        helper(root->left,a);
        helper(root->right,a);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root->right==nullptr && root->left == NULL) return -1;
        vector<int> a;
        helper(root, a);
        sort(a.begin(), a.end());
        for(int i=1; i<a.size(); i++){
            if(a[i-1]!=a[i]){
                return a[i];
            } 
    }
        return -1;
    }
};