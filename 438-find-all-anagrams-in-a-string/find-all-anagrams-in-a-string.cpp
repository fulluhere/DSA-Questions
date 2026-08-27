class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        
        unordered_map<char, int>mp;
        unordered_map<char, int>chk;
        vector<int>ans;

        if(n<m){
            return ans;
        }
        for(int i=0; i<m; i++){
            char ch = p[i];
            mp[ch]++;
            chk[s[i]]++;
        }


        int j=0, k=m-1;
        while(j<=k && k<n){
            if(mp == chk){
                ans.push_back(j);

            }
            chk[s[j]]--;
            if(chk[s[j]] == 0){
                chk.erase(s[j]);
            }
            if(k+1<n)
                chk[s[k+1]]++;
            j++;
            k++;

        }
        
        return ans;
    }
};