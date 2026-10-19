class Solution {
public:

    bool check(vector<int>&tar, vector<int>&chk){
        for(int i=0; i<26*2; i++){
            if(tar[i]>chk[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        vector<int>tar(26*2, 0);
        for(int i=0; i<t.size(); i++){
            if(t[i]>='A' && t[i]<='Z'){
                tar[t[i]-'A'+26]++;
            }else{
                tar[t[i]-'a']++;
            }
            
        }

        int i=0, j=0;

        vector<int>chk(26*2, 0);


        int l=-1;
        int r = j;
        int ans = INT_MAX;
        while(j<n){
            if(s[j]>='A' && s[j]<='Z'){
                chk[s[j]-'A'+26]++;
            }else{
                chk[s[j]-'a']++;
            }
            j++;

            while(i<j && check(tar, chk)){
                if(j-i<ans){
                    l = i;
                    r = j-1;
                    ans = r-l+1;
                }
                if(s[i]>='A' && s[i]<='Z'){
                    chk[s[i]-'A'+26]--;
                }else{
                    chk[s[i]-'a']--;
                }
                i++;
            }
            
        }
        
        if(l==-1 || ans==INT_MAX){
            return "";
        }
        return s.substr(l, ans);

    }
};