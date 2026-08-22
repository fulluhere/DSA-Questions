class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();
        vector<int>pref(n);
        int totOnes = 0;

        for(int i=0; i<n; i++){
            totOnes += (s[i] == '1');
            pref[i] = totOnes;
        }

        vector<bool>ans;

        for(string &t: strs){
            int lo = 0;
            int hi = 0;

            bool ok = true;

            for(int i=0; i<n; i++){
                if(t[i] == '1'){
                    lo++;
                    hi++;
                }else if(t[i] == '?'){
                    hi++;
                }

                hi = min(hi, pref[i]);

                if(lo>hi){
                    ok = false;
                    break;
                }
            }

            if(!ok){
                ans.push_back(false);
                continue;
            }

            ans.push_back(lo <= totOnes && totOnes<=hi);
        }

        return ans;
    }
};