class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r = n-1;
        int ans = nums[l];
        while(l<=r){
            int m = l + (r-l)/2;
            ans = min(ans, nums[m]);

            if(nums[l]<=nums[m]){
                ans = min(ans, nums[l]);
                l = m+1;
            }else{
                r = m-1;
            }
        }

        return ans;
    }
};