class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<int>spf(mx+1);

        for(int i=0; i<=mx; i++){
            spf[i] = i;
        }

        for(int i=2; i*i<=mx; i++){
            if(spf[i] == i){
                for(int j = i*i; j<=mx; j += i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }


        unordered_map<int, vector<int>>mp;

        for(int i=0; i<n; i++){
            int x = nums[i];

            while(x>1){
                int p = spf[x];
                mp[p].push_back(i);

                while(x%p == 0){
                    x /= p;
                }
            }
        }
        
        vector<int>dist(n, -1);
        vector<bool>used(mx+1, false);

        queue<int>q;
        q.push(0);
        dist[0] = 0;

        while(!q.empty()){
            int i = q.front(); 
            q.pop();

            if(i==n-1){
                return dist[i];
            }

            if(i-1 >= 0 && dist[i-1] == -1){
                dist[i-1] = dist[i] + 1;
                q.push(i-1);
            }

            if(i+1 < n && dist[i+1] == -1){
                dist[i+1] = dist[i] + 1;
                q.push(i+1);
            }
            int p = nums[i];

            if(p>1 && spf[p] == p && !used[p]){
                used[p] = true;

                for(int j: mp[p]){
                    if(dist[j] == -1){
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }
                mp[p].clear();
            }

        }

        return -1;

    }
};