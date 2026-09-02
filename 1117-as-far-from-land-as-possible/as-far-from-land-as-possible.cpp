class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = -1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        queue<pair<int, int>>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        if(q.empty() || q.size() == n*n) return -1;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [i, j] = q.front();
                q.pop();

                for(int k=0; k<4; k++){
                    int r = i + dr[k];
                    int c = j + dc[k];

                    if(r<0 || r>=n || c<0 || c>=n) continue;

                    if(grid[r][c] == 1){
                        continue;
                    }

                    grid[r][c] = 1;
                    q.push({r, c});
                }
            }
            ans++;
        }

        return ans;
    }
};