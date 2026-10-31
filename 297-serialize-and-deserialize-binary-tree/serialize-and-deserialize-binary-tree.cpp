/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        if(root == nullptr){
            return ans;
        }
        TreeNode* head = root;
        queue<TreeNode*>q;
        q.push(head);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node == nullptr){
                ans += "null,";
                continue;
            }

            ans += to_string(node->val) + ",";

            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string token;
        vector<string>v;

        while(getline(ss, token, ',')){
            v.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(v[0]));

        queue<TreeNode*>q;
        q.push(root);

        int i=1;

        while(!q.empty() && i<v.size()){
            auto cur = q.front();
            q.pop();

            if(v[i] != "null"){
                cur->left = new TreeNode(stoi(v[i]));
                q.push(cur->left);
            }
            i++;

            if(i<v.size() && v[i] != "null"){
                cur->right = new TreeNode(stoi(v[i]));
                q.push(cur->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));