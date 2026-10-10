class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        //priority-queue
        int n = nums.size();
        
        vector<int>ans;

        for(int i=0; i<n; i++){
            while(!ans.empty() && ans.back()>nums[i] && ans.size()+ n-i>k){
                ans.pop_back();
                
            }
            ans.push_back(nums[i]);

        }
        ans.resize(k);
        return ans;

    }
};