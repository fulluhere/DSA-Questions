class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        mp['a'] = 0;
        mp['b'] = 0;
        mp['c'] = 0;
        int ans = 0;

        int i=0;
        int j=0;

        while(j<n){
            mp[s[j]]++;
            while(i<n && mp['a']>0 && mp['b']>0 && mp['c']>0){
                ans += n-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }


        return ans;
    }
};