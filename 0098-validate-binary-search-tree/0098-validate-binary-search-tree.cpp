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

    void inorder(TreeNode* root, vector<int>& in){
        if(root==NULL) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    int maxx(TreeNode* root){
        if(root==NULL) return INT_MIN;
        // int a = maxx(root->left);
        // int b = maxx(root->right);
        return max(root->val, max(maxx(root->left), maxx(root->right)));
    }

    bool helper(TreeNode* root, TreeNode* minv, TreeNode* maxv){
        if(root == NULL) return true;
        if(minv!=NULL && root->val <= minv->val) return false;
        if(maxv!=NULL && root->val >= maxv->val) return false;
        bool l = helper(root->left, minv, root);
        bool r = helper(root->right, root, maxv);
        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        // vector<int> in;
        // inorder(root, in);
        
        // for(int i=1; i<in.size(); i++){
        //     if(in[i-1]>=in[i] ) return false;
        // }
        // return true;

        // approach 2

        return helper(root, NULL, NULL);
    }
};