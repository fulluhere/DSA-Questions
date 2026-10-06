class Solution {
public:

    void insert(int x, vector<int>& b){
        
        b.push_back(x);
        int sz = b.size();

        sz = sz - 1;
        int c = sz;
        int p = (sz-1)/2;

        while(p>=0 && b[p]>b[c]){
            swap(b[p], b[c]);
            
            c = p;
            p = (c-1)/2;
        }
    


    }

    int del(vector<int>&b){
        int sz = b.size();
        int x = b[0];
        swap(b[0], b[sz-1]);
        b.pop_back();

        sz--;
        int c = 0;
        while(true){
            int l = 2*c + 1;
            int r = 2*c + 2;
            int s = c;
            if(l<sz && b[l]<b[s]){
                s = l;
            }
            if(r<sz && b[r]<b[s]){
                s = r;
            }

            if(s == c){
                break;
            }

            swap(b[s], b[c]);
            c = s;


        }
 
        return x;

    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>b;
        for(int i=0; i<n; i++){
            insert(nums[i], b);
        }

        vector<int>ans;

        for(int i=0; i<n; i++){
            ans.push_back(del(b));
        }


        return ans;
    }
};