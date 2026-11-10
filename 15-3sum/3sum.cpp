class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>ans;

        unordered_map<int, int>mp;
        int s = 0;
        for(int i=0; i<n; i++){
            
            for(int j = i+1; j<n; j++){
                s = nums[i] + nums[j];

                if(mp.find(-s)!= mp.end()){
                    vector<int>tmp = {-s, nums[i], nums[j]};
                    sort(tmp.begin(), tmp.end());
                    ans.insert(tmp);

                    
                }
            }
            mp[nums[i]]++;
        }
        vector<vector<int>>res;

        for(auto &v: ans){
            res.push_back(v);
        }
        return res;

    }
};