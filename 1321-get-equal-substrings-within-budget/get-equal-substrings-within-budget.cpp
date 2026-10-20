class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
       
        int j=0;
        deque<int>dq;
        while(j<n){
            int x = abs(s[j]-t[j]);

            while(!dq.empty() && maxCost-x<0){
                int k = dq.front();
                dq.pop_front();
                maxCost += abs(s[k]-t[k]);
                
            }
            
            if(maxCost >= x){
                maxCost -= x;
                dq.push_back(j);
                ans = max(ans, j-dq.front()+1);
            }
            j++;
        }

        return ans;
    }
};