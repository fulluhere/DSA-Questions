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
    int ans = 0;
    int solve(TreeNode* head, int d){
        if(head == nullptr){
            return 0;
        }

        
          int l =   solve(head->left, d+1);
        
          int r =  solve(head->right, d+1);

            ans = max(ans, l+r);
           return 1 + max(l, r);
    }

    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        
        solve(root, 0);
        
        return ans;
    }
};