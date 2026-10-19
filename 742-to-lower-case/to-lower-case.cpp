class Solution {
public:
    string toLowerCase(string s) {
        int n = s.size();
        string ans = "";
        for(char c: s){
            if(c>=65 && c<=90){
                ans += c + 32;
            }else{
                ans += c;
            }
        }

        return ans;
    }
};