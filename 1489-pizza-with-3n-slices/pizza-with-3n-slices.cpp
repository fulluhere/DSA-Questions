class Solution {
public:
    int solve(vector<int>&arr, int k){
        int n = arr.size();
        
        vector<vector<int>>dp(n+1, vector<int>(k+1, INT_MIN));
        dp[0][0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                dp[i][j] = dp[i-1][j];
                if(j>0){
                    if(i==1){
                        dp[i][j] = max(dp[i][j], arr[i-1]);
                    }else{
                        dp[i][j] = max(dp[i][j], dp[i-2][j-1] + arr[i-1]);
                    }
                }

                    
            }
        }

        return dp[n][k];

    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n/3;
        vector<int>case1(slices.begin()+1, slices.end());
        vector<int>case2(slices.begin(), slices.end()-1);

        int ans1 = solve(case1, k);
        int ans2 = solve(case2, k);

        return max(ans1, ans2);
    }
};