class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;

        for(auto& currRow : matrix){
            vector<int>inverted(n);

            for(int i=0; i<n; i++){
                inverted[i] = (currRow[i]==0)? 1: 0;
            }
            int cnt = 0;

            for(auto& row: matrix){
                if(row == currRow || row == inverted){
                    cnt++;
                }
            }

            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};