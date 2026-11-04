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
    int solve(TreeNode* head){
        if(head == nullptr){
            return 0;
        }
        int left = max(solve(head->left), 0);
        int right = max(solve(head->right), 0); 
        
        ans = max(ans, head->val + left + right);
        return head->val +  max(left , right);

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};