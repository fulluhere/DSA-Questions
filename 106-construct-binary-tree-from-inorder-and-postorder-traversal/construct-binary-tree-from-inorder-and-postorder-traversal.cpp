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

    void solve(vector<int>& inorder, vector<int>& postorder, TreeNode*& head, int& i, int st, int end){
        if(i<0 || st>end){
            return;
        }

        TreeNode* root = new TreeNode(postorder[i--]);
        head = root;
        int idx = st;
        while(idx<=end && inorder[idx]!= root->val){
            idx++;
        }
        solve(inorder, postorder, head->right, i, idx+1, end);

        solve(inorder, postorder, head->left, i, st, idx-1);
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        TreeNode* tmp = nullptr;
        int i = n-1;
        solve(inorder, postorder, tmp, i, 0, n-1);
        return tmp;
    }
};