class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long a = max(0LL, 1LL*(k-nums[0]));
        long long b = max(0LL, 1LL*(k-nums[1]));
        long long c = max(0LL, 1LL*(k-nums[2]));

        for(int i=3; i<n; i++){
            long long cost = max(0LL, 1LL*(k-nums[i]));
            long long x = cost + min({a, b, c});
            a = b;
            b = c;
            c = x;
        }

        return min({a , b, c});
    }
};