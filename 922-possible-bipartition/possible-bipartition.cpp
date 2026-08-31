class Solution {
public:

    bool dfs(int node, int clr, vector<vector<int>>& adj, vector<int>&color){
        color[node] = clr;
        for(auto nbr: adj[node]){
            if(color[nbr] == -1){
                if(!dfs(nbr, 1-clr, adj, color)) return false;
            }

            if(color[nbr] == color[node]) return false;
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);

        for(auto t: dislikes){
            int u = t[0];
            int v = t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                if(!dfs(i, 0, adj, color)) return false;
            }
        }

        return true;
    }
};