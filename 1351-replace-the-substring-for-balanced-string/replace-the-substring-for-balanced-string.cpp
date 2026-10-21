class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int ans = n;

        int i=0;
        int j=0;
        unordered_map<char, int>mp;
        mp['Q'] = 0;
        mp['R'] = 0;
        mp['W'] = 0;
        mp['E'] = 0;
        for(char x: s){
            mp[x]++;
        }

        while(j<n){
            mp[s[j]]--;
            while(i<n && mp['Q']<=n/4 && mp['W']<=n/4 && mp['R']<=n/4 && mp['E']<=n/4){
                ans = min(ans, j-i+1);
                
                mp[s[i]]++;
                i++;
            }
            
            j++;
        }

        if(ans == n) return 0;

        return ans;
    }
};