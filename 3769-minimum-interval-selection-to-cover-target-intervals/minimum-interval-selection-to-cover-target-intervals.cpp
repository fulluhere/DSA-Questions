class Solution {
public:
    int minSelection(vector<vector<int>>& s, vector<vector<int>>& t) {
        int n1 = s.size();
        int n2 = t.size();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        vector<vector<int>>merge;

        for(auto &v: t){
            if(merge.empty() || merge.back()[1]<v[0]){
                merge.push_back(v);
            }else{
                merge.back()[1] = max(merge.back()[1] , v[1]);
            }
        }
        int ans=0;
        int i = 0;
        int bestE = -1;
        int reach = -1;
        for(auto &v: merge){
            int L = v[0];
            int R = v[1];

            if(reach < L){
                while(i<n1 && s[i][0]<=L){
                    bestE = max(bestE, s[i][1]);
                    i++;
                }

                if(bestE<L) return -1;
                ans++;
                reach = bestE;
            }

        

            while(reach<R){
                while(i<n1 && s[i][0]<=reach){
                    bestE = max(bestE, s[i][1]);
                    i++;
                }

                if(bestE <= reach) return -1;

                ans++;
                reach = bestE;

            }
    }
        return ans;
    }
};