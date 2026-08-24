class Solution {
public:

    int minLength(string s, int numOps) {
        int n = s.size();

        auto calculateForG1 = [&]() {
            int flipsToPattern1 = 0;
            int flipsToPattern2 = 0;

            for(int i=0; i<n; i++){
                if(s[i] != (i%2 == 0? '0': '1')) flipsToPattern1++;
                if(s[i] != (i%2 == 0 ? '1': '0')) flipsToPattern2++;
            }

            return min(flipsToPattern1, flipsToPattern2);
        };

        if(numOps >= calculateForG1()) return 1;

        auto isFeasible = [&](int g){
            int totOps = 0;
            char prevChar = s[0];
            int blockLen = 1;


            for(int i=1; i<n; i++){
                if(s[i] == prevChar){
                    blockLen++;
                }else{
                    totOps += (blockLen)/(g+1);
                    prevChar = s[i];
                    blockLen = 1;
                }
            }

            totOps += (blockLen)/(g+1);
            return totOps <= numOps;
        };

        int l=2;
        int r=n;
        int ans = n;

        while(l<=r){
            int m = l + (r-l)/2;
            if(isFeasible(m)){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }

        return ans;
    }
};