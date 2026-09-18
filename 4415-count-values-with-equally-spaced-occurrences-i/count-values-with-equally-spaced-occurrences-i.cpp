class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        unordered_map<int, int>freq;

        for(int x: nums){
            freq[x]++;
        }
            
        for(int i=0;i<n; i++){
            if(freq[nums[i]]!=3){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j]){
                    int temp = j-i;
                    for(int k=j+1; k<n; k++){
                        if(nums[k] == nums[j] && ((k-j) == temp)){
                            mp[nums[i]]++;
                            
                        }
                        
                    }
                }

            }
        }

        return mp.size();
    }
};