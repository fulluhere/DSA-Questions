class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        int cnt = 0;
        

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((nums[i][0] <= nums[j][0] && nums[i][1] >= nums[j][0]) ||   (nums[i][0] <= nums[j][1] && nums[i][1] >= nums[j][0])){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};