class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = 0;
        deque<int>maxD;
        deque<int>minD;
        int l =0;

        for(int r=0; r<n; r++){
            while(!maxD.empty() && nums[r]>maxD.back()){
                maxD.pop_back();
            }
            maxD.push_back(nums[r]);

            while(!minD.empty() && nums[r]<minD.back()){
                minD.pop_back();
            }
            minD.push_back(nums[r]);

            while((maxD.front() - minD.front())>limit){
                if(nums[l] == maxD.front()){
                    maxD.pop_front();
                }
                if(nums[l] == minD.front()){
                    minD.pop_front();
                }
                l++;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
        
    }
};