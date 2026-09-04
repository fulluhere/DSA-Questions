class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>vec1;
        vector<int>vec2;
        vector<vector<bool>>vis(n, vector<bool>(n, false));

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0 , -1, 1};
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();
                        if(!flag){
                            vec1.push_back(x*n+ y);
                        }else{
                            vec2.push_back(x*n + y);
                        }   
                        for(int k=0; k<4; k++){
                            int r = x + dr[k];
                            int c = y + dc[k];
                            

                            if(r<0 || r>=n || c<0 || c>=n){
                                continue;
                            }
                            if(grid[r][c] == 1 && vis[r][c] == false){
                                vis[r][c] = true;
                                q.push({r, c});


                            }

                            
                        }
                    }
                    flag = true;
                }
            }
        }

        int mini = INT_MAX;

        for(int i=0; i<vec1.size(); i++){
            int p, q;
            p = vec1[i]/n;
            q = vec1[i]%n;
            for(int j=0; j<vec2.size(); j++){
                int r, s;
                r = vec2[j]/n;
                s = vec2[j]%n;

                int dis = abs(p-r) + abs(q-s)-1;
                mini = min(mini, dis);

            }
        }

        return mini;
    }
};