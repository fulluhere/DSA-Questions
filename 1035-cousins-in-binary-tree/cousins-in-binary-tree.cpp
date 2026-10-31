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
    int d1 = -1;
    int d2 = -1;
    TreeNode* p1 = nullptr;
    TreeNode* p2 = nullptr;
    void solve(TreeNode* root, TreeNode* parent, int x, int y, int d){
        if(root == nullptr){
            return;
        }
        if(d1!=-1 && d2!=-1){
            return;
        }
        if(root->val == x){
            d1 = d;
            p1 = parent;
            
        }
        if(root->val == y){
            d2 = d;
            p2 = parent;
        }
        solve(root->left, root, x, y, d+1);
        solve(root->right, root, x, y, d+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
       
        solve(root, nullptr,  x, y, 0);
        if(d1==d2 &&  p1!=p2){
            return true;
        }
        return false;
    }
};