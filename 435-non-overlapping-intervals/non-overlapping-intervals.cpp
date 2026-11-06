class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1]<b[1];
        });
        int lastcount = intervals[0][1];
        for(int i=1; i<n; i++){
            if(lastcount>intervals[i][0]){
                cnt++;
               
            }else{
                lastcount = intervals[i][1];
            }
        }

        return cnt;
    }
};