class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
       

        for(int i=0; i<n-2; i++){
            
            int l = i+1;
            int r = n-1;

            while(l<r){
                int cur = nums[i] + nums[l] + nums[r];
                
                if(abs(target - cur) < abs(target - sum)){
                    sum = cur;
                }

                if(cur == target ){
                    return sum;
                }else if(cur < target){
                    l++;
                }else{
                    r--;
                }

            }
        }
        return sum;
    }
};