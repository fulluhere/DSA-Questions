class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        string ans = "";
        int mod = 1e9+7;
        int sign = 1;

        int i=0;

        while(i<n && s[i] == ' '){
            i++;
        }
        
        if(i<n && s[i] == '-'){
            sign = -1;
            i++;
        }

        else if (i<n && s[i] == '+'){
            i++;
        }

        while(i<n && s[i] == '0'){
            i++;
        }

        while(i<n && s[i]-'0'>=0 && s[i]-'0'<=9){
            ans += s[i];
            i++;
        }
        



        long long res = 0;

        for(int j = 0; j<ans.size(); j++){
            res = 1LL*(res*10) + (ans[j]-'0');
            if(sign*res<=INT_MIN){
                return INT_MIN;
            }
            if(sign*res>=INT_MAX){
                return INT_MAX;
            }

        }




        return sign*res;
    }
};