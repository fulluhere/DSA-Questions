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
    void solve(TreeNode* root1, TreeNode* root2, TreeNode* tmp){
        if(root1 == nullptr || root2 == nullptr){
            return;
        }
       
        if(root1->left && root2->left){
            tmp->left = new TreeNode(root1->left->val + root2->left->val);
            solve(root1->left, root2->left, tmp->left);
        }
        else if(root1->left){
            tmp->left = root1->left;
        }else if(root2->left){
            tmp->left = root2->left;
        }
        
        
        if(root1->right && root2->right){
            tmp->right = new TreeNode(root1->right->val + root2->right->val);
             solve(root1->right, root2->right, tmp->right);
        }
        else if(root1->right){
            tmp->right = root1->right;
        }else if(root2->right){
            tmp->right = root2->right;
        }

    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr){
            return root2;
        }
        if(root2 == nullptr){
            return root1;
        }
        TreeNode* tmp = new TreeNode(root1->val + root2->val);

        solve(root1, root2, tmp);

        return tmp;
    }
};