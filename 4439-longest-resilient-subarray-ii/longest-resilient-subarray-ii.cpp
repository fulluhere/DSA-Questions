class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>vec(n);

        for(int i=0; i<n; i++){
            vec[i] = nums[i]%k;
        }

        int ans  = 0;
        int i=0;
        while(i<n){
            int j = i;

            while(j<n-1 && vec[j] == vec[j+1]){
                j++;
            }
            int l = j-i+1;

            if(vec[i] == 0){
                ans = max(ans, l);
                i=j+1;
                continue;
            }
            int d = k/ gcd(k, vec[i]);
           
            int tn = 1 + (l-1)/d*d;

            ans = max(ans, tn);
            i=j+1;
        }

        return ans;
    }
};