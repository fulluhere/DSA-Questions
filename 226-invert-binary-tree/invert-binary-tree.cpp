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
    void solve(TreeNode* tmp, TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->right!=nullptr){
        tmp->left = new TreeNode(root->right->val);
        solve(tmp->left, root->right);}

        if(root->left != nullptr){
        tmp->right = new TreeNode(root->left->val);
        
        solve(tmp->right, root->left);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        TreeNode* tmp = new TreeNode(root->val);
        solve(tmp, root);
        return tmp;
        
    }
};