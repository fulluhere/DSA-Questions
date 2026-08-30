class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=-1; i<n; i++){
            vector<int>arr;

            for(int j=0; j<n; j++){
                if(i==j) continue;
                arr.push_back(nums[j]);
            }

            int m = arr.size();
            if(m<2) continue;

            vector<int>pref(m);
            vector<int>suff(m);

            pref[0] = arr[0];
            for(int j=1; j<m; j++){
                pref[j] = gcd(pref[j-1], arr[j]);
            }

            suff[m-1] = arr[m-1];
            for(int j=m-2; j>=0; j--){
                suff[j] = gcd(suff[j+1], arr[j]);
            }

            int score = 0;

            for(int j=0; j<m-1; j++){
                if(pref[j] == suff[j+1]){
                    score++;
                }
            }
            ans = max(ans, score);

        }
        return ans;
    }
};