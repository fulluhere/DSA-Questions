class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>ans;
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long x = (long long)target-sum;
                    if(x<=INT_MAX && x>=INT_MIN){
                        if(mp.find(x) != mp.end()){
                            vector<int>vec = {(int)x, nums[i], nums[j], nums[k]};
                            sort(vec.begin(), vec.end());
                            ans.insert(vec);
                        }
                    }
                }
            }
            mp[nums[i]] = i;
        }
        
        vector<vector<int>>res;

        for(auto x: ans){

            res.push_back(x);
        }
        return res;
    }
};