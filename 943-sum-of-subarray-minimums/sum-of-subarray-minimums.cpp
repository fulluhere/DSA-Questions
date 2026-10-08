class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<pair<int, int>>st1;
        stack<pair<int, int>>st2;
        int mod = 1e9 + 7;
        int sum = 0;
        for(int i=n-1; i>=0; i--){
            while(!st1.empty() && arr[i]<st1.top().first){
                st1.pop();
            }

            if(st1.empty()){
                right[i] = n-i;
            }
            else{
                right[i] = st1.top().second-i;
            }
            st1.push({arr[i], i});



        }
        for(int i=0; i<n; i++){
            while(!st2.empty() && arr[i]<=st2.top().first){
                st2.pop();
            }

            if(st2.empty()){
                left[i] = i+1;
            }
            else{
                left[i] = i - st2.top().second;
            }
            st2.push({arr[i], i});



        }

        for(int i=0; i<n; i++){
            long long x = (1LL*arr[i] * left[i]%mod*right[i])%mod;
            sum = (sum+x)%mod;
        }

        return sum;
    }
};