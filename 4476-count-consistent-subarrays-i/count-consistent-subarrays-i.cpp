class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i=0; i<n; i++){
            int bit = nums[i];
            int mini = nums[i];
            res++;
            for(int j=i+1; j<n; j++){
                mini = min(mini, nums[j]);
                bit = bit & nums[j];
                if(bit == mini){
                    res++;
                }
            }
        }

        return res;
    }
};