class Solution {
public:
    

    int  dfs(int i, vector<vector<int>>&g, vector<int>& score, vector<int>& op){
        if(g[i].empty()){
            return score[i];
        }

        int res = score[i];
        int mn = INT_MAX;

        for(int j: g[i]){
            int val = dfs(j, g, score, op);
            res += val;
            mn = min(mn, val);
        }

        if(op[i] || mn<0){
            res -= mn;
        }
        return res;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>>g(n);
        for(int i=1; i<n; i++){
            g[parent[i]].push_back(i);
        }
        return dfs(0, g, score, op);
        
    }
};