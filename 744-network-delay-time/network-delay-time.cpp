class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int e = times.size();

        vector<vector<pair<int, int>>>adj(n+1);
        vector<int>dist(n+1, INT_MAX);
        for(int i=0; i<e; i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            for(auto nbr : adj[cur.second]){
                int v = nbr.first;
                int d = nbr.second;

                if(dist[v]>dist[cur.second] + d){
                   dist[v]=dist[cur.second] + d;
                   pq.push({dist[v], v});
                }
            }
        }

        int res;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }

            res = max(res, dist[i]);
        }
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};