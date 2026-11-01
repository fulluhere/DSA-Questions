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
    vector<pair<pair<int, int>, int>>ans;

    void solve(TreeNode* head, int r, int c){
        if(head == nullptr){
            return;
        }
        ans.push_back({{r, c}, head->val});

        solve(head->left, r+1, c-1);
        solve(head->right, r+1, c+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root== nullptr) return {};
        solve(root, 0, 0);
        sort(ans.begin(), ans.end(), [](auto &a, auto &b){
            if(a.first.second != b.first.second)
                return a.first.second < b.first.second;

            if(a.first.first != b.first.first)
                return a.first.first < b.first.first;

            return a.second<b.second;
        });
        vector<vector<int>>res;
        vector<int>tmp;

        int prevCol = ans[0].first.second;

        for(int i=0; i<ans.size(); i++){
            int col = ans[i].first.second;

            if(col!=prevCol){
                res.push_back(tmp);
                tmp.clear();
                prevCol = col;
            }
            tmp.push_back(ans[i].second);
        }

        res.push_back(tmp);
        return res;
    }
};