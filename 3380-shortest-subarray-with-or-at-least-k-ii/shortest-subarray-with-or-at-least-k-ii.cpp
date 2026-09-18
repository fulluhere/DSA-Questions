class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>bitCount(32, 0);
        int l = 0;
        int currOR = 0;
        int ans = INT_MAX;
        for(int r=0; r<n; r++){
            for(int b=0; b<32; b++){
                if(nums[r] & (1<<b)){
                    bitCount[b]++;
                    currOR |= (1<<b);
                }
            }
            while(currOR>=k && l<=r){
                ans = min(ans, r-l+1);
                for(int b=0; b<32; b++){
                    if(nums[l] & (1<<b)){
                        bitCount[b]--;

                        if(bitCount[b] == 0){
                            currOR &= ~(1<<b);
                        }
                        
                    }
                }
                l++;
            }
        }
        return ans == INT_MAX? -1:ans;

    }
};