class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        long long res = (long long)sum;
        for(int i=k; i<n; i++){
            sum += nums[i];
            sum -= nums[i-k];
            res = max(res, (long long)sum);
        }

        double ans =(double) res/k;
        return ans;
    }
};