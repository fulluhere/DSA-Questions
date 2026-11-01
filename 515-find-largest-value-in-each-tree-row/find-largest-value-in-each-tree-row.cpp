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
    vector<int>ans;


    void solve(TreeNode* head){
        if(head == nullptr){
            return;
        }

        queue<TreeNode*>q;
        q.push(head);

        while(!q.empty()){
            int len = q.size();
            int maxi = INT_MIN;
            for(int i=0; i<len; i++){
                auto cur = q.front();
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);

                maxi = max(maxi, cur->val);

            }
            ans.push_back(maxi);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        solve(root);
        return ans;
    }
};