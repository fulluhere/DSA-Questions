class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        //priority-queue
        int n = nums.size();

        struct compare{
            bool operator()(pair<int, int>&a, pair<int, int>&b){
                if(a.first!=b.first){
                    return  a.first>b.first;
                }
                return a.second>b.second;
            
            }
        };



        priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
        for(int i=0; i<n-k+1; i++){
            pq.push({nums[i], i});
        }
        vector<int>ans;
        int prev = -1;
        int r = n-k;
        int i = 0;
        while(i<k){
            int v = 0;
            while(!pq.empty() && v==0){
                auto [x, idx] = pq.top();
                if(idx>prev && idx >= i){
                    ans.push_back(x);
                    v=1;
                    prev = idx;
                    pq.pop();
                }else{
                    pq.pop();
                }
            }
            r++;
            if(r<n)
            pq.push({nums[r], r});
            
            i++;

        }
        return ans;

    }
};