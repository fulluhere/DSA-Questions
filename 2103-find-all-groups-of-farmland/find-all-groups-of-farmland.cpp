class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        vector<vector<int>>ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j] == 1 && vis[i][j] == false){
                    vis[i][j] = true;
                    int maxi = i*n + j;
                    int mini = i*n + j;
                    queue<pair<int, int>>q;
                    q.push({i, j});

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        for(int k=0; k<4; k++){
                            int r = x + dr[k];
                            int c = y + dc[k];

                            if(r<0 || r>=m || c<0 || c>=n) continue;

                            if(land[r][c] == 1 && !vis[r][c]){
                                vis[r][c] = true;
                                mini = min(mini, r*n + c);
                                maxi = max(maxi, r*n + c);
                                q.push({r, c});
                            }
                        }

                    }

                    int p, t, r, s;
                    p = mini/n;
                    t = mini%n;
                    r = maxi/n;
                    s = maxi%n;
                    ans.push_back({p, t, r, s});
                }
            }
        }

        return ans;

    }
};