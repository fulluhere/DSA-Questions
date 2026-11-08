class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        int n = s1.size();
        int i = 0;
        while(i<n){
            int s = i;
            while(i<n && s1[i]!= s2[i]){
                i++;
            }

            if(s!=i){
                ans.push_back({s1.substr(s, i-s), s2.substr(s, i-s)});
                
            }

            i++;
        }

        return ans;
    }
};