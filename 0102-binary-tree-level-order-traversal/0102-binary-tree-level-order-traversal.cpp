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

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> a;
        if(root == NULL) return a;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            int s = q.size();
            vector<int> l;
            for(int i = 0; i<s; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                l.push_back(temp->val);
            }
            a.push_back(l);
        }
        
        return a;
    }
};