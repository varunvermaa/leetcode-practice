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

    bool issame(TreeNode* r, TreeNode* t){
        if(r == nullptr || t == nullptr ) return t==r;
        bool isl = issame(r->left, t->left);
        bool isr = issame(r->right, t->right);
        return (isl && isr && r->val==t->val);
    }

    TreeNode* invert(TreeNode* root){

        if(root==NULL) return NULL;
        TreeNode* l = invert(root->left);
        TreeNode* r = invert(root->right);
        root->left = r;
        root->right = l;
        return root;

    }

    TreeNode* copy(TreeNode* root){
        if(root == nullptr) return NULL;

        TreeNode* t = new TreeNode(root->val);
        
        t->left = copy(root->left);
        t->right = copy(root->right);
        return t;
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* t = copy(root);
        
        invert(t);
        return issame(root, t);
    }
};