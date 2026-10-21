
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int cnt = 0;
        int ans = 0;

        for (int j = 0; j < n; j++) {
            cnt += nums[j] % 2;

            while (cnt > k) {
                cnt -= nums[i] % 2;
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
