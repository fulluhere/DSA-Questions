class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<bool>vis(n, false);
        vector<int>idg(n);

        for(int i=0; i<n; i++){
            for(int x: graph[i]){
                adj[x].push_back(i);
                idg[i]++;
            }
        }

        vector<bool>isSafe(n, false);

        queue<int>q;
        for(int i=0; i<n; i++){
            if(idg[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();
            isSafe[x] = true;

            for(int v: adj[x]){
                idg[v]--;
                if(idg[v] == 0){
                    q.push(v);
                }
            }
        }

        vector<int>ans;

        for(int i= 0; i<n; i++){
            if(isSafe[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};