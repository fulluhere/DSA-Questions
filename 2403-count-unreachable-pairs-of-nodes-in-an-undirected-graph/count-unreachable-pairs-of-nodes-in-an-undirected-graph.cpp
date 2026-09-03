class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int prev = 1;
        long long ans = 0;
        int x = n;
        vector<bool>vis(n, false);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i] = true;
                int cnt = 0;
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    cnt++;
                    for(int v: adj[u]){
                        if(!vis[v]){
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
                
                ans += 1LL*cnt*(x-cnt);
                x = x-cnt;

            }
            

        }

        return ans;
    }
};