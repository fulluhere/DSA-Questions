class Solution {
public:
    bool check(long long m, vector<int>& time, int totalTrips){
        long long cnt = 0;
        int n = time.size();
        for(int i=0; i<n; i++){
            cnt += m/time[i];
            if(cnt>=totalTrips){
                return true;
            }
            
        }

        return false;
        
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        
        
        long long l = 1;
        long long r = (long long)time[0] * totalTrips;

        for(int i=1; i<n; i++){
            r = min(r, (long long)time[i]*totalTrips);
        }
        long long ans;
        while(l<=r){
            long long m = l + (r-l)/2;
            if(check(m, time , totalTrips)){
                ans = m;
                r = m-1;
            }else{
                l = m + 1;
            }
        }


        return ans;
    }
};