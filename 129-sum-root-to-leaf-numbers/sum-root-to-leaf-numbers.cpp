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
    void solve(TreeNode* head, string s){
        if(head == nullptr){

            return;
        }
        s = s+ to_string(head->val);
        if(head->left == nullptr && head->right == nullptr){
            int cur = stoi(s);
            ans += cur;

        }

        solve(head->left, s);
        solve(head->right, s);
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        solve(root, s);
        return ans;
    }
};