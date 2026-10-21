class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long>pref(n+1, 0);
        int i=0;
        int j = 0;
        int ans = INT_MAX;
        while(j<n){
            pref[j+1] = pref[j] + nums[j];
            while(i<=j && pref[j+1] - pref[i]>=target){
                ans = min(ans, j-i+1);
                i++;
            }

                
            j++;
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};