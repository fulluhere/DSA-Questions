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
    vector<vector<int>>ans;
    void solve(TreeNode* head){
        if(head == nullptr){
            return;
        }
        queue<TreeNode*>q;
        q.push(head);

        while(!q.empty()){
            int len = q.size();
            vector<int>tmp;
            for(int i=0; i<len; i++){
                auto cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                tmp.push_back(cur->val);
            }

            if(ans.size()%2 != 0){
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        solve(root);
        return ans;
    }
};