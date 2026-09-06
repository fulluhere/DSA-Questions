class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long left = 0;
        long long right = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(i<n/2){
                left+=nums[i];
            }

        }
        right = sum - left;
        if(left>right){
            cnt++;
        }

        for(int i=0; i<n-1; i++){
            left -= nums[i];
            
            left += nums[(n/2+i)%n];
            
            
            right = sum-left;

            if(left>right){
                cnt++;
            }

        }

        return cnt;
    }
};