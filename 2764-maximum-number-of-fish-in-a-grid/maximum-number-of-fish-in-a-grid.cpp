class Solution {
public:

    int dfs(int i, int j,  vector<vector<int>>& grid, vector<vector<bool>>&vis){
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j] == 0) return 0;
    
        vis[i][j] = true;

        int fish = grid[i][j];

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int k=0; k<4; k++){
            int r = i + dr[k];
            int c = j + dc[k];

            fish += dfs(r, c, grid, vis);
            
        }
        return fish;
    }


    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    ans = max(ans, dfs(i, j, grid, vis));
                }
            }
        }

        return ans;
    }
};