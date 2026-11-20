class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u'};
        
        int res = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int>mp;
            int cons = 0;
            for(int j=i; j<n; j++){
                char c = word[j];
                if(st.find(c)!=st.end()){
                    if(mp.find(c) != mp.end()){
                        mp[c]++;
                    }else{
                        mp[c] = 1;
                    }
                }else{
                    cons++;
                }
                if(mp.size() == 5 && cons == k){
                    res++;
                }

            }
        }
        return res;

    }
};