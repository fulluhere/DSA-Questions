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
    int ans = INT_MIN;
    void solve(TreeNode* head, int len){
        if(head->left==NULL && head->right == NULL){
            ans = max(ans, len);
            return;
        }
        
        if(head->left!=NULL)   
           solve(head->left, len+1);
        if(head->right!=NULL)
           solve(head->right, len+1);

    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        solve(root, 1);

        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};