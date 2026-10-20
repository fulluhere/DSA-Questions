class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<vector<int>>adj(n);


        vector<int>ind(n, 0);
        vector<int>outd(n, 0);


        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            if(colors[u] == 'R' && colors[v] == 'B'){
                adj[u].push_back(v);
                outd[u]++;
                ind[v]++;
            }
            else if(colors[u] == 'B' && colors[v] == 'W'){
                adj[u].push_back(v);
                outd[u]++;
                ind[v]++;
            }
            else if(colors[u] == 'W' && colors[v] == 'R'){
                adj[u].push_back(v);
                outd[u]++;
                ind[v]++;
            }
            else if(colors[u] == 'B' && colors[v] == 'R'){
                adj[v].push_back(u);
                outd[v]++;
                ind[u]++;
            }
            else if(colors[u] == 'W' && colors[v] == 'B'){
                adj[v].push_back(u);
                outd[v]++;
                ind[u]++;
            }
            else if(colors[u] == 'R' && colors[v] == 'W'){
                adj[v].push_back(u);
                outd[v]++;
                ind[u]++;
            }

        }
        int root = 0;
        int ans = -1;
        for(int i=0; i<n; i++){
            if(ind[i] == 0 && outd[i] <=2){
                root++;
                ans = i;
            }

            else if(outd[i]>2){
                return -1;
            }
        }

        if(root>1){
            return -1;
        }

        return ans;
    }
};