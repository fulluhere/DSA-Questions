class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n-1;
        int ans = -1;
        while(l<=r){
            int m = l + (r-l)/2;
            
            if(nums[m] == target){
                ans = m;
                break;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<=target && nums[m]>= target){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
            else if(nums[r]>=nums[m]){
                if(nums[m]<=target && nums[r]>= target){
                    l=m+1;
                }else{
                    r=m-1;
                }

            }
        }
        return ans;
    }
};