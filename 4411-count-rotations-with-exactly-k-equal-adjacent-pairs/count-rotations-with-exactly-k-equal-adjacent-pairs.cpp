class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int score = 0;
        string x = s;
        for(int i=0; i<n; i++){
            string ns = x.substr(1) + x[0];
            x = ns;
            int cnt = 0;
            for(int i=0; i<n-1; i++){
                if(ns[i] == ns[i+1]){
                    cnt++;
                }
            }
            if(cnt == k){
                score++;
            }

        }
        return score;
    }
};