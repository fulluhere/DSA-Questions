class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        vector<int>vec = costs;
        int t = k;
        int sz = candidates;
        long long ans = 0;

        if(n<=2*sz){
            sort(vec.begin(), vec.end());
            for(int i=0; i<t; i++){
                ans += vec[i];
            }
            return ans;
            
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }

            return a.second > b.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> h1(cmp);

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> h2(cmp);
            
    
        for(int i=0; i<sz; i++){
            h1.push({vec[i], i});
        }
    
        for(int i=n-1; i>n-1-sz; i--){
            h2.push({vec[i], i});
        }

        int l = sz;
        int r = n-1-sz;
        
        while(t--){



            if(h1.empty()){
                auto [y, yi] = h2.top();
                 ans += y;
                h2.pop();
                
                if(l<=r){
                    h2.push({vec[r], r});
                    r--;
                }
            }
            else if(h2.empty()){
                auto [x, xi] = h1.top();
                 ans += x;
                h1.pop();
                
                if(l<=r){
                    h1.push({vec[l], l});
                    l++;
                }
            }
            else{
                auto [x, xi] = h1.top();
                auto [y, yi] = h2.top();
                if(x<=y){
                        ans += x;
                        h1.pop();
                        
                        if(l<=r){
                            h1.push({vec[l], l});
                            l++;
                        }
                    }
                else{
                    ans += y;
                    h2.pop();
                    
                    if(l<=r){
                        h2.push({vec[r], r});
                        r--;
                    }
                }
            
            }
        
        }
 

        return ans;
    }
};