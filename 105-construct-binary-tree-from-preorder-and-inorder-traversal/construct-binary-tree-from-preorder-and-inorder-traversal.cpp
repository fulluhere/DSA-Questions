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
    void solve(vector<int>& preorder, vector<int>& inorder, TreeNode*& head, int& i, int st, int end){
        if(i>=inorder.size() || st>end){
            return;
        }
        int root = preorder[i++];
        head = new TreeNode(root);


        int idx = st;
        while(idx<=end && inorder[idx]!=root){
            idx++;
        }
        solve(preorder, inorder, head->left, i, st, idx-1);
        
        solve(preorder, inorder, head->right, i, idx+1, end);

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int i = 0;
        TreeNode* tmp = nullptr;
        solve(preorder, inorder, tmp, i, 0, n-1);
        return tmp;
    }
};