class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            int l = 1;
            unordered_map<int, int>rank;
            unordered_map<int, int>mp;
            for(int j=i; j<n; j++){
                if(rank.find(nums[j])==rank.end()){
                    rank[nums[j]] = l;
                    l++;
                }
                mp[nums[j]]++;
                if(mp[nums[j]]>rank[nums[j]]){
                    break;
                }

                
                    bool flag = true;
                    for(auto &[x, v]: mp){
                        if(v !=rank[x]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                       cnt++;
                
            }
        }

        return cnt;
    }
};