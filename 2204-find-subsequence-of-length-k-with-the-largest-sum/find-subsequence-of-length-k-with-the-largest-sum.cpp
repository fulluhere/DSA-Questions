class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>tmp = nums;
        sort(tmp.rbegin(), tmp.rend());
        unordered_map<int, int>mp;
        for(int i=0; i<k; i++){
            mp[tmp[i]]++;
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
            }
        }

        return ans;
        
    }
};