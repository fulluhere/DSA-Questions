class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>>vec(2*n, vector<int>(2, 0));
        int j= 0;
        for(int i=0; i<n && j<2*n; i++){
            vec[j][0] = a[i][0];
            vec[j][1] += 1;
            j++;
            vec[j][0] = a[i][1]+1;
            vec[j][1] += -1;
            j++;

        }

        sort(vec.begin(), vec.end());

        long long prev = 0;
        
        long long ans = 0;

        for(int i=0; i<vec.size(); i++){
            if(vec[i][1] == 1){
                ans += prev;
                prev++;
            }else{
                prev--;
            }

        }
        return ans;
    }
};