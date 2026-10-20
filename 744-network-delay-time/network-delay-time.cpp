class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        vector<int>dis(n+1, INT_MAX);
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0, k});
        dis[k] = 0;
        int ans = INT_MIN;
        while(!pq.empty()){
            auto [wt, u] = pq.top();
            pq.pop();

            if(wt>dis[u]) continue;
            for(auto  &[v, w]: adj[u]){
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(dis[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dis[i]);
        }

        if(ans == INT_MIN){
            return -1;
        }
        return ans;

    }
};