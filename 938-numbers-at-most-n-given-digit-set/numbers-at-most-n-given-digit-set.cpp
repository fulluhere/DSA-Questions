class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s= to_string(n);
        int len = s.size();
        int dk = digits.size();

        int ans = 0;

        for(int k=1; k<len; k++){
            ans += pow(dk, k);
        }

        for(int i=0; i<len; i++){
            bool found = false;
            for(int j=0; j<dk; j++){
                if(digits[j][0]<s[i]){
                    ans += pow(dk, len-i-1);
                }else if(digits[j][0] == s[i]){
                    found = true;
                    break;
                }
            }

            if(!found){
                return ans;
            }
        }

        return ans+1;
    }
};