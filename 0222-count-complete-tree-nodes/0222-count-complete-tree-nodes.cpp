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
    int size = 0;
    int countNodes(TreeNode* root) {
        if(root == NULL) return size;
        int lc = countNodes(root->left);        
        int rc = countNodes(root->right);
        size++;
        return size;
    }
};