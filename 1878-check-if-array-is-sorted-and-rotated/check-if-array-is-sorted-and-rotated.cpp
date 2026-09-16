class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int edge = nums[0];
        int i, j;
        for(i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){

                break;
            }
        }

        for(j=i+1; j<n-1; j++){
            if(nums[j+1]<nums[j]){
                return false;
            }else if(edge<nums[j]){
                return false;
            }
        }
        if(j<n && edge<nums[j]){
                return false;
        }

        return true;
    }
};